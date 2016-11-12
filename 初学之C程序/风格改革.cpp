#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int n, i, t, p, y;
	long a, x;
	double k, m;
	char c = 65;
	scanf("%ld %d", &a, &p);
	k = log((double) p);
	m = log((double) a);
	n = (int) (m / k) + 1;
	i = 1;
	x = a;
	t = n - i + 1;
	for (i = 1; t >= 1;) {
		x = a;
		while (t >= 1) {
			y = x % p;
			x = x / p;
			t--;
		}
		if ((y >= 10) && (y <= p - 1)) {
			c = 65 + y - 10;
			printf("%c", c);
		} else {
			printf("%d", y);
		}
		i++;
		t = n - i + 1;
	}
	if (a == 0) {
		printf("0");
	}
	printf("\n");
	system("pause");
	return 0;
}
