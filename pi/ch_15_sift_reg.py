import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

strobe_pin = 18
data_pin = 23
clock_pin = 24

GPIO.setup(strobe_pin, GPIO.OUT)
GPIO.setup(data_pin, GPIO.OUT)
GPIO.setup(clock_pin, GPIO.OUT)

def shift_out(bits): # MSB first. 8 bits
    for i in range(0, 8):
        b = bits & 0b10000000
        bits = bits << 1
        GPIO.output(data_pin, (b == 0b10000000))
        time.sleep(0.000001)
        GPIO.output(clock_pin, True)
        time.sleep(0.000001)
        GPIO.output(clock_pin, False)
        time.sleep(0.000001)
        
try:         
    while True:
        bits = input("Enter Byte ")
        print(bin(bits))
        shift_out(bits)
        GPIO.output(strobe_pin, True)
        time.sleep(0.000001)
        GPIO.output(strobe_pin, False)
        
finally:  
    print("Cleaning up")
    GPIO.cleanup()