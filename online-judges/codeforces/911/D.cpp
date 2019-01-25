#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int a[N];

int count(int n) {
	int sum = 0;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (a[j] < a[i]) sum++;
		}
	}
	return sum%2;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	int sum = count(n);
	int m; scanf("%d", &m);
	while (m--) {
		int l, r;
		scanf("%d %d", &l, &r);
		sum += (r-l+1)/2;
		sum %= 2;
		printf("%s\n", sum == 0 ? "even" : "odd");
	}
    return 0;
}

