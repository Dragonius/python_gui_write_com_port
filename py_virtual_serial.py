import sys
import time

from serial import Serial
from tkinter import *

serialPort="COM5"
baudrate = 115200

try:
    s = Serial(serialPort,baudrate)
except Exception as e:
    print("\n", e)
    print(f">No device found on {serialPort} probably")

    sys.exit(69)

def sup(val):


    #add semicolon after value
    msg = val+";"

    #encode message
    encodedMessage = msg.encode()

    # Send the encoded message
    s.write(encodedMessage)
    
    #Wait 1 sec
#    time.sleep(1)


#make TK
root = Tk()

scale = Scale(root,
            variable=DoubleVar(),
            width=40,
            length=480,
            orient=HORIZONTAL,
            from_=0,
            to=255,
            command=sup)

scale.pack()

root.mainloop()

print("Closing down")
s.close()









