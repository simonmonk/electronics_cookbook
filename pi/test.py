import spidev
import ws2812
spi = spidev.SpiDev()
spi.open(0,0)

#write 4 WS2812's, with the following colors: red, green, blue, yellow
ws2812.write2812(spi, [[10,0,0], [0,10,0], [0,0,10], [10, 10, 0]])
