## FizzBuzz
## 1. Wstęp
Program opisuje implementację i testowanie funkcji fizzBuzz napisanej w języku C++. Funkcja zwraca odpowiednie wartości w zależności od tego, czy dana liczba jest podzielna przez 3, 5, czy oba te dzielniki. W dokumencie znajduje się także struktura skryptów kompilacyjnych oraz testów jednostkowych z użyciem biblioteki Google Test.
## Kod
## 1. functions.cpp
~~~~ cpp
#include <string>
using namespace std;

string fizzBuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        return "FizzBuzz";
    } else if (n % 3 == 0) {
        return "Fizz";
    } else if (n % 5 == 0) {
        return "Buzz";
    } else {
        return to_string(n);
    }
}
~~~~
## 2. kompiluj.sh
Uruchamianie głównego programu
~~~~ cpp
#!/bin/sh
rm main
clear
echo "----Kompilacja programu----"
g++ -o main main.cpp
echo "---Kompilacja ukonczona----"
echo "---Uruchamianie programu---"
chmod +x main
./main
echo "---Zakonczono program---"
~~~~
## 3. kompiluj_test.sh
Kompilowanie i uruchamianie testów jednostkowych
~~~~ cpp
#!/bin/sh
rm main_test
clear
echo "----Kompilacja programu testujacego----"

g++ main.cpp -o main
g++ main_test.cpp -o main_test -lgtest -lgtest_main -pthread

echo "---Kompilacja testow ukonczona----"
echo "---Uruchamianie programu testujacego---"
chmod +x main_test
./main_test
echo "---Zakonczono program testujacy---"
~~~~
## 4. main.cpp
Program główny, który pobiera liczbę od użytkownika, wywołuje funkcję fizzBuzz i wyświetla wynik.
~~~~ cpp
#include <iostream>
#include <string>
#include "functions.cpp"

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbę: ";
    cin >> n;

    string result = fizzBuzz(n);
    cout << result << endl;

    return 0;
}
~~~~
## 5. main_test.cpp
Program testujący funkcję fizzBuzz z użyciem Google Test, sprawdzający różne przypadki liczb.
~~~~ cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(FizzBuzzTest, MultiplesOf3) {
    ASSERT_EQ(fizzBuzz(3), "Fizz");
    ASSERT_EQ(fizzBuzz(9), "Fizz");
}

TEST(FizzBuzzTest, MultiplesOf5) {
    ASSERT_EQ(fizzBuzz(5), "Buzz");
    ASSERT_EQ(fizzBuzz(10), "Buzz");
}

TEST(FizzBuzzTest, MultiplesOf3And5) {
    ASSERT_EQ(fizzBuzz(15), "FizzBuzz");
    ASSERT_EQ(fizzBuzz(30), "FizzBuzz");
}

TEST(FizzBuzzTest, NeitherMultipleOf3Nor5) {
    ASSERT_EQ(fizzBuzz(1), "1");
    ASSERT_EQ(fizzBuzz(7), "7");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
~~~~
## Funkcje
<li>string fizzBuzz(int n): Funkcja przyjmuje liczbę całkowitą n. Zwraca "Fizz" dla liczb podzielnych przez 3, "Buzz" dla liczb podzielnych przez 5, "FizzBuzz" dla liczb podzielnych przez 3 i 5, oraz wartość liczby jako tekst dla pozostałych przypadków.

Funkcja fizzBuzz działa zgodnie z oczekiwaniami i poprawnie zwraca określone wartości dla liczb podzielnych przez 3, 5 oraz obie te liczby. Testy jednostkowe pokrywają różne scenariusze, w tym liczby, które spełniają każde z warunków funkcji, oraz liczby niespełniające żadnego z nich.

## Wynik

