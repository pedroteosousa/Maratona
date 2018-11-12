#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

double eps = 1e-6;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int d; scanf("%d", &d);
		if (d * d < 4 * d) {
			printf("N\n");
			continue;
		}
		double delta = sqrt(d * d - 4 * d);
		double b = (d + delta) / 2.0;
		double a = d - b;
		if (abs((a + b) - a * b) <= eps && abs((a + b) - (double)d) <= eps) {
			printf("Y %.10lf %.10lf\n", a, b);
			continue;
		}
		b = (d - delta) / 2.0;
		a = d - b;
		if (abs((a + b) - a * b) <= eps && abs((a + b) - (double)d) <= eps) {
			printf("Y %.10lf %.10lf\n", a, b);
			continue;
		}
		printf("N\n");
	}
    return 0;
}

/*
(d + sqrt(d * d - 4 * d) ) / 2
*/
