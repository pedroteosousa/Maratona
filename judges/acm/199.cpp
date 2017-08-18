#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1791791791;

#define pb push_back

struct person {
	int s, b;
	int index;
	person(int _s, int _b, int i) {
		s = _s;
		b = _b;
		index = i;
	}
};

bool cmp(const person &a, const person &b) {
	if (a.s < b.s) return true;
	else if (a.s == b.s) {
		if (a.b < b.b) return true;
		else if (a.b == b.b) return a.index < b.index;
		else return false;
	}
	else return false;
}

bool cmp2(const person &a, const person &b) {
	if (a.s < b.s && a.b < b.b) return true;
	else return false;
}

vector<struct person> v;
struct person mx[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.pb(person(a, b, i));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i=0;i<n;i++) {
		
	}
	return 0;
}

