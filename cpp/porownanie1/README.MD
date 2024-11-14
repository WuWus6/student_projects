## Benchmark wydajności instrukcji if-else i switch w C++
## Opis
Ten program w języku C++ porównuje wydajność instrukcji if-else i switch, korzystając z frameworka Google Test. Kod mierzy czas wykonania obu konstrukcji dla tej samej liczby iteracji oraz sprawdza, czy wyniki zwracane przez obie funkcje są identyczne. Czas wykonania mierzony jest za pomocą biblioteki chrono w mikrosekundach.

## Kod
~~~~ cpp 
#include <iostream>
#include <chrono>
#include <gtest/gtest.h>

using namespace std;

int compareIf(int value) {
    if (value == 1) {
        return 10;
    }
    else if (value == 2) {
        return 20;
    }
    else if (value == 3) {
        return 30;
    }
    else {
        return 40;
    }
}

int compareSwitch(int value) {
    switch (value) {
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        default:
            return 40;
    }
}

TEST(BenchmarkTest, IfElseBenchmark) {
    const int iterations = 10000;
    int sumIf = 0;

    auto startIf = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        sumIf += compareIf(i % 4);
    }
    auto endIf = std::chrono::high_resolution_clock::now();
    auto durationIf = std::chrono::duration_cast<std::chrono::microseconds>(endIf - startIf);

    cout << "Czas wykonania instrukcji if-else: " << durationIf.count() << " mikrosekund" << endl;
}

TEST(BenchmarkTest, SwitchBenchmark) {
    const int iterations = 10000;
    int sumSwitch = 0;

    auto startSwitch = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        sumSwitch += compareSwitch(i % 4);
    }
    auto endSwitch = std::chrono::high_resolution_clock::now();
    auto durationSwitch = std::chrono::duration_cast<std::chrono::microseconds>(endSwitch - startSwitch);

    cout << "Czas wykonania instrukcji switch: " << durationSwitch.count() << " mikrosekund" << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
~~~~


## Funkcje
<li>compareIf(int value) – przyjmuje argument int value i zwraca int. Funkcja zwraca wartość
10 dla value == 1, 20 dla value == 2, 30 dla value == 3, a w przeciwnym wypadku 40.
<br/>

<li>compareSwitch(int value) – przyjmuje argument int value i zwraca int. Funkcja zwraca wartość
10 dla value == 1, 20 dla value == 2, 30 dla value == 3, a w przeciwnym wypadku 40.

<li>BenchmarkTest::IfElseBenchmark – wykonuje 10 000 iteracji funkcji compareIf z wartościami argumentu 
cyklicznie zmienianymi przez i % 4. Mierzy czas wykonania instrukcji if-else w mikrosekundach.

<li>BenchmarkTest::SwitchBenchmark – wykonuje 10 000 iteracji funkcji compareSwitch z wartościami argumentu 
cyklicznie zmienianymi przez i % 4. Mierzy czas wykonania instrukcji switch w mikrosekundach.

## Pomiar czasu dla if-else:

Eksperyment wykonany przy użyciu testów benchmarkowych pozwala na porównanie czasu wykonania instrukcji if-else i switch w scenariuszu częstych wywołań obu funkcji. Wyniki wskazują, która z instrukcji jest bardziej wydajna w danym kontekście operacji.

## Screen

![screen](zrzut.png)

Po wykonaniu testu program wyświetla czas wykonania dla obu przypadków (w mikrosekundach).
