import serial
import time

class voiceCoils:
    def __init__(self):
        self.ser = serial.Serial()
        
    def connect(self, port):
        self.ser.port = port
        self.ser.baudrate = 9600
        self.ser.open()
        
        # wait serial init
        time.sleep(2)

    def close(self):
        #self.homing()
        self.off()
        self.ser.close()
    
    #go to a certain relative position in mm and degrees
    def goto(self,val1,val2):
        num_par = str(3)
        command = str(1)
        val1_str = str(val1)
        val2_str = str(val2)
        
        self.ser.write(num_par.encode())
        self.ser.write("\n".encode())
        self.ser.write(command.encode())
        self.ser.write("\n".encode())
        self.ser.write(val1_str.encode())
        self.ser.write("\n".encode())
        self.ser.write(val2_str.encode())
        self.ser.write("\n".encode())
   
    #%%
    #com=1 turn on the motor, com=0 turn off the motor
    def off(self):  
        num_par = str(3)
        command = str(1)
        val1_str = str(0)
        val2_str = str(0)
        
        self.ser.write(num_par.encode())
        self.ser.write("\n".encode())
        self.ser.write(command.encode())
        self.ser.write("\n".encode())
        self.ser.write(val1_str.encode())
        self.ser.write("\n".encode())
        self.ser.write(val2_str.encode())
        self.ser.write("\n".encode())

