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
	for(int k = 0; k < n; k++) {	
		int i;
		scanf("%d", &i);	
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	//printf("n is: %d\n", n);
	for(int j = 0; j < n; j++) {
		printf("%d ", v[j]);
	}
    return 0;
}

