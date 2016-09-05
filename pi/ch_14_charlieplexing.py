import RPi.GPIO as GPIO
import thread, time

GPIO.setmode(GPIO.BCM)
pins = [18, 23, 24]

pin_led_states = [
  [1, 0, -1], # LED1
  [0, 1, -1], # LED2
  [-1, 1, 0], # LED3
  [-1, 0, 1], # LED4
  [1, -1, 0], # LED5
  [0, -1, 1]  # LED6
]

led_states = [0, 0, 0, 0, 0, 0]

def set_pins(led):
  for pin in range(0, 3):
      if pin_led_states[led][pin] == -1:
          GPIO.setup(pins[pin], GPIO.IN)
      else:
          GPIO.setup(pins[pin], GPIO.OUT)
          GPIO.output(pins[pin], pin_led_states[led][pin])

def clear_pins():
  for pin in range(0, 3):
      GPIO.setup(pins[pin], GPIO.IN)

def refresh():
  while(True):
   for led in range(0, 6):
     clear_pins()
     if led_states[led]:
       set_pins(led)
     else:
       clear_pins()
     time.sleep(0.001)

thread.start_new_thread(refresh, ())
		
while True:
    x = int(raw_input("Pin (0 to 5) :"))
    led_states[x] = not led_states[x]
