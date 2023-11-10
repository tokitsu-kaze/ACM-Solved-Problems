#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e6+10;
int main()
{
	int n,m,i;
	string s;
	map<string,int> mp;
	scanf("%d",&n);
	while(n--)
	{
		cin>>s;
		mp[s]=1;
	}
	scanf("%d",&m);
	while(m--)
	{
		cin>>s;
		if(!mp.count(s))
		{
			puts("WRONG");
			continue;
		}
		if(mp[s]) puts("OK");
		else puts("REPEAT");
		mp[s]=0;
	}
	return 0;
}
