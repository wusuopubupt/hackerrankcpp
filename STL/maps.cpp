#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;	
	map<string, int> m;
	int type;
	string name;
	int marks;
	for(int i = 0; i < n; i++) {
		cin >> type;		
		if(1 == type) {
			cin >> name >> marks;	
			map<string, int>::iterator itr = m.find(name);
			if(itr != m.end()) {
				itr->second = itr->second + marks;
			} else {
				m.insert(make_pair(name, marks));
			}
		} else if(2 == type)  {
			cin >> name;	
			m.erase(name);
		} else if(3 == type) {
			cin >> name;	
			map<string, int>::iterator itr = m.find(name);
			if(itr == m.end()) {
				cout << 0 << endl;	
			} else {
				cout << itr->second << endl;	
			}
		}
	}
	return 0;
}
