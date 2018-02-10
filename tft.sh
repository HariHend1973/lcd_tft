#!/bin/bash
#stty -F /dev/ttyACM0 9600 raw -echo -echoe -echok -echoctl -echoke
screen -dmS arduino /dev/ttyACM1 115200,cs8
signal=""
old_signal=""
while true
do
   signal=$(/root/oled/signal.sh)
   if [ "$signal" != "$old_signal" ]
   then
     echo -e -n "$(/root/oled/signal.sh)\r" > /dev/ttyACM1;
     old_signal=$signal
   fi
   echo -e -n "$(/root/oled/temp.sh)\r" > /dev/ttyACM1;
   echo -e -n "$(/root/oled/txrx.sh)\r" > /dev/ttyACM1;
   echo -e -n "$(/root/oled/wifi.sh)\r" > /dev/ttyACM1;
   echo -e -n "$(/root/oled/cpu.sh)\r" > /dev/ttyACM1;
   echo -e -n "$(/root/oled/disk.sh)\r" > /dev/ttyACM1;
   echo -e -n "$(/root/oled/clock.sh)\r" > /dev/ttyACM1;
   # some delay :)
   for i in {1..1000}; do echo $i > /dev/null; done
   #sleep 3;
done &

