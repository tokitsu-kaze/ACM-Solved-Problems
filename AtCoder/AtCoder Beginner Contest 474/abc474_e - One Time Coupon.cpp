#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int a,b;}res[MAX];
ll sufb[MAX];
int main()
{
	int T,n,i,mna;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mna=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&res[i].a,&res[i].b);
			mna=min(mna,res[i].a);
		}
		sort(res+1,res+1+n,[](node x,node y){
			if(x.a-x.b==y.a-y.b)
			{
				if(x.a==y.a) return x.b>y.b;
				return x.a<y.a;
			}
			return x.a-x.b<y.a-y.b;
		});
		sufb[n+1]=0;
		for(i=n;i;i--) sufb[i]=sufb[i+1]+res[i].b;
		ans=LLINF;
		now=0;
		for(i=1;i<=n;i++)
		{
			now+=res[i].a;
			ans=min(ans,now+sufb[i+1]+1LL*max(0,n-i-i)*mna);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
amn=min{ai}
使用券，花费 bi；
先花费 amn 买券，再花费 bi 使用券；
直接花费 ai，多一张券。

考虑哪些直接 ai 买，哪些使用券。
直接买肯定是买 ai 小的，按 ai 从小到大排序？
枚举买几个 ai，后缀就全是 bi，再看看少几张券，用 anm 补一下？
发现样例3过不去。先猜一下按 ai-bi 排序。
*/
