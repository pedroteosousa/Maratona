#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	char s[100];
	scanf("%s", s);
	int count = 0;
	for (int i=0;i<strlen(s);i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || (s[i] >= '0' && s[i] <= '9' && s[i]%2 != 0))
			count++;
	}
	printf("%d\n", count);
    return 0;
}

