## Benchmark wydajności instrukcji if-else i switch w C++
Opis
Ten program w języku C++ porównuje wydajność instrukcji if-else i switch, korzystając z frameworka Google Test. Kod mierzy czas wykonania obu konstrukcji dla tej samej liczby iteracji oraz sprawdza, czy wyniki zwracane przez obie funkcje są identyczne. Czas wykonania mierzony jest za pomocą biblioteki chrono w mikrosekundach.

## Kod


## Funkcje
compareIf(int value)

Funkcja korzysta z serii instrukcji if-else, aby zwrócić odpowiednią wartość na podstawie przekazanej liczby value.
Zwraca:

10, gdy value == 1

20, gdy value == 2

30, gdy value == 3

40 dla każdej innej wartości


compareSwitch(int value)

Funkcja korzysta z instrukcji switch, aby zwrócić odpowiednią wartość na podstawie przekazanej liczby value.
Zwraca:

10, gdy value == 1

20, gdy value == 2

30, gdy value == 3

40 dla każdej innej wartości


Test wydajności

Test: BenchmarkTest, IfElseBenchmark

Ten test porównuje czas wykonania funkcji if-else i switch dla 10 000 iteracji.

## Pomiar czasu dla if-else:

Funkcja compareIf jest wywoływana w pętli 10 000 razy, z wartościami od 0 do 3 (dzięki i % 4, co pozwala przełączać wartości w cyklu).
Pomiar czasu dla switch:

Funkcja compareSwitch jest wywoływana również 10 000 razy, z tymi samymi wartościami, co w przypadku if-else, aby porównać wydajność.
Porównanie wyników:

Test wykorzystuje makro ASSERT_EQ, aby sprawdzić, czy suma wyników z obu funkcji (if-else oraz switch) jest taka sama. Jeśli wyniki będą różne, test zakończy się niepowodzeniem.
Wyświetlanie czasu:

Po wykonaniu testu program wyświetla czas wykonania dla obu przypadków (w mikrosekundach).
Dzięki tej dokumentacji użytkownicy repozytorium będą mieli pełny obraz działania programu oraz sposobu, w jaki realizowany jest test porównawczy wydajności instrukcji if-else oraz switch.
