/*
Даны неотрицательные целые числа n, k и массив целых чисел из диапазона [0..109] размера n.
Требуется найти k-ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k ∈[0..n-1] в отсортированном массиве.
Напишите нерекурсивный алгоритм.
Требования к дополнительной памяти: O(n).
Требуемое среднее время работы: O(n).
Функцию Partition следует реализовывать методом прохода двумя итераторами в одном направлении.
Описание для случая прохода от начала массива к концу:
Выбирается опорный элемент.
Опорный элемент меняется с последним элементом массива.
Во время работы Partition в начале массива содержатся элементы, не бОльшие опорного. Затем располагаются элементы, строго бОльшие опорного. В конце массива лежат нерассмотренные элементы. Последним элементом лежит опорный.
Итератор (индекс) i указывает на начало группы элементов, строго бОльших опорного.
Итератор j больше i, итератор j указывает на первый нерассмотренный элемент.
Шаг алгоритма. Рассматривается элемент, на который указывает j. Если он больше опорного, то сдвигаем j. Если он не больше опорного, то меняем a[i] и a[j] местами, сдвигаем i и сдвигаем j.
В конце работы алгоритма меняем опорный и элемент, на который указывает итератор i.

3_4. Реализуйте стратегию выбора опорного элемента “случайный элемент”. Функцию Partition реализуйте методом прохода двумя итераторами от конца массива к началу.

Ввод:                   Вывод:
10 4                    5
1 2 3 4 5 6 7 8 9 10

*/

#include <iostream>
#include <vector>

int get_random_pivot(int left, int right) {
    srand(time(NULL));
    return left + rand() % (right - left);
}

int partition(std::vector<int>& array, int left_bound, int right_bound) {
    if (left_bound == right_bound) {
        return left_bound;
    }
    std::swap(array[get_random_pivot(left_bound, right_bound)], array[right_bound]);
    int index = right_bound - 1;
    while (index >= left_bound && array[right_bound] < array[index]) {
        index--;
    }
    int j_index = index;
    while (--j_index >= left_bound) {
        if (array[right_bound] < array[j_index]) {
            std::swap(array[j_index], array[index]);
            index--;
        }
    }
    std::swap(array[++index], array[right_bound]);
    return index;
}

int KStat(std::vector<int>& array, int k) {
  int left_bound = 0;
  int right_bound = array.size() - 1;
  while (true) {
    int pivot = partition(array, left_bound, right_bound);
    if (pivot == k) {
        return array[pivot];
    }
    if (pivot < k) {
      left_bound = pivot + 1;
    } else {
      right_bound = pivot - 1;
    }
  }
}

void input_reader(std::vector<int>& array, int n) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        array.push_back(tmp);
    }
}

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<int> array;
    input_reader(array, n);
    std::cout << KStat(array, k) << '\n';
    return 0;
    
}
