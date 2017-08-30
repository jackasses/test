#/bin/bash

process=$(ps -e | grep "run_grill")
echo $process
alt=${process%% ? *}
#echo $alt
sudo kill $alt
