import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

input_pin = 23

GPIO.setup(input_pin, GPIO.IN)

try:         
    while True:
        reading = GPIO.input(input_pin) 
        print(reading)
        time.sleep(0.5)         
finally:  
    print("Cleaning up")
    GPIO.cleanup()