/*
Группа людей называется современниками если был такой момент, когда они могли собраться вместе. 
Для этого в этот момент каждому из них должно было уже исполниться 18 лет, но ещё не исполниться 80 лет. 
Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников. 
В день 18летия человек уже может принимать участие в собраниях, а в день 80летия и в день смерти уже не может.
Замечание. Человек мог не дожить до 18-летия, либо умереть в день 18-летия. В этих случаях принимать участие в собраниях он не мог.

Ввод:                          Вывод:
3                              3                        
2 5 1980 13 11 2055             
1 1 1982 1 1 2030
2 1 1920 2 1 2000
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct date {
    int day;
    int month;
    int year;
    bool operator<(const date& right);
    bool is_start;
};


class human {

    public:

    human(const date& birth, const date& die) : birth_day(birth.day), birth_month(birth.month), birth_year(birth.year), die_day(die.day), die_month(die.month), die_year(die.year), valid(false) { consructor(); }
    ~human(){}

    date timeline_start;
    date timeline_end;

    bool valid;

    private:

    void consructor();

    int birth_day;
    int birth_month;
    int birth_year;

    int die_day;
    int die_month;
    int die_year;
};

void human::consructor() {
    if (die_year - birth_year < 18) {
        return;
    } else {
        valid = true;
         
        timeline_start.year = birth_year + 18;
        timeline_start.month = birth_month;
        timeline_start.day = birth_day;
        
        timeline_start.is_start = true;
        timeline_end.is_start = false;

        if (die_year - birth_year < 80) {
        timeline_end.year = die_year;
        timeline_end.month = die_month;
        timeline_end.day = die_day;
        } else {
            timeline_end.year = birth_year + 80;
            timeline_end.month = birth_month;
            timeline_end.day = birth_day;
        }
    }
}

bool date::operator<(const date& right) { 
    if (this->year == right.year){
        if (this->month == right.month){
            return this->day < right.day;
        } else {
            return this->month < right.month;
        }
    } else {
        return this->year < right.year;
    }
}

void date_filler(date& date){
    for (int i = 0; i < 3; i++){
        int num = 0;
        std::cin >> num;
        if (i == 0){
            date.day = num;
        } else if (i == 1) {
            date.month = num;
        } else {
            date.year = num;
        }
    }
}

int contemporaries_counter(std::vector<date>& people, int count){
    std::sort(people.begin(), people.end());    // после сортировки наш массив представяет timeline от даты появления первой личности
    int counter = 0;                            // до даты ухода последней. Пробегая по массиву мы фиксируем 
    int tmp = 0;                                // максимальное количество наложений отрезков
    for (int i = 0; i < count; i++) {
        if (people[i].is_start) {
            tmp++;
            if (tmp > counter) {
                counter = tmp;
            }
        } else {
            tmp--;
        }
    }
    return counter;
}

int main(){
    int n = 0;
    std::cin >> n;
    std::vector<date> people;
    int count = 0;
    for (int i = 0; i < n; i++){
        date birth;
        date die;
        date_filler(birth);
        date_filler(die);
        human man = human(birth, die);
        if (man.valid){
            people.push_back(man.timeline_start);
            people.push_back(man.timeline_end);
            count += 2;
        }
    }
    std::cout << contemporaries_counter(people, count) << '\n';
    return 0; 
}
