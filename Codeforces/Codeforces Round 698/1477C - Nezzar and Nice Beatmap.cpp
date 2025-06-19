#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int x[MAX],y[MAX],res[MAX],vis[MAX];
ll sqr(ll x){return x*x;}
ll dis(int i,int j){return sqr(x[i]-x[j])+sqr(y[i]-y[j]);}
int main()
{
	int n,i,j;
	ll mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	mx=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(dis(i,j)>mx)
			{
				mx=dis(i,j);
				res[1]=i;
				res[2]=j;
			}
		}
	}
	for(i=1;i<=n;i++) vis[i]=0;
	vis[res[1]]=vis[res[2]]=1;
	for(i=3;i<=n;i++)
	{
		mx=0;
		for(j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if(dis(res[i-1],j)>mx)
			{
				mx=dis(res[i-1],j);
				res[i]=j;
			}
		}
		vis[res[i]]=1;
	}
	for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}
