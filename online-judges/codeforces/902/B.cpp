#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int p[N];
int c[N];
int resp = 1;

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n-1;i++) {
		scanf("%d", &p[i+1]);
		p[i+1]--;
	}
	for (int i=0;i<n;i++) {
		scanf("%d", &c[i]);
	}
	for (int i=0;i<n;i++) {
		if (c[i] != c[p[i]]) resp++;
	}
	printf("%d\n", resp);
    return 0;
}

