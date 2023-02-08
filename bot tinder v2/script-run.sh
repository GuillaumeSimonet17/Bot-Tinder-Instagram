#! /bin/bash

make


pip install chromedriver
pip install selenium
pip install pandas
pip install numpy
npm install jquery

'/Applications/Google Chrome.app/Contents/MacOS/Google Chrome' --remote-debugging-port=9222 --user-data-dir='/Users/guillaumesimonet/Desktop/bot tinder v2'

