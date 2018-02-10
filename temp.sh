#!/bin/sh
temp="$(gigi sbc | grep Temperature | cut -f 3 -d' ')"
temp=${temp%???}
#degree="$(echo $'\xDF'C)"
#degree=$(echo $'\xc2\xb0'C)
echo -n "temper $temp"
