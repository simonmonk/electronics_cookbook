#!/usr/bin/env python

from oled.device import ssd1306   # 1
from oled.render import canvas
from PIL import ImageFont    # 2
import time

device = ssd1306(port=1, address=0x3C)  # 3
large_font = ImageFont.truetype('FreeMono.ttf', 24)  # 4

x = 0
while True:
    with canvas(device) as draw:      # 5
        draw.pieslice((x, 30, x+30, 60), 45, -45, fill=255)   # 6
        x += 10    # 7
        if x > 128:
            x = 0
        now = time.localtime()  # 8
        draw.text((0, 0), time.strftime('%H:%M:%S', now), font=large_font, fill=255)
    time.sleep(0.1)