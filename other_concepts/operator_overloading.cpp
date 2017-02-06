#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
	vector<vector<int>> a;

	Matrix operator + (Matrix x) {
		Matrix result;
		int m = a.size();			
		int n = a[0].size();
		//printf("m: %d, n: %d\n", m, n);
      	for(int i=0; i<m; i++) {
			vector<int> v;
         	for(int j=0; j<n; j++) {
				v.push_back(a[i][j] + x.a[i][j]);
				//result.a[i][j] = a[i][j] + x.a[i][j];
         	}
			result.a.push_back(v);
      	}
		return result;
	}
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}

