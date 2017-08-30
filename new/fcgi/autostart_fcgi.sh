#/bin/bash

sleep 5
cd /home/pi/firmware/azura-firmware/fcgi/
sudo spawn-fcgi -n main_fcgi -p 8000
