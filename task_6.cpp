/*
Дан массив целых чисел в диапазоне [0..10^9]. Размер массива кратен 10 и ограничен сверху значением 2.5 * 10^7 элементов. 

Все значения массива являются элементами псевдо-рандомной последовательности. 

Необходимо написать функцию сортировки массива.

Для этого нужно прислать .cpp файл, в котором описать функцию Sort

void Sort(unsigned int* arr, unsigned int size);

Необходимо включить в файл header #include "sort.h"
*/

#include "sort.h"
#include <iostream> 
#include <stack>

unsigned int get_random_pivot(unsigned int* array, unsigned int left,unsigned int right) {
    unsigned int a = left + rand() % (right - left);
    unsigned int b = left + rand() % (right - left);
    unsigned int c = left + rand() % (right - left);
    if (array[a] < array[c]) {
		if (array[b] < array[a]) {
			return a;
		} else if (array[b] < array[c]) {
			return c;
		} else {
			return b;
		}
	} else if (array[b] < array[c]) {
		return c;
	} else if (array[a] < array[b]) {
		return a;
	} else {
		return b;
	}
}

inline unsigned int partition(unsigned int* array, unsigned int left_bound, unsigned int right_bound) {
    if (left_bound == right_bound) {
        return left_bound;
    }
    std::swap(array[get_random_pivot(array, left_bound, right_bound)], array[right_bound]);
    int64_t index = right_bound - 1;
    while (index >= left_bound && !(array[index] < array[right_bound])) {
        index--;
    }
    int64_t j_index = index;
    while (--j_index >= left_bound) {
        if (!(array[j_index] < array[right_bound])) {
            std::swap(array[j_index], array[index]);
            index--;
        }
    }
    std::swap(array[++index], array[right_bound]);
    return index;
}

void Sort(unsigned int* arr, unsigned int size) {
    unsigned int seed = time(nullptr);
	srand(seed);
    unsigned int left_bound = 0;
    unsigned int right_bound = size - 1;
    std::stack<unsigned int> params;
    params.push(left_bound);
    params.push(right_bound);
    while (!(params.empty())) {
        right_bound = params.top();
        params.pop();
        left_bound = params.top();
        params.pop();
        if (right_bound - left_bound +  1 >= 110) {
            unsigned int pivot_possition = partition(arr, left_bound, right_bound);
            if (left_bound + 1 < pivot_possition) {
                params.push(left_bound);
                params.push(pivot_possition - 1);
            }
            if (right_bound - 1 > pivot_possition) {
                params.push(pivot_possition + 1);
                params.push(right_bound);
            }
        } else {
            for (unsigned int i = left_bound + 1; i < right_bound + 1; ++i) {
                unsigned int tmp = arr[i];
                long long int j = i - 1;
                for (; j >= left_bound && tmp < arr[j]; --j) {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = tmp;
            }
        }
    }
}
