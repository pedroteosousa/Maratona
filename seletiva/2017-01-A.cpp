#include <bits/stdc++.h>

using namespace std;

int p[200000];

int inf = 1791791791;

int main()
{
	vector<long long> s;
	int t;
	scanf("%d", &t);
	for(int i=2;i<10000;i++) p[i] = 0;
	for(int i=2;i<10000;i++)
	{
		if (p[i] == 0)
		{
			p[i] = 1;
			for(int j=2*i;j<10000;j+=i)
			{
				p[j]++;
			}
		}
	}
	for(int i=2;i<10000;i++)
	{
		if (p[i] >= 3)
		{
			s.push_back(i);
		}
	}
	for(int i=0;i<t;i++)
	{
		int a;
		scanf("%d", &a);
		printf("%lld\n", s[a-1]);
	}
	return 0;
}
