## Projekt Schody

## Wstęp
Program oblicza parametry schodów na podstawie podanych danych wejściowych zgodnie z zasadami techniki budowy i normami unijnymi. Omówiony zostanie kod programu, funkcjonalność zaimplementowanych funkcji oraz eksperyment pokazujący jego działanie. Wyniki obliczeń zostaną przedstawione w formie liczby stopni, ich wysokości oraz głębokości. Program przyjmuje jako dane wejściowe długość biegu schodów, wysokość kondygnacji i docelową wysokość stopnia, weryfikuje też wartości wyjściowe.

## Ilustracja poglądowa

![screen](schody_wymiary.png)

## Kod kalkulatora
~~~~ cpp
#include <iostream>
#include <cmath>
#include <stdexcept>

class KalkulatorSchodow {
public:
    // Konstruktor przyjmujący długość biegu schodów i wysokość kondygnacji (w cm)
    KalkulatorSchodow(double dlugoscSchodow, double wysokoscPietra)
        : dlugoscSchodow(dlugoscSchodow), wysokoscPietra(wysokoscPietra) {}

    // Funkcja obliczająca liczbę stopni na podstawie docelowej wysokości stopnia
    int obliczLiczbeStopni(double wysokoscStopniaDocelowa) {
        if (wysokoscStopniaDocelowa < 17.0 || wysokoscStopniaDocelowa > 19.0) {
            throw std::invalid_argument("Wysokość stopnia musi być pomiędzy 17 a 19 cm.");
        }
        return static_cast<int>(std::round(wysokoscPietra / wysokoscStopniaDocelowa));
    }

    // Funkcja obliczająca rzeczywistą wysokość stopnia
    double obliczWysokoscStopnia(int iloscStopni) {
        if (iloscStopni <= 0) {
            throw std::invalid_argument("Liczba stopni musi być większa od zera.");
        }
        return wysokoscPietra / iloscStopni;
    }

    // Funkcja obliczająca rzeczywistą głębokość stopnia na podstawie liczby stopni i długości biegu
    double obliczGlebokoscStopnia(int iloscStopni) {
        if (iloscStopni <= 0) {
            throw std::invalid_argument("Liczba stopni musi być większa od zera.");
        }
        return dlugoscSchodow / iloscStopni;
    }

private:
    double dlugoscSchodow;       // Długość biegu schodów (w cm)
    double wysokoscPietra;       // Wysokość kondygnacji (w cm)
};
~~~~

## Kod funkcji main
~~~~ cpp
int main() {
    double dlugoscSchodow, wysokoscPietra, wysokoscStopniaDocelowa;
    
    std::cout << "Podaj długość biegu schodów (w cm): ";
    std::cin >> dlugoscSchodow;
    std::cout << "Podaj wysokość kondygnacji (w cm): ";
    std::cin >> wysokoscPietra;
    
    std::cout << "Podaj docelową wysokość stopnia (w cm, pomiędzy 17 a 19): ";
    std::cin >> wysokoscStopniaDocelowa;

    try {
        KalkulatorSchodow kalkulator(dlugoscSchodow, wysokoscPietra);

        int iloscStopni = kalkulator.obliczLiczbeStopni(wysokoscStopniaDocelowa);
        double rzeczywistaWysokoscStopnia = kalkulator.obliczWysokoscStopnia(iloscStopni);
        double glebokoscStopnia = kalkulator.obliczGlebokoscStopnia(iloscStopni);

        std::cout << "Liczba stopni: " << iloscStopni << std::endl;
        std::cout << "Wysokość każdego stopnia: " << rzeczywistaWysokoscStopnia << " cm" << std::endl;
        std::cout << "Głębokość każdego stopnia: " << glebokoscStopnia << " cm" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << '\n';
    }

    return 0;
}
~~~~
Funkcja main odpowiada za interakcję z użytkownikiem, przyjmując wartości wejściowe i wywołując odpowiednie metody klasy KalkulatorSchodow. W razie błędnych wartości wejściowych (np. niewłaściwa wysokość stopnia) program wyświetli odpowiedni komunikat błędu.
## Kod test
~~~~ cpp
#include <gtest/gtest.h>
#include "stairs.cpp"

TEST(KalkulatorSchodowTest, ObliczLiczbeStopni) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_EQ(kalkulator.obliczLiczbeStopni(18), 17);
}

TEST(KalkulatorSchodowTest, ObliczWysokoscStopnia) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_NEAR(kalkulator.obliczWysokoscStopnia(17), 17.65, 0.01);
}

TEST(KalkulatorSchodowTest, ObliczGlebokoscStopnia) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_NEAR(kalkulator.obliczGlebokoscStopnia(17), 29.41, 0.01);
}
~~~~
Testy sprawdzają poprawność metod klasy KalkulatorSchodow, weryfikując, czy wyniki są zgodne z oczekiwaniami.
## Wynik testu

![screen](wynik.png)
