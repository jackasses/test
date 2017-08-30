#!/bin/bash

V='run_'

read -p "Versionsnummer: " version

V+=$version

cd lib/
sudo make clean && make VER=$V
