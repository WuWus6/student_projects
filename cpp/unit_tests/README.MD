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
