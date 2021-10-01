import pyttsx3
from datetime import datetime
import webbrowser
import os
import speech_recognition as sr
import wolframalpha
engine = pyttsx3.init('sapi5')
voice = engine.getProperty('voices')
import pyjokes
import pyautogui
# using get_joke() to generate a single joke
#language is english
#category is neutral
import time


#pyautogui.press('launchmediaselect')
def speak(audio):
    engine.say(audio)
    engine.runAndWait()
def wish():
    a=""
    hour = int(datetime.now().hour)
    if hour >= 0 and hour < 12 :
        a="good morning Sir"
    elif hour >12 and hour <18 :
        a="good afternoon Sir"
    else:
        a="good evening sir"
    speak(a)
def takeCommand():

	r = sr.Recognizer()

	with sr.Microphone() as source:
		print("Listening...")

		audio = r.listen(source)

	try:
		print("Recognizing...")
		query = r.recognize_google(audio, language ='en-in')
		print(f"User said: {query}\n")

	except Exception as e:
		print(e)
		print("Unable to Recognize your voice.")
		return "None"


	return query.lower()


wish()
assis='jarvis'
def playmusic():
    m = "D:\\mobile\\audio"
    songs=os.listdir(m)
    os.startfile(os.path.join(m,songs[0]))

def mood(st):
    if 'sad' in st:
        speak("Why so sad sir , should I,Play some music")
        music=takeCommand()
        if 'yes' or 'play' in music :
            playmusic()
    elif 'happy' in st:
        speak("you are happy , then I am happy")
while True:
    query=takeCommand().lower()
    if 'ok '+assis in query:
        speak('Yes,sir how may I help you ')
        #speak("Ha bhai ,kya hua")
        task=takeCommand()
        if 'change your name' in task:
            speak('Ok sir,what you want call me ')
            name=takeCommand()
            while 'none' in name:
                speak('Ok sir,what you want call me ')
                name=takeCommand()
            assis=name
            speak("Name changed to "+name)
        elif 'stop' in task:
            if 'music' in task:
                pyautogui.press('playpause')
        elif 'music' in task:
            playmusic()
        elif 'question' in task:
            # Taking input from user
            speak("Yes sir, what want to ask ")
            question = takeCommand().lower()
            app_id = '#'
            client = wolframalpha.Client(app_id)
            res = client.query(question)
            answer = next(res.results).text
            speak(answer)
        elif 'google' in task:
            speak("yes sir ,what should I search ")
            t=takeCommand()
            webbrowser.open('google.com/search?q='+t)
        elif 'how are you' in task:
            speak(" I am good sir ,just enjoying with buddies")
            speak("how about you ,sir ")
            st=takeCommand()
            mood(st)

        elif 'joke'  in task:
            My_joke = pyjokes.get_joke(language="en", category="neutral")
            speak(My_joke)
        elif  'volume' in task:
            print('volume')
            if 'increase' in task or 'raise' in task:
                pyautogui.press('volumeup',presses=5)
            elif 'lower' in task or 'down' in task or  'slow' in task:
                pyautogui.press('volumedown',presses=10)
                #pyautogui.keyDown('volumedown')
        elif 'mute' in task:
            pyautogui.press('volumemute')
        elif 'next track' in task:
            pyautogui.press('prevtrack')

    elif 'page up' in query:
            print('pageup')
            pyautogui.press('pgup')
    elif 'page down' in query:
            pyautogui.press('pgdn')
    elif assis+' quit' in query:
        speak("Ok, sir taking a break ")
        break
    elif 'new task' in query:
        pyautogui.press('launchmediaselect')
    elif "stop listening" in query:
        speak("How long sir ")
        s=takeCommand()
        if 'none' in s:
            time.sleep(10)

        else:
            try:
                a=int(s)
                time.sleep(a)
                speak("Awake sir")
            except:
                speak("Sorry sir ,didn't understand")