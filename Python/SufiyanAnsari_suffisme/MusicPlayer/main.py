import pygame
import tkinter as tk
import os

musicPlayer = tk.Tk()

musicPlayer.title('Mini Music Player')

musicPlayer.geometry('600x400')

'''
ALL THE SONGS IN SONGS FOLDER WILL BE VISIBLE IN PLAYLIST

'''
os.chdir('./songs')

frame_top = tk.Frame(musicPlayer)
frame_bottom = tk.Frame(musicPlayer)
songList = os.listdir()

playList = tk.Listbox(frame_bottom,font = 'Cambria 14 bold',bg='cyan',selectmode = tk.SINGLE)

for item in songList:
	pos = 0
	playList.insert(pos,item)
	pos += 1

pygame.init()
pygame.mixer.init()

def play():
	pygame.mixer.music.load(playList.get(tk.ACTIVE))
	var.set(playList.get(tk.ACTIVE))
	pygame.mixer.music.play()

def exitMP():
	pygame.mixer.music.stop()

def pause():
	pygame.mixer.music.pause()

def resume():
	pygame.mixer.music.unpause()

btn_play = tk.Button(frame_top, height = 2, width = 7, text = '▶', font = 'Cambria 14 bold',command = play , bg='lime green' , fg='black')
btn_play.grid(row=0,column=0)
btn_exit = tk.Button(frame_top, height = 2, width = 7, text = '■', font = 'Cambria 14 bold',command = exitMP , bg='red' , fg='black')
btn_exit.grid(row=0,column=1)
btn_pause = tk.Button(frame_top, height = 2, width = 7, text = '⏯️', font = 'Cambria 14 bold',command = pause , bg='orange' , fg='black')
btn_pause.grid(row=0,column=2)
btn_resume = tk.Button(frame_top, height = 2, width = 7, text = '◀️', font = 'Cambria 14 bold',command = resume , bg='orange' , fg='black')
btn_resume.grid(row=0,column=3)

playList.pack(fill='both', expand='yes')

var = tk.StringVar()
songTitle = tk.Label(musicPlayer, font = 'Cambria 12 bold', textvariable = var)
songTitle.pack()
frame_top.pack()
frame_bottom.pack(fill='x')
musicPlayer.mainloop()