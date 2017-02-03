#include <map>
#include <iostream>

using namespace std;

int main(){
    unsigned int n;
    cin >> n;

    // your code goes here
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

	if(n > 9) {
		cout << "Greater than 9" << endl;
	} else {
		cout << m[n] << endl;
	}	
    return 0;
}

