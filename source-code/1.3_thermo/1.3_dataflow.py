# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 18:27:03 2020

@author: nicol
"""

import serial

try:
    arduino = serial.Serial("COM11", 9600)
    #|dev|ttyACM0 is placeholder, find  the actual name in the Arduino IDE
    # or: arduino = Serial("COM3")
except:
    print("Please check port")
    
rawdata = []
count = 0
"""
while True: 
	print(str(arduino.readline())
"""
while count < 180:
    rawdata.append(str(arduino.readline())) 
    #alternatively: arduino.readline().decode(’utf-8’)
    count += 1
    print(count)


def clean(L):
    """ cleans linsto into printable list
    """
    res=[]
    for i in range(len(L)):
        temp=L[i][2:]
        res.append(temp[:-5])
    return res
    
cleandata=clean(rawdata)

def write(L):
    """ writes data into .txt file
    """
    file=open("data2.txt",mode='w')
    for i in range(len(L)):
        file.write(L[i]+'\n')
    file.close()

write(cleandata)