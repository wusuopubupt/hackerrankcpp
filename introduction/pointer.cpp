#include <cstdio>
#include <cmath>

void update(int *a,int *b) {
    // Complete this function    
	int temp_a = *a;
	int temp_b = *b;
	*a += temp_b;
	*b = std::fabs(temp_a - temp_b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

