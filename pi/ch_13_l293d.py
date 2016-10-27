import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

# Define pins
motor_1_speed_pin = 18
motor_2_speed_pin = 23
motor_1_dir_A_pin = 24
motor_1_dir_B_pin = 17
motor_2_dir_A_pin = 27
motor_2_dir_B_pin = 22

# Set pin modes
GPIO.setup(motor_1_speed_pin, GPIO.OUT)
GPIO.setup(motor_2_speed_pin, GPIO.OUT)
GPIO.setup(motor_1_dir_A_pin, GPIO.OUT)
GPIO.setup(motor_1_dir_B_pin, GPIO.OUT)
GPIO.setup(motor_2_dir_A_pin, GPIO.OUT)
GPIO.setup(motor_2_dir_B_pin, GPIO.OUT)

# Start PWM
motor_1_pwm = GPIO.PWM(motor_1_speed_pin, 500)
motor_1_pwm.start(0)
motor_2_pwm = GPIO.PWM(motor_2_speed_pin, 500)
motor_2_pwm.start(0)

# Set one motor to full speed
motor_1_pwm.ChangeDutyCycle(100)
GPIO.output(motor_1_dir_A_pin, False) 
GPIO.output(motor_1_dir_B_pin, True) 

# Second motor to half sped
motor_2_pwm.ChangeDutyCycle(50)
GPIO.output(motor_2_dir_A_pin, True) 
GPIO.output(motor_2_dir_B_pin, False) 

input("Enter '0' to stop ")
print("Cleaning up")
GPIO.cleanup()