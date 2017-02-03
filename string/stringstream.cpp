#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
	stringstream ss(str);
	std::vector<int> numbers;
	int num;
	char c;
	// Extract formatted data
	while (ss >> num) {
		numbers.push_back(num);
		ss >> c;
	}

	return numbers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

