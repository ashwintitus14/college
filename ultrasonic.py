import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

GPIO_TRIG = 18
GPIO_ECHO = 24

GPIO.setup(GPIO_TRIG, GPIO.OUT)
GPIO.setup(GPIO_ECHO, GPIO.IN)

def distance():
    GPIO.output(GPIO_TRIG, True)

    time.sleep(0.00001) #0.01ms
    GPIO.output(GPIO_TRIG, False)
    
    while GPIO.input(GPIO_ECHO) == 0:
        starttime = time.time()

    while GPIO.input(GPIO_ECHO) == 1:
        stoptime = time.time()

    timeelapsed = stoptime - starttime
    distance = (timeelapsed * 34300) / 2

    return distance


screen_diagonal = float(input("Enter the diagonal length of the projector screen in inches"))
lcd_diagonal = float(input("Enter the diagonal length of the Projector's LCD Panel in inches"))

try:
    while True:
        dist = distance()
        dist_inches = dist*0.393701
        lens_focal_length_inch = (dist * (lcd_diagonal*0.8))/ screen_diagonal
        lens_focal_length_mm = lens_focal_length_inch*25.4
        print("Focal Length of lens = %.1f mm" % lens_focal_length_mm)
        time.sleep(1)

except KeyboardInterrupt:
    print("Measurement stopped by User")
    GPIO.cleanup()
