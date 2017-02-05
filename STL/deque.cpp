#include <iostream>
#include <deque> 
#include <vector>
using namespace std;


void print_deque(std::deque<int> dq) {
	std::deque<int>::iterator it = dq.begin();
	while(it != dq.end()) {
		cout << *it << " ";	
		it++;
	}
	cout << endl;
}

void printKMax(int arr[], int n, int k){
   //Write your code here.
	deque<int> dq;		
	int i = 0;
	int j = i;
	vector<int> v;
	while(i <= n-k) {
		while(dq.size() < k) {
			dq.push_back(arr[j++]);	
		}
		i++;
		//print_deque(dq);
		// deque is full, find max	
		std::deque<int>::iterator it = dq.begin();
		int max = *it;
  		while (it != dq.end()) {
			if(*it > max) {
				max = *it;
			}
			it++;
		}
		v.push_back(max);
		// pop left
		dq.pop_front();
	}
	for(int j = 0; j < v.size(); j++) {
		cout << v[j] << " ";		
	}
	cout << endl;
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}

