import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

input_pin = 23

GPIO.setup(input_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

try:         
    while True:
        if GPIO.input(input_pin) == False: 
            print("Button Pressed!")
            while GPIO.input(input_pin) == False: 
                pass
                time.sleep(0.01)         
finally:  
    print("Cleaning up")
    GPIO.cleanup()