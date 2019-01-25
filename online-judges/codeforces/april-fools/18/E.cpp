#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int main() {
	int n; scanf("%d", &n);
	int t1 = 0, t2 = 0;
	for (int i=0;i<n;i++) {
		string s, s1;
		cin >> s >> s1;
		if (s1[0] == 's') {
			t1++;
		} else t2++;
	}
	if (t1 < t2) swap(t1, t2);
	for (int i=1;i<1000;i++) {
		int k = (i+1)/2;
		int k2 = i - k;
		int p1 = k*k + k2*k2;
		int p2 = i*i-p1;
		if (p1 >= t1 && p2 >= t2) {
			printf("%d\n", i);
			return 0;
		}
	}
    return 0;
}

