import os
import pandas as pd
from pydub import AudioSegment
from gtts import gTTS
from playsound import playsound


def textToSpeech(text, filename, language):
    mytext = str(text)
    myobj = gTTS(text=mytext, lang= language, slow=False)
    myobj.save(filename)

# This function returns pydub audio segments
def mergeAudios(hiAudios, enAudios):
    combined= AudioSegment.empty()
    for audio in hiAudios:
        combined += AudioSegment.from_mp3(audio)
    for audio in enAudios:
        combined += AudioSegment.from_mp3(audio)
    return combined


def generateAnnouncement(filename):
    ANNOUNCEMENTS = AudioSegment.empty()

    df = pd.read_excel(filename)
    for index, item in df.iterrows():
        # 2 - Generate from-city
        textToSpeech(item['from'], '2_hindi.mp3', 'hi')

        # 4 {Departure Station}
        textToSpeech(item['via'], '4_hindi.mp3', 'hi')

        # 6 - Generate to-city
        textToSpeech(item['to'], '6_hindi.mp3', 'hi')

        # 8 - Generate train no and name
        textToSpeech(item['train_no'] + " " +
                     item["train_name"], '8_hindi.mp3', 'hi')

        # 10 - Generate platform number
        textToSpeech(item['platform'], '10_hindi.mp3', 'hi')

        hiAudios = [f"{i}_hindi.mp3" for i in range(1,12)]

        # Generating names according to Hindi format

        # 2 - Generating {train_no} + " " + {train_name}
        textToSpeech(item['train_no'] + "   " + item["train_name"], '2_eng.mp3', 'en')

        # 4 - Generating {Departure Station}
        textToSpeech(item['from'], '4_eng.mp3', 'en')

        # 6 - Generating {Arriving Station}
        textToSpeech(item['to'], '6_eng.mp3', 'en')

        # 8 - Generating {Intermediate Station}
        textToSpeech(item['via'], '8_eng.mp3', 'en')

        # 10 - Genrating {platform_no}
        textToSpeech(item['platform'], '10_eng.mp3', 'en')
        enAudios = [f"{i}_eng.mp3" for i in range(1,11)]
        announcement = mergeAudios(hiAudios, enAudios)
        ANNOUNCEMENTS += announcement
    
    ANNOUNCEMENTS.export(f"final.mp3", format="mp3")

        

if __name__ == '__main__':
    print("Generating announcement")
    generateAnnouncement("announce_hindi.xlsx")
    playsound("final.mp3")
    