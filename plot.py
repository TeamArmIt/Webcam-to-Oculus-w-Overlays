import matplotlib.pyplot as plt
import numpy as np
import cv2
plt.ion() ## Note this correction
fig=plt.figure()

i=0
#x=list()
#y=list()
f=open('headtrackingdata.txt', 'r')
for line in f:
	x=0
	y=0
	z=0
	if i%4==0:
		x=float(line)
		plt.scatter(i,x, color='red')
	elif (i-1)%4==0:
		y=float(line)
		plt.scatter(i,y, color='green')
	elif (i-2)%4==0:
		z=float(line)
		plt.scatter(i,z, color='blue')
	#x.append(i)
	#y.append(temp_y)
	
	i+=1
	plt.show() #plt.pause(0.0001) #Note this correction
	plt.pause(.00001)
	if cv2.waitKey(20) == 27:
		break