import matplotlib.pyplot as plt
import matplotlib
import numpy as np
import cv2
import ast
matplotlib.use('GTKAgg') 
plt.ion() ## Note this correction
fig=plt.figure()
f, axarr = plt.subplots(3, sharex=True)
axarr[0].set_title('Yaw')
axarr[1].set_title('Pitch')
axarr[2].set_title('Roll')
i=0
#x=range(10)
#y=list()
while True:
	temp=0
	coord=raw_input()
	ncoord=coord.split()
	#print ncoord
	'''
	if 'x:' in coord:
		temp=float(coord[2:])
		axarr[0].scatter(i,temp, color='red')
	elif 'y:' in coord:
		temp=float(coord[2:])
		axarr[1].scatter(i,temp, color='green')
	elif 'z:' in coord:
		temp=float(coord[2:])
		axarr[2].scatter(i,temp, color='blue')
	'''
	#x.append(i)
	#y.append(temp)
	axarr[0].scatter(i,float(ncoord[0]), color='red')
	axarr[1].scatter(i,float(ncoord[1]), color='green')
	axarr[2].scatter(i,float(ncoord[2]), color='blue')
	i+=1
	plt.show() #plt.pause(0.0001) #Note this correction
	plt.pause(.0001)
	