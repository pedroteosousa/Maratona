#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

int v[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0;i<k;i++) {
		int a;
		scanf("%d", &a);
		v[a-1] = 1;
	}
	int t = 0;
	for (int i=0;i<k;i++) {
		int a;
		scanf("%d", &a);
		v[a-1] = 2;
	}
	for (int i=0;i<n;i++) {
		int l = (i-1+n)%n, r = (i+1)%n;
		if (v[i] == 1) {
			if (v[l] != 2 && v[r] == 2) {
				t++;
				v[r] = 0;
				v[i] = 0;
			}
			if (v[l] == 2 && v[r] != 2) {
				t++;
				v[l] = 0;
				v[i] = 0;
			}
		}
	}
	for (int i=0;i<n;i++) {
		int l = (i-1+n)%n, r = (i+1)%n;
		if (v[i] == 1 && (v[l] == 2 || v[r] == 2)) {
			t++;
			if (v[l] == 2) v[l] = 0;
			else v[r] = 0;
		}
	}
	printf("%d\n", t+(k-t)*2);
    return 0;
}

