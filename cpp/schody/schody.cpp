#include <iostream>
#include <cmath>
#include <stdexcept>

class KalkulatorSchodow {
public:
    // Konstruktor przyjmujący długość biegu schodów i wysokość kondygnacji (w cm)
    KalkulatorSchodow(double dlugoscSchodow, double wysokoscPietra)
        : dlugoscSchodow(dlugoscSchodow), wysokoscPietra(wysokoscPietra) {}

    // // Funkcja obliczająca liczbę stopni na podstawie docelowej wysokości stopnia
    // int obliczLiczbeStopni(double wysokoscStopniaDocelowa) {
    //     if (wysokoscStopniaDocelowa < 17.0 || wysokoscStopniaDocelowa > 19.0) {
    //         throw std::invalid_argument("Wysokość stopnia musi być pomiędzy 17 a 19 cm.");
    //     }
    //     return static_cast<int>(std::round(wysokoscPietra / wysokoscStopniaDocelowa));
    // }

//     int obliczLiczbeStopni(double wysokoscPietra, double minWysokoscStopnia = 17.0, double maxWysokoscStopnia = 19.0) {
//     // Liczymy wstępnie liczbę stopni dla maksymalnej i minimalnej wysokości stopnia
//     int liczbaStopni = std::round(wysokoscPietra / ((minWysokoscStopnia + maxWysokoscStopnia) / 2.0)) + 1;
//     return iloscStopni;
// }

// Funkcja obliczająca liczbę stopni na podstawie docelowej wysokości stopnia
    int obliczLiczbeStopni(double wysokoscStopniaDocelowa = (17.0 + 19.0) / 2) {
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
