#include <gtest/gtest.h>
#include "schody.cpp"  // Włącz plik z kodem klasy KalkulatorSchodow

// Test konstrukcji obiektu KalkulatorSchodow
TEST(KalkulatorSchodowTest, Konstruktor) {
    KalkulatorSchodow kalkulator(500, 300);
    // Sprawdzanie, czy obiekt został utworzony bez wyjątków
    EXPECT_NO_THROW(KalkulatorSchodow(500, 300));
}

// Test obliczania liczby stopni przy prawidłowej wysokości stopnia
TEST(KalkulatorSchodowTest, ObliczLiczbeStopni_PrawidlowaWysokoscStopnia) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_EQ(kalkulator.obliczLiczbeStopni(18), 17);
}

// Test obliczania liczby stopni przy nieprawidłowej wysokości stopnia (poniżej zakresu)
TEST(KalkulatorSchodowTest, ObliczLiczbeStopni_WysokoscStopniaPonizejZakresu) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_THROW(kalkulator.obliczLiczbeStopni(16), std::invalid_argument);
}

// Test obliczania liczby stopni przy nieprawidłowej wysokości stopnia (powyżej zakresu)
TEST(KalkulatorSchodowTest, ObliczLiczbeStopni_WysokoscStopniaPowyzejZakresu) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_THROW(kalkulator.obliczLiczbeStopni(20), std::invalid_argument);
}

// Test obliczania rzeczywistej wysokości stopnia przy prawidłowej liczbie stopni
TEST(KalkulatorSchodowTest, ObliczWysokoscStopnia_PrawidlowaLiczbaStopni) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_NEAR(kalkulator.obliczWysokoscStopnia(17), 17.65, 0.01);
}

// Test obliczania rzeczywistej wysokości stopnia przy liczbie stopni równej 0 (oczekiwany wyjątek)
TEST(KalkulatorSchodowTest, ObliczWysokoscStopnia_LiczbaStopniZerowa) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_THROW(kalkulator.obliczWysokoscStopnia(0), std::invalid_argument);
}

// Test obliczania głębokości stopnia przy prawidłowej liczbie stopni
TEST(KalkulatorSchodowTest, ObliczGlebokoscStopnia_PrawidlowaLiczbaStopni) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_NEAR(kalkulator.obliczGlebokoscStopnia(17), 29.41, 0.01);
}

// Test obliczania głębokości stopnia przy liczbie stopni równej 0 (oczekiwany wyjątek)
TEST(KalkulatorSchodowTest, ObliczGlebokoscStopnia_LiczbaStopniZerowa) {
    KalkulatorSchodow kalkulator(500, 300);
    EXPECT_THROW(kalkulator.obliczGlebokoscStopnia(0), std::invalid_argument);
}

// Funkcja main() do uruchamiania wszystkich testów
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

