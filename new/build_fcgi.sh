#!/bin/bash

V='fcgi_'

read -p "FCGI Versionsnummer: " version

V+=$version

#cd lib/
#sudo make clean && make VER=$V

g++ -lfcgi -lfcgi++ src/main_fcgi.cpp -o $V

mv $V bin/


