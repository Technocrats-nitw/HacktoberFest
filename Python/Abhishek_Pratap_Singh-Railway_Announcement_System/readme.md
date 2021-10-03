## Railway Announcement System

This is a basic railway announcement system.
It will take an excel sheet containing the trains information 
andit will play announcement as well as save the the audio file(in hindi as well as english) corresponding to that.

In this folder ```railway.mp3``` is audio file which contains s
ome recorded voice of Indian Railway,which i will slice to create skeleton of announcement
(means like "May i have your attention please train no _____ , (train name) from ____ to _____ via _____ 
is arriving shortly on platform no _____)and the blank spaces will be filled by according 
to data given in Excel Sheet.

#### Brief description about main.py

i) It will slice the voice clip and split.

ii) Then it will convert given train information in text format to audio format.

iii)Finally it will stich all the clips in proper order and save a seperate file 

for announcement of each train having name related with train no.



#### Brief description about main2.py

i) Here I am directly using sliced clip because it will be always same.

ii) Then it will convert given train information in text format to audio format.

iii) And it will stich all the clips in proper order and save as well as announce

 timing of all trains provided in Excel Sheet together because playing an audio 
 
file one by one for each train will be tidious when there is large no. of trains.<br>

Credit-[CodeWithHarry](https://www.youtube.com/channel/UCeVMnSShP_Iviwkknt83cww).