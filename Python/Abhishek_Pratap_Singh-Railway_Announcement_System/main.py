import os
import pandas as pd
from pydub import AudioSegment
from gtts import gTTS


def textToSpeech(text, filename, language):
    mytext = str(text)
    myobj = gTTS(text=mytext, lang=language, slow=False)
    myobj.save(filename)


# This function returns pydub audio segments
def mergeAudios(audios):
    combined = AudioSegment.empty()
    for audio in audios:
        combined += AudioSegment.from_mp3(audio)
    return combined


def generateSkeleton():
    audio = AudioSegment.from_mp3('railway.mp3')
    # Generate "kripya dhyan dijiye"
    start = 88000       # It is starting time in miliseconds in our main recording from where we want to cut our desired part
    finish = 90200      # It is starting time in miliseconds in our main recording upto where we want to cut our desired part
    audioProcessed = audio[start:finish]        # Slicing of main audio file
    # Exporting it to computer
    audioProcessed.export("1_hindi.mp3", format="mp3")

    # 2 is from-city

    # 3 - Generate se chalkar
    start = 91000
    finish = 92200
    audioProcessed = audio[start:finish]
    audioProcessed.export("3_hindi.mp3", format="mp3")

    # 4 is via-city

    # 5 - Generate ke raaste
    start = 94000
    finish = 95000
    audioProcessed = audio[start:finish]
    audioProcessed.export("5_hindi.mp3", format="mp3")

    # 6 is to-city

    # 7 - Generate ko jaane wali gaadi sakhya
    start = 96000
    finish = 98900
    audioProcessed = audio[start:finish]
    audioProcessed.export("7_hindi.mp3", format="mp3")

    # 8 is train no and name

    # 9 - Generate kuch hi samay mei platform sankhya
    start = 105500
    finish = 108200
    audioProcessed = audio[start:finish]
    audioProcessed.export("9_hindi.mp3", format="mp3")

    # 10 is platform number

    # 11 - Generate par aa rahi hai
    start = 109000
    finish = 112250
    audioProcessed = audio[start:finish]
    audioProcessed.export("11_hindi.mp3", format="mp3")


def generateSkeletontEng():
    audio = AudioSegment.from_mp3('railway.mp3')
    # 1  May i have your attention please train no
    start = 19600
    finish = 23750
    audioProcessed = audio[start:finish]
    audioProcessed.export("1_eng.mp3", format="mp3")

    # 2 {train_no} + " " + {train_name}

    # 3 from

    start = 30300
    finish = 31200
    audioProcessed = audio[start:finish]
    audioProcessed.export("3_eng.mp3", format="mp3")

    # 4 {Departure Station}

    # 5 to
    start = 32000
    finish = 32800
    audioProcessed = audio[start:finish]
    audioProcessed.export("5_eng.mp3", format="mp3")

    # 6 {Arriving Station}

    # 7 via
    start = 34000
    finish = 34850
    audioProcessed = audio[start:finish]
    audioProcessed.export("7_eng.mp3", format="mp3")

    # 8 {Intermediate Station}

    # 9 is arriving shortly on
    start = 36500
    finish = 40500
    audioProcessed = audio[start:finish]
    audioProcessed.export("9_eng.mp3", format="mp3")
    # 10 {platform_no}


def generateAnnouncement(filename):
    df = pd.read_excel(filename)
    print(df)
    for index, item in df.iterrows():
        # 2 - Generate from-city
        textToSpeech(item['from'], '2_hindi.mp3', 'hi')

        # 4 {Departure Station}
        textToSpeech(item['to'], '4_hindi.mp3', 'hi')

        # 6 - Generate to-city
        textToSpeech(item['to'], '6_hindi.mp3', 'hi')

        # 8 - Generate train no and name
        textToSpeech(item['train_no'] + " " +
                     item["train_name"], '8_hindi.mp3', 'hi')

        # 10 - Generate platform number
        textToSpeech(item['platform'], '10_hindi.mp3', 'hi')

        audios = [f"{i}_hindi.mp3" for i in range(1, 12)]

        announcement = mergeAudios(audios)
        announcement.export(
            f"announcement_{item['train_no']}_{index+1}.mp3", format="mp3")


def generateAnnouncementEng(filename):
    df = pd.read_excel(filename)
    print(df)
    for index, item in df.iterrows():
        # 2 {train_no} + " " + {train_name}
        textToSpeech(item['train_no'] + "   " +
                     item["train_name"], '2_eng.mp3', 'en')

        # 4 {Departure Station}
        textToSpeech(item['from'], '4_eng.mp3', 'en')

        # 6 {Arriving Station}
        textToSpeech(item['to'], '6_eng.mp3', 'en')

        # 8 {Intermediate Station}
        textToSpeech(item['via'], '8_eng.mp3', 'en')

        # 10 {platform_no}
        textToSpeech(item['platform'], '10_eng.mp3', 'en')

        audios = [f"{i}_eng.mp3" for i in range(1, 11)]

        announcement = mergeAudios(audios)
        announcement.export(
            f"Engannouncement_{item['train_no']}_{index+1}.mp3", format="mp3")

if __name__ == '__main__':
    print("Generating Skeleton")
    generateSkeleton()
    generateSkeletontEng()
    print("Now generating announcement")
    generateAnnouncement("announce_hindi.xlsx")
    generateAnnouncementEng("announce_hindi.xlsx")
