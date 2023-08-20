#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "lessions/algorithm.h"

using namespace std;
using namespace algorithm;

template<class T>
void printVec(const vector<T>& vec) {
	cout << "v = {";
	for (size_t n = vec.size(), i = 0; i < vec.size(); cout << vec[i++] << (--n ? ", " : ""));
	cout << "};" << endl;
}

int main() {
	cout << CalcMedian({ 1, 2, 3, 4 }).second << endl;
	cout << CalcMedian({ 1, 2, 3 }).second << endl;
	cout << CalcMedian({ 1, 2, 1000 }).second << endl;


	return 0;
}