#pragma once

#ifndef _YA_ALGORITHM_H_
#define _YA_ALGORITHM_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

namespace algorithm {

    void PrintWorryCount(const vector<bool>& is_nervous) {
        // подсчитываем количество элементов в векторе is_nervous, равных true
        int worry_count = 0;
        for (bool status : is_nervous) {
            if (status) {
                ++worry_count;
            }
        }
        cout << worry_count << endl;
    }

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
}


#endif // !_YA_ALGORITHM_H_

