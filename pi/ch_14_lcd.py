import time
import Adafruit_CharLCD as LCD

# Raspberry Pi pin configuration:
lcd_rs        = 27  # Note this needs to be changed to 21 for Model B rev1 Pi's.
lcd_en        = 22
lcd_d4        = 25
lcd_d5        = 24
lcd_d6        = 23
lcd_d7        = 18
lcd_backlight = 4

lcd_columns = 16
lcd_rows    = 2

lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7,
                           lcd_columns, lcd_rows, lcd_backlight)

lcd.message('Electyronics\nCookbook')
t0 = time.time()

while True:
    lcd.set_cursor(10, 1)
    lcd.message(str(int(time.time()-t0)))
    time.sleep(0.1)
