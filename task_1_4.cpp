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
/*
bool string_comparator (std::string left , std::string right){ 
    if (left.length() != right.length()){
        return (left.length() < right.length());
    } else {
        for (int i = 0; i < left.length(); i++){
            if (left[i] < right[i]){
                return true;
            } else if (left[i] > right[i]){
                return false;
            }
        }
        return false;
    }
}*/

void string_sort(std::vector<std::string>& string_collector, int n){
    for (int i = 1; i < n; ++i) {
    std::string tmp = string_collector[i];
    int j = i - 1;
    for (; j >= 0 && tmp.compare(string_collector[j]) < 0; --j) {
      string_collector[j + 1] = string_collector[j];
    }
    string_collector[j + 1] = tmp;
    }
}

void string_printer(std::vector<std::string>& string_collector, int n){
    for (int i = 0; i < n; i++){
        std::cout << string_collector[i] << '\n';
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