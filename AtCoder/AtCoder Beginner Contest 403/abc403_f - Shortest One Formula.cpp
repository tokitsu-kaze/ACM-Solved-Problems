#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
string dp[MAX],g[MAX];
int main()
{
	string tmp;
	int i,j,n;
	dp[0]=g[0]="";
	dp[1]=g[1]="1";
	dp[11]=g[11]="11";
	dp[111]=g[111]="111";
	dp[1111]=g[1111]="1111";
	for(i=1;i<=MAX-10;i++)
	{
		if(g[i]!="") continue;
		for(j=1;j<i;j++)
		{
			tmp=dp[j]+"+"+dp[i-j];
			if(dp[i]==""||tmp.size()<dp[i].size()) dp[i]=tmp;
		}
		g[i]="("+dp[i]+")";
		for(j=2;j<i;j++)
		{
			if(i%j) continue;
			tmp=g[j]+"*"+g[i/j];
			if(dp[i]==""||tmp.size()<dp[i].size()) dp[i]=tmp;
			if(g[i]==""||tmp.size()<g[i].size()) g[i]=tmp;
		}
//		cout<<i<<" "<<dp[i]<<endl;
	}
	scanf("%d",&n);
	cout<<dp[n]<<"\n";
	return 0;
}
