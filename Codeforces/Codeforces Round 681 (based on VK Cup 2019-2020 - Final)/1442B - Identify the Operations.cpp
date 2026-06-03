#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX],b[MAX],tag[MAX],l[MAX],r[MAX],pos[MAX];
void del(int x)
{
	l[r[x]]=l[x];
	r[l[x]]=r[x];
}
int main()
{
	int T,n,k,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<=n+1;i++)
		{
			tag[i]=pos[i]=0;
			l[i]=i-1;
			r[i]=i+1;
		}
		l[0]=0;
		r[n+1]=n+1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		a[0]=a[n+1]=0;
		tag[0]=1;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&b[i]);
			tag[b[i]]=1;
		}
		ans=1;
		for(i=1;i<=k;i++)
		{
			tag[b[i]]=0;
			x=pos[b[i]];
			if(tag[a[l[x]]] && tag[a[r[x]]]) ans=0;
			else if(!tag[a[l[x]]] && !tag[a[r[x]]]) ans=ans*2%mod;
			del(x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
bi 互不相同是重要条件，稍微转化一下，在 a 中删 bi 跟删旁边两个没有本质区别。
所以就变成每次删掉 bi，看前驱后继有没有之后会出现的。
按题意模拟即可。
*/
