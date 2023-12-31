#include "algorithm.h"

namespace algorithm {
	
	void PrintWorryCount(const vector<bool>& is_nervous) {
		// ������������ ���������� ��������� � ������� is_nervous, ������ true
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

	pair<bool, double> CalcMedian(vector<double> samples) {
		if (samples.empty())
			return { false, 0 };

		auto m = samples.begin() + samples.size() / 2;
		nth_element(samples.begin(), m, samples.end());
		if (samples.size() % 2) {
			return { true, *m };
		}
		else {
			return { true, (*(m--) + *m) / 2};			
		}
	}

	vector<int> CountNamesLong(const set<string>& storage, const vector<string>& candidates) {
		vector<int> isInSet(candidates.size());
		transform(candidates.begin(), candidates.end(), isInSet.begin(),
			[&storage](const string& s) {return storage.count(s) ? 1 : 0; });
		return isInSet;
	}
}