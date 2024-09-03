#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int cnt0[33],cnt1[33];
void add(int x,int v)
{
	int i,ok;
	ok=0;
	for(i=20;~i;i--)
	{
		if(ok==0 && ((x>>i)&1)) cnt1[i]+=v;
		if(ok==1 && !((x>>i)&1)) cnt0[i]+=v;
		ok|=(x>>i)&1;
	}
}
int a[MAX];
int main()
{
	int n,q,i,x,y;
	ll ans;
	scanf("%d%d",&n,&q);
	memset(cnt0,0,sizeof cnt0);
	memset(cnt1,0,sizeof cnt1);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		add(a[i],1);
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		add(a[x],-1);
		a[x]=y;
		add(a[x],1);
		ans=0;
		for(i=0;i<=20;i++) ans+=1LL*cnt0[i]*cnt1[i];
		printf("%lld\n",ans);
	}
	return 0;
}
