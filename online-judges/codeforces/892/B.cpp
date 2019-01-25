#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	int n;
	scanf("%d", &n);
	set<int> s;
	while (n--) {
		int a; scanf("%d", &a);
		while(n+a >= *s.begin() && s.size()) {
			s.erase(s.begin());
		}
		s.insert(n);
	}
	printf("%d\n", s.size());
    return 0;
}

