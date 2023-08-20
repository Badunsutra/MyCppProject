#include "algorithm.h"

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
	
	void GetNumbersOfPeopleWithNameAgeAndSort() {		
		cout << "Count: ";
		int count;
		cin >> count;
		vector<pair<int, string>> pairs;
		for (int i = 0; i < count; ++i) {
			string name;
			int age;
			if (cin >> name >> age) {
				pairs.push_back({ age, name });
			}
		}

		sort(pairs.begin(), pairs.end());
		reverse(pairs.begin(), pairs.end());

		for (const auto& [age, name] : pairs) {
			cout << name << endl;
		}
	}

}