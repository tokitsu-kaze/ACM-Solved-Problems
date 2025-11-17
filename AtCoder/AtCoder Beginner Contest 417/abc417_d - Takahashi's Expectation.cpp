#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int p[MAX],a[MAX],b[MAX],res[MAX][1010],sumb[MAX];
int main()
{
	int n,i,j,q,x,pos;
	scanf("%d",&n);
	sumb[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&p[i],&a[i],&b[i]);
		sumb[i]=sumb[i-1]+b[i];
	}
	for(j=0;j<=1000;j++)
	{
		res[n][j]=j;
		if(p[n]>=j) res[n][j]+=a[n];
		else res[n][j]=max(0,res[n][j]-b[n]);
	}
	for(i=n-1;i;i--)
	{
		for(j=0;j<=1000;j++)
		{
			res[i][j]=j;
			if(p[i]>=j) res[i][j]+=a[i];
			else res[i][j]=max(0,res[i][j]-b[i]);
			res[i][j]=res[i+1][res[i][j]];
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		if(x<=1000)
		{
			printf("%d\n",res[1][x]);
			continue;
		}
		if(x>sumb[n]+1000)
		{
			printf("%d\n",x-sumb[n]);
			continue;
		}
		pos=lower_bound(sumb+1,sumb+n+1,x-1000)-sumb;
		if(pos==n) printf("%d\n",x-sumb[pos]);
		else printf("%d\n",res[pos+1][x-sumb[pos]]);
	}
	return 0;
}

