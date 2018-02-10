# lcd_tft
Arduino 3.5" tft lcd for raspberry pi stats via serial usb (openwrt/lede)

Steps
- login to openwrt, create folder name oled
- put all scripts in that directory.
- edit /etc/rc.local add line sh /root/oled/tft.sh > /dev/null 2>&1 &
- create new project in arduino IDE, open .ino file, compile and upload
- connect arduino usb to raspberry pi usb, usually that will create device /dev/ttyACM* automatically. Adjust to tft.sh.

