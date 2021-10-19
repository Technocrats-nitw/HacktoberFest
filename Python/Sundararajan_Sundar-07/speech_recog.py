import speech_recognition as sr
import time
#two mwthods are there: By audio file and microphone 
r = sr.Recognizer()
mic = sr.Microphone()
harvard = sr.AudioFile('harvard.wav') # by audio file input (you can add your own audio file)
#with mic as source:
with harvard as source: # you can change harvard to mic for your speech test
    time.sleep(1)
    print('Say Something!!')
    #time.sleep(1) # uncomment when you go for audio file
    #print('Wait')
    audio = r.listen(source)
    try:
        voice = r.recognize_google(audio)
        print(voice)
        f = open('output.txt','w')

        f.write('This is your Words:\n {}'.format(voice))
        f.close()
    except sr.UnknownValueError:
        print("Sorry! I dont get it! Please repeat")
    except sr.RequestError:
        print('Sorry my speech service is down!')