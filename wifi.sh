#!/bin/sh
wifi="$(cat /proc/net/wireless | awk 'NR==3 {print $4}' | sed 's/\.//')"
echo -n "wifi ${wifi}"

#sstmp=${ss:1}
#signal=${sstmp%.*}

