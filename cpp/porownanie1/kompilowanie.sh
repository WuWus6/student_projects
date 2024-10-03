#!/bin/sh
rm main_test
clear
echo "----Kompilacja benchmarka testujacego----"

g++ -std=c++11 tester.cpp -o main_test -lgtest_main -lgtest -lbenchmark -lpthread

echo "---Kompilacja benchmarka ukonczona----"
echo "---Uruchamianie beanchmarka---"
chmod +x main_test
./main_test
echo "---Zakonczono benchmark---"
