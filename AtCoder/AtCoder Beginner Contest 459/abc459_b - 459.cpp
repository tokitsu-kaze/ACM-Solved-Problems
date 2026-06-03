#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int i,j,tot,x,id[26],n,c[11];
	string s;
	tot=0;
	for(i=2;i<=9;i++)
	{
		if(i==7||i==9) x=4;
		else x=3;
		for(j=0;j<x;j++)
		{
			id[tot++]=i;
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		c[i]=id[s[0]-'a'];
	}
	for(i=1;i<=n;i++) printf("%d",c[i]);
	puts("");
	return 0;
}
