import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

led_pin = 18

GPIO.setup(led_pin, GPIO.OUT)


try:         
    while True:
        GPIO.output(led_pin, True)  # LED on
        time.sleep(1)               # delay 1 second
        GPIO.output(led_pin, False) # LED off
        time.sleep(1)               # delay 1 second
finally:  
    print("Cleaning up")
    GPIO.cleanup()