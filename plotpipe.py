import matplotlib.pyplot as plt
import numpy as np
import cv2
plt.ion() ## Note this correction
fig=plt.figure()

i=0
#x=list()
#y=list()
f=open('pitch.txt', 'r')
while True:
	coord=raw_input()
	x=0
	y=0
	z=0
	if 'x:' in coord:
		x=float(coord[2:])
		plt.scatter(i,x, color='red')
	elif 'y:' in coord:
		y=float(coord[2:]))
		plt.scatter(i,y, color='green')
	elif 'z:' in coord:
		z=float(coord[2:])
		plt.scatter(i,z, color='blue')
	#x.append(i)
	#y.append(temp_y)
	
	i+=1
	plt.show() #plt.pause(0.0001) #Note this correction
	plt.pause(.0001)
	if cv2.waitKey(20) == 27:
		break