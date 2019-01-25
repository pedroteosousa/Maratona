#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5e6 + 5;
const ll inf = 1791791791;
const ll mod = 1e9+7;

string s[40] = {"Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson","Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield","Arthur","Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan"};

int main() {
	int n;
	scanf("%d", &n);
	printf("%s\n", s[n-1].c_str());
    return 0;
}

