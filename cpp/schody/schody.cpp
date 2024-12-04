#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip> // Do precyzyjnego wyświetlania wyników

class KalkulatorSchodow {
public:
    // Konstruktor przyjmujący długość biegu schodów i wysokość kondygnacji (w cm)
    KalkulatorSchodow(double dlugoscSchodow, double wysokoscPietra)
        : dlugoscSchodow(dlugoscSchodow), wysokoscPietra(wysokoscPietra) {}

    // Funkcja próbująca znaleźć odpowiednią wysokość stopnia (17, 18, 19 cm)
    void znajdzOdpowiedniaWysokosc() {
        for (double wysokoscStopniaDocelowa : {17.0, 18.0, 19.0}) {
            int iloscStopni = static_cast<int>(wysokoscPietra / wysokoscStopniaDocelowa);

            // Oblicz rzeczywistą wysokość stopnia
            double rzeczywistaWysokosc = wysokoscPietra / iloscStopni;

            // Sprawdź, czy liczba stopni jest całkowita
            if (std::fmod(wysokoscPietra, wysokoscStopniaDocelowa) == 0) {
                std::cout << "Dla docelowej wysokosci stopnia " << wysokoscStopniaDocelowa 
                          << " cm, liczba stopni wynosi: " << iloscStopni << '\n';
                std::cout << "Rzeczywista wysokosc stopnia: " << rzeczywistaWysokosc << " cm\n";
                std::cout << "Glebokosc stopnia: " << obliczGlebokoscStopnia(iloscStopni) << " cm\n";
                return; // Znaleziono odpowiednią wysokość
            }
        }

        // Jeśli nie udało się znaleźć odpowiedniej wysokości
        std::cout << "Nie da sie zaprojektowac schodow z odpowiednia liczba stopni (17, 18, 19 cm).\n";
    }

    // Funkcja obliczająca rzeczywistą głębokość stopnia
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

int main() {
    try {
        // Wprowadzenie danych przez użytkownika
        double dlugoscSchodow, wysokoscPietra;

        std::cout << "Podaj dlugosc biegu schodow (w cm): ";
        std::cin >> dlugoscSchodow;
        std::cout << "Podaj wysokosc kondygnacji (w cm): ";
        std::cin >> wysokoscPietra;

        KalkulatorSchodow kalkulator(dlugoscSchodow, wysokoscPietra);

        // Znajdź odpowiednią wysokość stopnia
        kalkulator.znajdzOdpowiedniaWysokosc();
    } catch (const std::exception& e) {
        std::cerr << "Wystapil blad: " << e.what() << '\n';
    }

    return 0;
}
