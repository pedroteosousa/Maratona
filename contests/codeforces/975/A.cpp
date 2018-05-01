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
	int n; scanf("%d", &n);	
	set<vector<int> > resp;
	for (int i=0;i<n;i++) {
		string s;
		cin >> s;
		vector<int> temp;
		for (int i=0;i<26;i++) {
			temp.pb(0);
		}
		for (int j=0;j<s.size();j++) {
			temp[s[j]-'a'] = 1;
		}
		resp.insert(temp);
	}
	printf("%d\n", (int)resp.size());
    return 0;
}

