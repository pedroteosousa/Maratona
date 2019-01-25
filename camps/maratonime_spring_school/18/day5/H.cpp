#include<bits/stdc++.h> 

using namespace std;
#define int long long
int l,m;

char s[112];

int mows(int ch,int ti,int pot,int mins){
	mins+=ch;
	int blocks=mins/(ch+ti);
	int resp=blocks*ti*pot;
	mins-=(ch+ti)*blocks;
	mins-=ch;
	if(mins>0)resp+=mins*pot;
	return resp;
}



int32_t main(){
	//ios::sync_with_stdio(false);
	//cin.tie();
	
	vector<pair<pair<int,int>,string>> v;
	
	scanf("%lld%lld",&l,&m);
	getchar();
	for(int i=0;i<m;i++){
		fgets(s,112,stdin);
		int j=0;
		string name;
		int p=0,c=0,t=0,r=0;
		while(s[j]!=','){
			//cout<<s[j]<<" ";
			name.push_back(s[j]);
			j++;
		}
		j++;
		//cout<<"leu nome"<<endl;
		while(s[j]!=','){
			p*=10;
			p+=s[j]-'0';
			j++;
		}
		j++;
		//cout<<"leu nome"<<endl;
		while(s[j]!=','){
			c*=10;
			c+=s[j]-'0';
			j++;
		}
		j++;
		//cout<<"leu nome"<<endl;
		while(s[j]!=','){
			t*=10;
			t+=s[j]-'0';
			j++;
		}
		j++;
		//cout<<"leu nome"<<endl;
		while(s[j]!='\n'){
			r*=10;
			r+=s[j]-'0';
			j++;
		}
		//cout<<"leu nome"<<endl;
		//cout<<name<<" "<<p<<" "<<c<<" "<<t<<" "<<r<<endl;
		bool deuruim=0;
		for(int k=1;k<=l;k++){
			int mo=mows(r,t,c,10080ll*k);
			//cout<<name<<" "<<i<<" "<<mo<<" "<<l*i<<endl;
			if(mo<l*k){
				deuruim=1;
				break;
			}
		}
		if(!deuruim)v.push_back(make_pair(make_pair(p,i),name));
	}
	if(v.size()==0){
		cout<<"no such mower"<<endl;
		return 0;
	}
	sort(v.begin(),v.end());
	int pricemin=v[0].first.first;
	for(int i=0;i<v.size();i++){
		if(v[i].first.first==pricemin)
			cout<<v[i].second<<endl;
	}
}