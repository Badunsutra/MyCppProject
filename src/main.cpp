#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "lessions/algorithm.h"

using namespace std;
using namespace algorithm;

int main() {
	cout << CountStartsWithA({ "And"s, "another"s, "one"s, "gone"s, "another"s, "one"s "bites"s, "the"s, "dust"s });
	return 0;
}