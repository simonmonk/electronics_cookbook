from demo_opts import device
from oled.render import canvas
from PIL import ImageFont
from demo_opts import args

font = ImageFont.load_default()


with canvas(device) as draw:
    draw.rectangle((0, 0, device.width-1, device.height-1), outline=255, fill=0)
    font = ImageFont.load_default()
    draw.text((5, 20), 'Electronics Cookbook',  font=font, fill=255)
