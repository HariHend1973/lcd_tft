#!/bin/sh
cpu=$(top -bn 1 | head -n 5 | grep "CPU:" | awk '{print $2}')
echo "proc $cpu"
