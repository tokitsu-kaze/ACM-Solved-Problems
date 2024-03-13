#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
const int mod=100003;
ll comb[33][33];
void init(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=m;j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
int main()
{
	int n,m,k,i,j,pre;
	ll now;
	string ans;
	init(31,31);
	scanf("%d%d%d",&n,&m,&k);
	ans="";
	pre=0;
	k--;
	for(i=n-1;~i;i--)
	{
		now=0;
		for(j=0;j+pre<=m;j++) now+=C(i,j);
		if(k>=now)
		{
			k-=now;
			pre++;
			ans+="1";
		}
		else ans+="0";
	}
	cout<<ans<<"\n";
	return 0;
}
