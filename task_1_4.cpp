/*Напишите программу, печатающую набор строк в лексикографическом порядке.
Строки разделяются символом перевода строки '\n'. 
Если последний символ в потоке ввода '\n', считать, что после него нет пустой строки. 
Известно, что либо n < 100, либо n <= 1000, но при этом число инверсий в данном наборе строк меньше 100. 
Максимальная длина строки 255 символов. Написать свою функцию сравнения строк. Сортировать вставками.

Ввод	Вывод
4       ab
caba    aba
abba    abba
ab      caba
aba
*/

#include <iostream>
#include <vector>
#include <string>

bool string_comparator(const std::string& left, const std::string& right){
    int iter1 = 0;
    int iter2 = 0;
    while (iter1 < left.length() && iter2 < right.length()){
        if (left[iter1++] != right[iter2++]){
            return left[--iter1] < right[--iter2];
        }
    }
    return iter2 != right.length();
}

void string_sort(std::vector<std::string>& string_collector, int n){
    for (int i = 1; i < n; ++i) {
        std::string tmp = string_collector[i];
        int j = i - 1;
        for (; j >= 0 && string_comparator(tmp, string_collector[j]); --j) {
            string_collector[j + 1] = string_collector[j];
        }
        string_collector[j + 1] = tmp;
    }
}

void string_printer(std::vector<std::string>& string_collector, int n){
    for (const auto& i : string_collector){
        std::cout << i << '\n';
    }
}

int main(){
    int n = 0;
    std::vector<std::string> string_collector;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        std::string temp;
        std::cin >> temp;
        string_collector.push_back(temp);
    }
    string_sort(string_collector, n);
    string_printer(string_collector, n);
    return 0;
}
