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

    //����� �� ����������� ������� PrintWorryCount. ���������� �, ��������� count.
    inline void PrintWorryCount2(const vector<bool>& is_nervous) {
        int worry_count = count(is_nervous.begin(), is_nervous.end(), true);
        cout << worry_count << endl;
    }

    //�������� �������, ������� ��������� ������ ����� � ���������� ����� �����, ������������ �� ������� ��� ��������� ���������� ����� �a�.
    inline int CountStartsWithA(const vector<string>& xs) {
        return count_if(xs.begin(), xs.end(), 
                        [](const string& s) {return !s.empty() && tolower(s.at(0)) == 'a'; });
    }

    //�������� ���������� �����, ��� � ������� �������. �������� ��� ����� � ����� ������ �� ����������� � �� ������ � �������.
    void GetNumbersOfPeopleWithNameAgeAndSort();

    // ������� {true, �������}, ���� ��� ����������, �� ���� ������ ��������, ����� - {false, 0}
    // �������� �������� - ������ ��������� �� ��������, ��� ��� ��� ������� ������� ����������, ����� ������� �����
    pair<bool, double> CalcMedian(vector<double> samples);

    //��������� ������� �������������� ������� �����. ��������, ��� ������� �������������� ������� ������� ����� ����.
    inline double Average(const vector<int>& xs) {
        return xs.size() ? accumulate(xs.begin(), xs.end(), 0) / xs.size() : 0.0;
    }

    //�������� �������, ������� ��������� ������-������ � ��������� ����-���� � ���������� ����� ������.
    //� ����� ������ ����� ������� ���� ����-����� ����� ������, ����� ������ ����� �����. 
    //��������� � accumulate �������� ���������� �������, ������������� ��������� ����-���� � ������ ������� �������.
    inline string AddStopWords(const string& query, const set<string>& stop_words) {
        return accumulate(stop_words.begin(), stop_words.end(), query,
            [](string acc, string add) {return acc + " -" + add; });
    }
}


#endif // !_YA_ALGORITHM_H_

