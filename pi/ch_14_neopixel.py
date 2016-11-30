import spidev
import ws2812
from random import randint
import time

spi = spidev.SpiDev()
spi.open(0,0)

N = 10
                          # g r b
pixels = []
for x in range(0, 10):
    pixels.append([0, 0, 0])

while True:
  for i in range(0, N):
    pixels[i] = [randint(0, 64), randint(0, 64), randint(0, 64)]
    ws2812.write2812(spi, pixels)
  time.sleep(0.1)

