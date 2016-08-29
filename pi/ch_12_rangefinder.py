import RPi.GPIO as GPIO
import time

trigger_pin = 18
echo_pin = 23 # USE LEVEL CONVERTER 5V->3.3V

GPIO.setmode(GPIO.BCM)
GPIO.setup(trigger_pin, GPIO.OUT)
GPIO.setup(echo_pin, GPIO.IN)

def time_to_echo(timeout):
    t0 = time.time()
    while GPIO.input(echo_pin) == False and time.time() < (t0 + timeout):
        pass
    t0 = time.time()
    while GPIO.input(echo_pin) == True and time.time() < (t0 + timeout):
        pass
    return time.time() - t0

def get_distance():
    GPIO.output(trigger_pin, True)
    time.sleep(0.00001)     # 10us
    GPIO.output(trigger_pin, False)
    time.sleep(0.0002)      # 200us
    pulse_len = time_to_echo(1)
    distance_cm = pulse_len / 0.000058
    distance_in = distance_cm / 2.5
    return (distance_cm, distance_in)
    

while True:
    print("cm=%f\tinches=%f" % get_distance())
    time.sleep(1)