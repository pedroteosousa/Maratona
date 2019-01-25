#include <bits/stdc++.h>

using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

const int N = 5e6 + 5;
const int inf = 1791791791;
const int mod = 1e9+7;

int main() {
	stack<int> sp;
	stack<bool> ov;
	int n;
	scanf("%d", &n);
	sp.push(inf);
	ov.push(true);
	int resp = 0;
	int speed = 0;
	while (n--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &speed);
			while (sp.top() < speed) {
				resp++;
				sp.pop();
			}
		}
		if (t == 2) {
			while(ov.top() == false) {
				resp++;
				ov.pop();
			}
		}
		if (t == 3) {
			int a; scanf("%d", &a);
			sp.push(a);
			while (sp.top() < speed) {
				resp++;
				sp.pop();
			}
		}
		if (t == 4) {
			ov.push(true);
		}
		if (t == 5) {
			sp.push(inf);
		}
		if (t == 6) {
			ov.push(false);
		}
	}
	printf("%d\n", resp);
    return 0;
}

