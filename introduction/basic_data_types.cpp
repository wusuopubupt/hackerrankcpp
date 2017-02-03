#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
	// int, long, long long, char, float, and double
	int a;
	long b;
	long long c;
	char d;
	float e;
	double f;
	scanf("%d %ld %lld %c %f %lf", &a, &b, &c, &d, &e, &f);
	printf("%d\n%ld\n%lld\n%c\n%.3f\n%.9lf\n", a, b, c, d, e, f);

    return 0;
}

