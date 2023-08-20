#pragma once

#ifndef _YA_ALGORITHM_H_
#define _YA_ALGORITHM_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <utility>

using namespace std;

namespace algorithm {

    void PrintWorryCount(const vector<bool>& is_nervous);

    //–анее вы реализовали функцию PrintWorryCount. ѕерепишите еЄ, использу€ count.
    inline void PrintWorryCount2(const vector<bool>& is_nervous) {
        int worry_count = count(is_nervous.begin(), is_nervous.end(), true);
        cout << worry_count << endl;
    }

    //Ќапишите функцию, котора€ принимает вектор строк и возвращает число строк, начинающихс€ на большую или маленькую английскую букву УaФ.
    inline int CountStartsWithA(const vector<string>& xs) {
        return count_if(xs.begin(), xs.end(), 
                        [](const string& s) {return !s.empty() && tolower(s.at(0)) == 'a'; });
    }

    //—читайте количество людей, им€ и возраст каждого. ¬ыведите все имена с новой строки по старшинству Ч от старых к молодым.
    void GetNumbersOfPeopleWithNameAgeAndSort();

    // верните {true, медиана}, если она существует, то есть вектор непустой, иначе - {false, 0}
    // обратите внимание - вектор принимаем по значению, так как его придЄтс€ немного подпортить, чтобы вернуть ответ
    pair<bool, double> CalcMedian(vector<double> samples);
}


#endif // !_YA_ALGORITHM_H_

