#include <bits/stdc++.h>
using namespace std;

const int N = 20000000;

int reverse(int n) {
	int c = 0;
	while (n != 0) {
		c *= 10;
		c += n%10;
		n /= 10;
	}
	return c;
}

bool isP[N];
vector<int> v;

int main () {
	isP[0] = isP[1] = 1;
	for (int i=2;i<N;i++) {
		if (isP[i] == 0) {
			v.push_back(i);
			for (int j=i+i;j<N;j+=i) {
				isP[j] = 1;
			}
		}
	}
	int n; scanf("%d", &n);
	for (auto i : v) {
		int r = reverse(i);
		if (isP[i] == 0 && isP[r] == 0 && i != r) n--;
		if (n == 0) {printf("%d\n", i); break;}
		//printf("%d %d\n", i, n);
	}
}
