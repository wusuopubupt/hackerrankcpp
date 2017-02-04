#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	set<int> s;
	int x, y;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		if(1 == x) {
			s.insert(y);	
		} else if(2 == x) {
			s.erase(y);	
		} else if(3 == x) {
			set<int>::iterator itr = s.find(y);			
			if(itr == s.end()) {
				cout << "No" << endl;		 
			} else {
				cout << "Yes" << endl;		 
			}
		}
	}
    return 0;
}

