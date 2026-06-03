#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e4+10;
const ll K=1e10;
int n,x[MAX],y[MAX],p[MAX];
int get_dist(int i,int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int ck()
{
	int i;
	ll res=0;
	for(i=2;i<=n;i++) res+=get_dist(p[i-1],p[i]);
	res+=get_dist(p[1],p[n]);
	return res<=K;
}
int main()
{
	int i,j,itx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++) p[i]=i;
	const int W=2e7;
	int B=W/sqrt(n);
	sort(p+2,p+1+n,[&](int a,int b){
		if(x[a]/B==x[b]/B)
		{
			if((x[a]/B)&1) return y[a]>y[b];
			else return y[a]<y[b];
		}
		return x[a]/B<x[b]/B;
	});
	for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	return 0;
}
