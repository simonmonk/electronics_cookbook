import time, Adafruit_DHT

sensor_pin = 4
sensor_type = Adafruit_DHT.DHT11

while True:
    humidity, temp = Adafruit_DHT.read_retry(sensor_type, sensor_pin)
    print(str(temp) + " C " + str(humidity) + " %")
    time.sleep(1)