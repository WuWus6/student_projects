## Dokumentacja BubbleSort QuickSort
## 1. Wstęp
Kod przedstawia implementację dwóch algorytmów sortowania: BubbleSort oraz QuickSort, a także testy porównujące ich wydajność. Celem jest ocena czasu wykonania obu algorytmów na dużym zbiorze danych oraz wyciągnięcie wniosków na temat ich efektywności.

## 2. Kod
~~~ cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

using namespace std;

// Funkcja sortująca wektor za pomocą BubbleSort
void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Funkcja sortująca wektor za pomocą QuickSort
void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000);
    std::srand(std::time(0));
    std::generate(vec.begin(), vec.end(), std::rand);

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania QuickSort: " << elapsed_seconds.count() << "s\n";
}

// Test wydajności sortowania BubbleSort
TEST(BenchmarkTest, BubbleSortBenchmark) {
    std::vector<int> vec(10000);
    std::srand(std::time(0));
    std::generate(vec.begin(), vec.end(), std::rand);

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania BubbleSort: " << elapsed_seconds.count() << "s\n";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
~~~~

## 3. Funkcje

<li>void bubbleSort(vector<int>& vec): Funkcja przyjmuje wektor vec typu int i sortuje go w porządku rosnącym za pomocą algorytmu BubbleSort. Zwraca posortowany wektor przez referencję.<br/>

<li>void quickSort(vector<int>& vec): Funkcja przyjmuje wektor vec typu int i sortuje go w porządku rosnącym za pomocą algorytmu QuickSort. Zwraca posortowany wektor przez referencję.<br/>

<li>TEST(BenchmarkTest, QuickSortBenchmark): Test wydajności funkcji quickSort na wektorze o 10000 elementach. Zwraca czas wykonania w sekundach.<br/>

<li>TEST(BenchmarkTest, BubbleSortBenchmark): Test wydajności funkcji bubbleSort na wektorze o 10000 elementach. Zwraca czas wykonania w sekundach.<br/>

## 4. Wynik


