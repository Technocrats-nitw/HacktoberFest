'''
	GUI Program to Convert Hexadecimal code to RGB format
	Accepted inputs
	6 length
		• # _ _ _ _ _ _
		• _ _ _ _ _ _
	3 length
		• # _ _ _
		• _ _ _
	For example: #ff22ee = ff22ee = #f2e = f2e
'''

import tkinter as tk
import tkinter.font as font

# color dictionary and main executable function
def rgb():
	h = {
	'0':0,
	'1':1,
	'2':2,
	'3':3,
	'4':4,
	'5':5,
	'6':6,
	'7':7,
	'8':8,
	'9':9,
	'a':10,
	'b':11,
	'c':12,
	'd':13,
	'e':14,
	'f':15
	}	
	hex_data = enter.get()
	text = ''
	if(hex_data[0]=='#'):
		hex_data = hex_data[1:]
	k = hex_data
	if(len(hex_data)==6):     #handling the input
		try:
			text = 'rgb('+str(16*h[k[0]]+h[k[1]])+','+str(16*h[k[2]]+h[k[3]])+','+str(16*h[k[4]]+h[k[5]])+')'
		except KeyError:
			text = 'Invalid'
	elif len(hex_data)==3:
		try:
			text = 'rgb('+str(16*h[k[0]]+h[k[0]])+','+str(16*h[k[1]]+h[k[1]])+','+str(16*h[k[2]]+h[k[2]])+')'
		except KeyError:
			text='Invalid'
	else:
		text = 'Invalid'
	lbl_ans = tk.Label(text=text,font=font.Font(size=15,family='Helvetica'))
	lbl_ans.grid(row=3,column=0,sticky='we')

# intitialising tkinter
window = tk.Tk()
window.title('Hex2RGB')

window.rowconfigure([0,1,2,3],minsize=20)
window.columnconfigure(0,minsize=60)

# passing all widgets
lbl = tk.Label(window,text='Hex2RGB',font=font.Font(size=30,family='Helvetica'),bg='#333',fg='#f1f1f1')
lbl.grid(row=0,sticky='nsew')
main_frame = tk.Frame(window)
enter = tk.Entry(main_frame)
enter.grid(row=0,column=0,sticky='ns',ipadx=5,ipady=5,padx=5,pady=5)
btn = tk.Button(main_frame,text='Submit',command=rgb)
btn.grid(row=0,sticky='ns',column=1,padx=5,pady=5)
main_frame.grid(row=1,column=0)

window.mainloop()
