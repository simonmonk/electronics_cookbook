import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

in_1_pin = 18   
in_2_pin = 23
in_3_pin = 24
in_4_pin = 25
en_pin = 22

GPIO.setup(in_1_pin, GPIO.OUT)
GPIO.setup(in_2_pin, GPIO.OUT)
GPIO.setup(in_3_pin, GPIO.OUT)
GPIO.setup(in_4_pin, GPIO.OUT)
GPIO.setup(en_pin, GPIO.OUT)
GPIO.output(en_pin, True)

period = 0.02

def step_forward(steps, period):  
  for i in range(0, steps):
    set_coils(1, 0, 0, 1)
    time.sleep(period)
    set_coils(1, 0, 1, 0)
    time.sleep(period)
    set_coils(0, 1, 1, 0)
    time.sleep(period)
    set_coils(0, 1, 0, 1)
    time.sleep(period)

def step_reverse(steps, period):   
  for i in range(0, steps):
    set_coils(0, 1, 0, 1)
    time.sleep(period)
    set_coils(0, 1, 1, 0)
    time.sleep(period)
    set_coils(1, 0, 1, 0)
    time.sleep(period)
    set_coils(1, 0, 0, 1)
    time.sleep(period)

  
def set_coils(in1, in2, in3, in4): 
  GPIO.output(in_1_pin, in1)
  GPIO.output(in_2_pin, in2)
  GPIO.output(in_3_pin, in3)
  GPIO.output(in_4_pin, in4)
  

try:
    print('Command letter followed by number');
    print('p20 - set the inter-step period to 20ms (control speed)');
    print('f100 - forward 100 steps');
    print('r100 - reverse 100 steps');
    
    while True:     
        command = input('Enter command: ')
        parameter_str = command[1:] # from char 1 to end
        parameter = int(parameter_str)   
        if command[0] == 'p':   
            period = parameter / 1000.0
        elif command[0] == 'f':
            step_forward(parameter, period)
        elif command[0] == 'r':
            step_reverse(parameter, period)

finally:
    print('Cleaning up')
    GPIO.cleanup()