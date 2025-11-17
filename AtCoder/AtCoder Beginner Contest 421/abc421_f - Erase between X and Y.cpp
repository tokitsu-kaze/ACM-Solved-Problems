#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int l[MAX],r[MAX],op[MAX],x[MAX],y[MAX],pos[MAX];
int main()
{
	int q,i,now,tot;
	ll ans;
	l[0]=r[0]=-1;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&op[i],&x[i]);
		if(op[i]==1)
		{
			l[i]=x[i];
			r[i]=r[x[i]];
			r[x[i]]=i;
		}
		else scanf("%d",&y[i]);
	}
	now=0;
	tot=0;
	while(now!=-1)
	{
		pos[now]=++tot;
		now=r[now];
	}
	l[0]=r[0]=-1;
	for(i=1;i<=q;i++)
	{
		if(op[i]==1)
		{
			l[i]=x[i];
			r[i]=r[x[i]];
			l[r[x[i]]]=i;
			r[x[i]]=i;
		}
		else
		{
			if(pos[x[i]]>pos[y[i]]) swap(x[i],y[i]);
			ans=0;
			now=r[x[i]];
			while(now!=y[i])
			{
//				cout<<now<<" "<<l[now]<<" "<<r[now]<<endl;
				ans+=now;
				r[l[now]]=r[now];
				l[r[now]]=l[now];
				now=r[now];
			}
			printf("%lld\n",ans);
		}
/*		now=0;
		while(now!=-1)
		{
			cout<<now<<" ";
			now=r[now];
		}
		puts("");*/
	}
	return 0;
}
