#include <map>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
	unsigned int a, b;
	cin >> a >> b;	
	if(a > b) {
		return 0;
	}

	map<unsigned int, string> m = {
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"},
		{5, "five"},
		{6, "six"},
		{7, "seven"},
		{8, "eight"},
		{9, "nine"}
	};

	for(unsigned int i=a; i <= b; i++) {
		if(i <= 9) {
			cout << m[i] << endl;
		} else {
			if(i % 2 == 0) {
				cout << "even" << endl;
			} else {
				cout << "odd" << endl;
			}
		}	
	}

	
	
    return 0;
}

