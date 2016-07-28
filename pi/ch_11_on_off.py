import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

led_pin = 18

GPIO.setup(led_pin, GPIO.OUT)


try:         
    while True:
        answer = input("1 for on 0 for off")
        if answer == 1:
            GPIO.output(led_pin, True)  # LED on
        elif answer == 0:
            GPIO.output(led_pin, False) # LED off
finally:  
    print("Cleaning up")
    GPIO.cleanup()