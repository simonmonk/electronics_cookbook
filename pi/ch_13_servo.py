import RPi.GPIO as GPIO
import time

servo_pin = 18

# Tweak these values to get full range of servo movement
deg_0_pulse = 0.5   # ms 
deg_180_pulse = 2.5 # ms
f = 50.0   #50Hz = 20ms between pulses

# Do some calculations on the pulse width parameters
period = 1000 / f # 20ms 
k = 100 / period         # duty 0..100 over 20ms 
deg_0_duty = deg_0_pulse * k  
pulse_range = deg_180_pulse - deg_0_pulse
duty_range = pulse_range * k  

GPIO.setmode(GPIO.BCM)
GPIO.setup(servo_pin, GPIO.OUT) 
pwm = GPIO.PWM(servo_pin, f)      
pwm.start(0)

def set_angle(angle):  
    duty = deg_0_duty + (angle / 180.0) * duty_range
    pwm.ChangeDutyCycle(duty)

try:
    while True:   
        angle = input("Angle (0 to 180): ")
        set_angle(angle)
finally:
    print("Cleaning up")
    GPIO.cleanup()
