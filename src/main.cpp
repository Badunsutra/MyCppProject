#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "lessions/algorithm.h"
#include <chrono>

using namespace std;
using namespace algorithm;

template<class T>
void printVec(const vector<T>& vec) {
	cout << "v = {";
	for (size_t n = vec.size(), i = 0; i < vec.size(); cout << vec[i++] << (--n ? ", " : ""));
	cout << "};" << endl;
}

int main() {
	const int SAMPLE_COUNT = 5;
    set<string> s;
    vector<string> v;
    string stra = ""s;
    string strb = ""s;

    for (int j = 0; j < 10000; ++j) {
        s.insert(stra);
        stra += "a"s;
        if (j % 2 == 0) {
            v.push_back(strb);
            strb += "b"s;
        }
        else {
            v.push_back(stra);
        }
    }
    cout << "Testing slow version" << endl;
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        auto begin = chrono::steady_clock::now();
        CountNamesLong(s, v);
        auto end = chrono::steady_clock::now();
        cout << "Time difference Long = "s << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]"s << endl;
    }

	return 0;
}