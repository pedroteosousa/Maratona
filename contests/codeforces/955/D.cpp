#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+5;
int z[N];

void Z(string s) {
	int n = s.size();
	int m = -1;
	for (int i = 1; i < n; i++) {
		z[i] = 0;
		if (m != -1 && m + z[m] >= i)
			z[i] = min(m + z[m] - i, z[i-m]);
		while (i + z[i] < n && s[i+z[i]] == s[z[i]])
			z[i]++;
		if (m == -1 || i + z[i] > m + z[m])
			m = i;
	}
}

int kmp[N];

void build(string p) {
	int n = p.size(), k = -1;
	kmp[0] = k;
	for (int i = 1; i < n+1; i++) {
		while (k >= 0 && p[k] != p[i-1]) k = kmp[k];
		kmp[i] = ++k;
	}
}

vector<int> match(string p, string s) {
	int n = s.size(), m = p.size(), j = 0;
	vector<int> matches;
	for (int i = 1; i < n+1; i++) {
		while (j >= 0 && p[j] != s[i-1]) j = kmp[j];
		if (++j == m) {
			matches.push_back(i-j+1);
			j = kmp[j];
		}
	}
	return matches;
}

int main () {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	string s, t;
	cin >> s >> t;
	string rt = t;
	string rs = s;
	reverse(rs.begin(), rs.end());
	reverse(rt.begin(), rt.end());
	Z(rt + string("$") + rs);
	map<int, int> val;
	set<int> asdf, asdf2;
	for (int i=0;i<=k;i++) {
		asdf.insert(i);
		asdf2.insert(i);
	}
	for (int i=m+1;i<=n+m;i++) {
		//printf("%d ", z[i]);
		while (true) {
			set<int>::iterator it = asdf.upper_bound(z[i]);
			if (it != asdf.begin()) {
				it--;
				int g = *it;
				if (i-m-1+g >= k && val[g] == 0) {
					asdf.erase(it);
					val[g] = i-m-1+g;
					//printf("val[%d] = %d\n", g, val[g]);
				} else break;
			} else break;
		}
	}
	//printf("\n");

	Z(t + string("$") + s);
	for (int i=m+1;i<=n+m;i++) {
		while (true) {
			set<int>::iterator it = asdf2.upper_bound(z[i]);
			if (it != asdf2.begin()) {
				it--;
				int g = *it;
				if (i-m-1+g >= k) {
					asdf2.erase(it);
					//printf("z[%d] = %d, g = %d\n", i, z[i], g);
					if (val[m-g] != 0) {
						int y = val[m-g] + i-m+g-k;
						//printf("y = %d %d %d\n", y, val[m-g], i-m+g-k);
						if (y <= n && i-m+g < n-val[m-g]+1) {
							//printf("Yes\n%d %d\n", i-m+g-k, n-val[m-g]+1);
							return 0;
						}
					}
				} else break;
			} else break;
		}
		//printf("%d ", kmp[i]);
	}
	printf("No\n");
	return 0;
}
