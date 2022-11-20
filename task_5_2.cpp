/*
Дан массив неотрицательных целых 64-битных чисел. Количество чисел не больше 1000000.
Отсортировать массив методом поразрядной сортировки LSD по байтам.

Ввод:           Вывод:
3               4 7 1000000
4 1000000 7
*/

#include <iostream>
#include <vector>

void input_reader(std::vector<int64_t>& array, int n) {
    int64_t tmp = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        array.push_back(tmp);
    }
}

void radix_sort(std::vector<int64_t>& array, int n, int degree) {
    std::vector<std::vector<int64_t>> digits(256, std::vector<int64_t>());
    int mask = 0b11111111;
    for (int i = 0; i < n; i++) {
        int tmp = (array[i] >> 8 * degree) & mask;
        digits[tmp].push_back(array[i]);
    }
    int64_t index = 0;
    for (int i = 0; i < 256; i++) {
        if (digits[i].size() != 0) {
            for (int j =  0; j < digits[i].size(); j++) {
                array[index++] = digits[i][j];
            }
        }
    }
}

void LSD_sort(std::vector<int64_t>& array, int n) {
    for (int i = 0; i < 8; i++) {
        radix_sort(array, n, i);
    }
}

void array_printer(std::vector<int64_t>& array) {
    for (const auto& i : array) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    int n = 0;
    std::vector<int64_t> array;
    std::cin >> n;
    input_reader(array, n);
    LSD_sort(array, n);
    array_printer(array);
    return 0;
}
