/*
Дана последовательность целых чисел из диапазона (-1000000000 .. 1000000000). 
Длина последовательности не больше 1000000. Числа записаны по одному в строке. Количество чисел не указано. 
Пусть количество элементов n, и числа записаны в массиве a = a[i]: i из [0..n-1]. 
Требуется напечатать количество таких пар индексов (i,j) из [0..n-1], что (i < j и a[i] > a[j]). 
Указание: количество инверсий может быть больше 4*1000000000 - используйте int64_t. 

Ввод: Вывод:
4     6
3
2
1

*/

#include <iostream> 
#include <vector> 

int64_t Merge(std::vector<int64_t>& array, int left_bound, int median, int right_bound) {
    std::vector<int64_t> result(right_bound - left_bound);
    int i = left_bound; 
    int j = median;
    int64_t answer = 0;
    while (i < median && j < right_bound) {
        if (array[i] < array[j]) {
            result[i - left_bound + j - median] = array[i]; 
            i++; 
        } else {
            if (array[j] < array[i]) {  
                answer += median - i;  
            }
            result[i - left_bound + j - median] = array[j]; 
            j++;
        }
    }
    for (; i < median; ++i) {
        result[i - left_bound + j - median] = array[i];
    }
    for (; j < right_bound; ++j) {
        result[j - left_bound] = array[j];
    }
    for (int k = 0; k < result.size(); ++k) {
        array[left_bound + k] = result[k];
    }
    return answer;
}


void inversion_counter(std::vector<int64_t>& array, int left_bound, int right_bound, int64_t& answer) {
    if (right_bound - left_bound <= 1) {
        return;
    } 
    int median = (right_bound + left_bound) / 2;
    inversion_counter(array, left_bound, median, answer);
    inversion_counter(array, median, right_bound, answer);
    answer += Merge(array, left_bound, median, right_bound);
}

int64_t inversion_counter(std::vector<int64_t>& array) {
    int64_t answer = 0;
    inversion_counter(array, 0, array.size(), answer);
    return answer;
}

int main() {
    std::vector<int64_t> array;
    int64_t number = 0;
    while (std::cin >> number) {
        array.push_back(number);
    }
    std::cout << inversion_counter(array) << '\n';
    return 0;
}
