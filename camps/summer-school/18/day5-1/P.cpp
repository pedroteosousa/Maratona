#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+9;

template <int n> struct matrix {
	long long mat[n][n];
	matrix () {
		memset (mat, 0, sizeof (mat));
	}
	matrix (long long temp[n][n]) {
		memcpy (mat, temp, sizeof (mat));
	}
	void identity() {
		memset (mat, 0, sizeof (mat));
		for (int i=0;i<n;i++)
			mat[i][i] = 1;
	}
	matrix<n> operator* (const matrix<n> &a) const {
		matrix<n> temp;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++) {
					temp.mat[i][j] += mat[i][k]*a.mat[k][j];
					temp.mat[i][j] %= mod;
				}
		return temp;
	}
	matrix<n> operator% (long long m) {
		matrix<n> temp(mat);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				temp.mat[i][j] %= m;
		return temp;
	}
	matrix<n> pow(long long e, long long m) {
		matrix<n> temp;
		if (e == 0) {
			temp.identity();
			return temp%m;
		}
		if (e == 1) {
			memcpy (temp.mat, mat, sizeof (temp.mat));
			return temp%m;
		}
		temp = pow(e/2, m);
		if (e % 2 == 0)
			return (temp*temp)%m;
		else
			return (((temp*temp)%m)*pow(1, m))%m;
	}
};

int kmp[N];

void build(string s) {
	int n = s.size(), k = -1;
	kmp[0] = k;
	for (int i = 1; i < n+1; i++) {
		while (k >= 0 && s[k] != s[i-1]) k = kmp[k];
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

int main() {
	string p; int n;
	cin >> p >> n;
	build(p);
	string f1 = "", f2 = "a", f3 = "b";
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	if (n == 1) {
		if (p == string("a")) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if (n == 2) {
		if (p == string("b")) printf("1\n");
		else printf("0\n");
		return 0;
	}
	for (int i=0;i<20;i++) {
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
		if (n == i+3) {
			//cout << f3 << endl;
			printf("%d\n", (int)match(p, f3).size());
			return 0;
		}
	}
	int af0 = match(p, f1).size();
	int a = match(p, f3).size();
	int b = match(p, f2).size();
	int c = match(p, (f2+f3)).size() - a - b;
	int d = a - b - af0;
	long long base[4][4] = {{a,0,0,0}, {b,0,0,0}, {c,0,0,0}, {d,0,0,0}};
	long long temp[4][4] = {{1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}};	
	matrix<4> m(temp), ba(base);
	m = m.pow(n-22, mod);
	
	ba = (m*ba)%mod;
	printf("%lld\n", ba.mat[0][0]);
	return 0;
}

