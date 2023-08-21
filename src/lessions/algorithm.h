#pragma once

#ifndef _YA_ALGORITHM_H_
#define _YA_ALGORITHM_H_

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <utility>
#include <numeric>

using namespace std;

namespace algorithm {

    void PrintWorryCount(const vector<bool>& is_nervous);

    //Ранее вы реализовали функцию PrintWorryCount. Перепишите её, используя count.
    inline void PrintWorryCount2(const vector<bool>& is_nervous) {
        int worry_count = count(is_nervous.begin(), is_nervous.end(), true);
        cout << worry_count << endl;
    }

    //Напишите функцию, которая принимает вектор строк и возвращает число строк, начинающихся на большую или маленькую английскую букву “a”.
    inline int CountStartsWithA(const vector<string>& xs) {
        return count_if(xs.begin(), xs.end(), 
                        [](const string& s) {return !s.empty() && tolower(s.at(0)) == 'a'; });
    }

    //Считайте количество людей, имя и возраст каждого. Выведите все имена с новой строки по старшинству — от старых к молодым.
    void GetNumbersOfPeopleWithNameAgeAndSort();

    // верните {true, медиана}, если она существует, то есть вектор непустой, иначе - {false, 0}
    // обратите внимание - вектор принимаем по значению, так как его придётся немного подпортить, чтобы вернуть ответ
    pair<bool, double> CalcMedian(vector<double> samples);

    //Вычислите среднее арифметическое вектора чисел. Считайте, что среднее арифметическое пустого массива равно нулю.
    inline double Average(const vector<int>& xs) {
        return xs.size() ? accumulate(xs.begin(), xs.end(), 0) / xs.size() : 0.0;
    }

    //Напишите функцию, которая принимает строку-запрос и множество стоп-слов и возвращает новую строку.
    //В новой строке после запроса идут стоп-слова через пробел, перед каждым стоит дефис. 
    //Передайте в accumulate четвёртым аргументом функцию, сворачивающую множество стоп-слов в «хвост» нужного формата.
    inline string AddStopWords(const string& query, const set<string>& stop_words) {
        return accumulate(stop_words.begin(), stop_words.end(), query,
            [](string acc, string add) {return acc + " -" + add; });
    }
}


#endif // !_YA_ALGORITHM_H_

