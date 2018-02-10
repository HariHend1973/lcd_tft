#!/bin/sh
ss="$(grep strength /tmp/3ginfotmp | awk '{print $3}' 2> /dev/null)"
#echo -n "Modem Signal: $ss"

signal=${ss%?};

if [ -z "$signal" ]
   then
      echo -n "sinyal0"
fi
if [ $signal -eq 0 ]
   then
      echo -n "sinyal0"
fi
if [ $signal -gt 0 ] && [ $signal -lt 21 ]
   then
      echo -n "sinyal20"
fi
if [ $signal -gt 20 ] && [ $signal -lt 41 ]
   then
      echo -n "sinyal40"
fi
if [ $signal -gt 40 ] && [ $signal -lt 61 ]
   then
      echo -n "sinyal60"
fi
if [ $signal -gt 60 ] && [ $signal -lt 81 ]
   then
      echo -n "sinyal80"
fi
if [ $signal -gt 80 ] && [ $signal -lt 101 ]
   then
      echo -n "sinyal100"
fi
