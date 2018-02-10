#!/bin/sh
size=$(df -h | grep "/dev/root" | awk '{print $2}')
used1=$(df -h | grep "/dev/root" | awk '{print $3}')
avail=$(df -h | grep "/dev/root" | awk '{print $4}')

availB=$(printf $avail | sed 's/[0-9\.]*//g')
avail=${avail%??}
avail=${avail/.*}

echo -n "disk $avail$availB"
