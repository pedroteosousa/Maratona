#include<bits/stdc++.h> 

using namespace std;


int v[412];

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int day;
		cin>>day;
		v[day]++;
	}
	
	int pro=0;
	int cost=0;
	int resp=0;
	for(int i=0;i<=365;i++){
		pro+=v[i];
		if(cost+pro>=20 || (i==365 && cost+pro!=0)){
			pro=0;
			cost=0;
			resp++;
		}
		else cost+=pro;
	}
	cout<<resp<<endl;

}