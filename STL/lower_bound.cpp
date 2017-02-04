#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}
	//sort(v.begin(), v.end());

	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int k;
		scanf("%d", &k);	
		std::vector<int>::iterator it;
		/* timeout
		if((it = std::find(v.begin(), v.end(), k)) != v.end()) {
			cout << "Yes " << it -v.begin() + 1 << endl;		
		} else {
			it  = std::lower_bound (v.begin(), v.end(), k); 
			cout << "No " << it - v.begin() + 1 << endl;
		}*/
		it = std::lower_bound(v.begin(), v.end(), k);
		if(*it == k) {
			cout << "Yes " << it -v.begin() + 1 << endl;		
		} else {
			cout << "No " << it -v.begin() + 1 << endl;		
		}
	}
    return 0;
}

