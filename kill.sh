#!/bin/sh
kill -9 $(ps www | grep tft.sh | grep -v grep | awk '{print $1}')
killall -9 screen
