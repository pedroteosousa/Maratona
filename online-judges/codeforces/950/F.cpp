#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

int b[N];
int v[N];

int update(int p, int val, int n) {
	for(;p < n; p += p & -p) b[p] += val;
}

int getsum(int p) {
	int sum = 0;
	for(; p != 0; p -= p & -p) {
		sum += b[p];
	}
	return sum;
}

int get(int p) {
	return getsum(p) - getsum(p-1);
}

bool canSave(int p, int d, int n, int tot) {
	int t = min(p, n-p);
	if (n % 2 == 1 && 2*p == (n+1)) t = p;
	int l = max(p-d-1, 0);
	int r = min(p+d, n);
	int s = getsum(r) - getsum(l);
	if (s >= tot) return true;
	else return false;
}

int main() {
	int n, d, tot; scanf("%d %d %d", &n, &d, &tot);
	for (int i=0;i<n;i++) {
		scanf("%d", &v[i+1]);
		update(i+1, v[i+1], N);
	}
	int l1 = 1;
	int l2 = n;
	int resp = 0;
	for (int i=1;2*i<=(n+1);i++) {
		if (canSave(i, d, n, tot) && canSave(n-i+1, d, n, tot)) {
			if (get(i) >= tot) {
				update(i+1, get(i)-tot, N);
			} else {
				int miss = tot - get(i);
				while (miss != 0) {
					int have = get(l1);
					update(l1, -min(have, miss), N);
					miss -= min(have, miss);
					l1++;
				}
			}
			update(i, -get(i), N);
			if (n % 2 != 1 || i != (n+1)/2) {
				int j = n-i+1;	
				if (get(j) >= tot) {
					update(j-1, get(j)-tot, N);
				} else {
					int miss = tot - get(j);
					while (miss != 0) {
						int have = get(l2);
						update(l2, -min(have, miss), N);
						miss -= min(have, miss);
						l2--;
					}
				}
				update(j, -get(j), N);
			}
			resp++;
		
			//for (int y=1;y<=n;y++) printf("%d ", get(y));
			//printf("\n");
		} else {
			update(min(i+d, n-i), get(i), N);
			update(i, -get(i), N);

			update(max(n-i+1-d, i+1), get(n-i+1), N);
			update(n-i+1, -get(n-i+1), N);
		}
	}
	printf("%d\n", (n+1)/2 - resp);
	return 0;
}

