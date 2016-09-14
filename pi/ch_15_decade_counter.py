import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

reset_pin = 18
clock_pin = 23

GPIO.setup(reset_pin, GPIO.OUT)
GPIO.setup(clock_pin, GPIO.OUT)

def set_ditit(digit): 
    GPIO.output(reset_pin, True)
    time.sleep(0.000001)
    GPIO.output(reset_pin, False)
    time.sleep(0.000001)
    for i in range(0, digit):
        GPIO.output(clock_pin, True)
        time.sleep(0.000001)
        GPIO.output(clock_pin, False)
        time.sleep(0.000001)
        
try:         
    while True:
        digit = input("Enter digit 0..9 ")
        set_ditit(digit)
        
finally:  
    print("Cleaning up")
    GPIO.cleanup()