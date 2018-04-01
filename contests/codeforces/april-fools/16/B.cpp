#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

bool v[N];
int m[N];

int main() {
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &m[i]);
	}
	for (int j=0;j<n;j++) {
		int a; scanf("%d", &a);
		for (int i=a;i<N;i+=m[j]) {
			v[i] = true;
		}
	}
	int resp = 0;
	for (int i=0;i<N;i++) {
		if (v[i]) resp++;
	}
	printf("%lf\n", (double)resp / (double)N);
    return 0;
}

