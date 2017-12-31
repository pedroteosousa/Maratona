#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e2 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	char s1[N], s2[N];
	scanf("%s %s", s1, s2);
	int i = 0;
	for (i=1;i<strlen(s1);i++) {
		if (s1[i] >= s2[0]) {
			s1[i] = s2[0];
			s1[i+1] = '\0';
			break;
		}
	}
	if (strlen(s1) == 1) {
		s1[1] = s2[0];
		s1[2] = '\0';
	}
	else if (s1[strlen(s1)-1] != s2[0]) {
		int n = strlen(s1);
		s1[n] = s2[0];
		s1[n+1] = '\0';
	}
	printf("%s\n", s1);
    return 0;
}

