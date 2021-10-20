from turtle import *
from time import sleep
coordinates = [
	(-400,250),
	(-200,-150),
	(200,200),
	(-500,40),
	(-450,-120)
]
speed('fastest')
color('cyan')
bgcolor('black')
corona_virus = 0
main = 200
while corona_virus < len(coordinates):
	sleep(0.3)
	a = main
	penup()
	goto(coordinates[corona_virus])
	pendown()
	while a > -100:
		if a > 0:
			forward(a)
			left(a*(200/main))
		else:
			penup()
			if(a == -100):
				break
		a = a - main/200
	main -= 20
	corona_virus += 1
	if main <= 0:
		break
main = 300
a = main
penup()
goto(-200,0)
pendown()
while a > -100:
	if a > 0:
		forward(a)
		left(a*(200/main))
	else:
		penup()
		if(a == -100):
			break
	a = a - main/200
sleep(2)
