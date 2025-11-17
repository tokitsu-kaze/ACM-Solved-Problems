#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],c[MAX],id[MAX];
int main()
{
	int T,n,i,mx;
	ll ans;
	scanf("%d",&n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&c[i]);
		id[i]=i;
		ans+=c[i];
	}
	sort(id+1,id+1+n,[&](int x,int y){
		return a[x]<a[y];
	});
	mx=a[id[1]]+c[id[1]];
	for(i=2;i<=n;i++)
	{
		ans+=max(0,a[id[i]]-mx);
		mx=max(mx,a[id[i]]+c[id[i]]);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
ai<aj<ak
i->k:ak-ai-ci
i->j->k:aj-ai-ci+ak-aj-cj=ak-ai-ci-cj
按a排序后，找中转点一定不劣 
*/

