#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++)
	{
		vector<int> t;
		int n, k;
		scanf("%d %d", &n, &k);
		for(int j=0;j<n;j++)
		{
			int a;
			scanf("%d", &a);
			t.push_back(a);
		}
		sort(t.begin(), t.end());
		int mini = 1791791791;
		for(int j=0;j+k-1<n;j++)
		{
			mini = min(mini, t[j+k-1] - t[j]);
		}
		printf("%d\n", mini);
	}
	return 0;
}
