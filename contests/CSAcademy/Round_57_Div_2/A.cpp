#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

int v[1000];

int main() {
	char s[1000];
	scanf("%s", s);
	for (int i=0;i<26;i++) {
		scanf("%d", &v[i+'a']);
	}
	int n = strlen(s);
	long long resp = 0;
	for (int i=0;i<n;i++) {
		resp += v[s[i]];
	}
	printf("%lld\n", resp);
    return 0;
}

