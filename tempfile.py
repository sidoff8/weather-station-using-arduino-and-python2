import serial
import numpy
import matplotlib.pyplot as plt
from drawnow import *

l=[]
t = []
h = []
arduinoData = serial.Serial('com3',115200)
plt.ion()
count=0

def makeFig():
    plt.ylim(0,100)
    plt.title('Temperature and Humidity')
    plt.grid(True)
    plt.ylabel('temp in C')
    plt.plot(t, 'ro-', label='Drgrees Celsius')
    plt.legend(loc='upper left')
    plt2=plt.twinx()
    plt.ylim(0,100)
    plt2.plot(h,'b^-',label='Humidity in %')
    plt2.legend(loc='upper right')
    
    

while True:
    while (arduinoData.inWaiting()==0):
        pass
    arduinoString = arduinoData.readline()
    dataArray = arduinoString.split(',')
    lux = float (dataArray[0] )
    humd = float ( dataArray[1])
    temp = float ( dataArray[2])
    t.append(temp)
    h.append(humd)
    l.append(lux)
    drawnow(makeFig)
    plt.pause(.000001)
    count=count+1
    if(count>60):
        t.pop(0)
        h.pop(0)
        l.pop(0)
        
    
