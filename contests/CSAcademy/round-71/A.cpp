#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

const int N = 1e5 + 5;
const int inf = 1791791791;

int main() {
	string s;
	cin >> s;
	int found = 0;
	for (int i = 0; i<s.size(); i++) {
		char c = s[i];
		if (c == 'A' && !found) {
			found = 1;
			printf("%c", c);
		} else if (c == 'B') {
			found = 0;
			printf("%c", c);
		}
	} printf("\n");
    return 0;
}

