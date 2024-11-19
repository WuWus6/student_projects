#!/bin/sh
rm tester
clear
echo "----Kompilacja programu testujacego----"

# Kompilacja kodu źródłowego dla programu głównego
g++ main.cpp -o main

# Kompilacja kodu testów
g++ tester.cpp -o tester -lgtest -lgtest_main -pthread

echo "---Kompilacja testow ukonczona----"
echo "---Uruchamianie programu testujacego---"
chmod +x tester
./tester
echo "---Zakonczono program testujacy---"
