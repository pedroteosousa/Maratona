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
	map<string, int> m;
	for (int i=0;i<10;i++) {
		printf("%d\n", i);
		fflush(stdout);
		string s = string("");
		char c = 0;
		do {
			c = getchar();
			s = s + c;
		} while (c != '\n');
		m[s]++;
	}
	if (m[string("no\n")] == 5) printf("normal\n");
	else printf("grumpy\n");
	fflush(stdout);
    return 0;
}

