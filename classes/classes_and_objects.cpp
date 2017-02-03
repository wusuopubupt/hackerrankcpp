#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Student {
private:
	int scores[5];
public:
	void input() {
		scanf("%d %d %d %d %d", &scores[0], &scores[1], &scores[2], &scores[3], &scores[4]);	
	}
	int calculateTotalScore() {
		int total = 0;
		for(int i = 0; i < sizeof(scores)/sizeof(scores[0]); i++)	{
			total += scores[i];	
		}
		return total;
	}
};

int main() {
	int n;
	cin >> n;
	Student* stu = new Student[n];

	for(int i = 0; i < n; i++) {
		stu[i].input();	
	}

	int kristen_score = stu[0].calculateTotalScore();
	int cnt = 0;
	for(int i = 1; i < n; i++) {
		int total_score = stu[i].calculateTotalScore();	
		if(total_score > kristen_score) cnt++;
	}

	cout << cnt;

	return 0;
}
