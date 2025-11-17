#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int st[MAX],top,v[MAX],l[18][MAX],r[18][MAX];
int main()
{
	int n,k,q,i,j,a,b,x,y,tx,ty,ans;
	scanf("%d%d%d",&n,&k,&q);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	top=0;
	for(i=n;i;i--)
	{
		while(top && v[st[top-1]]<=v[i])
		{
			l[0][st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	top=0;
	for(i=1;i<=n;i++)
	{
		while(top && v[st[top-1]]<=v[i])
		{
			r[0][st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	l[0][1]=1;
	r[0][n]=n;
	for(j=1;j<=17;j++)
	{
		for(i=1;i<=n;i++)
		{
			l[j][i]=min(l[j-1][l[j-1][i]],l[j-1][r[j-1][i]]);
			r[j][i]=max(r[j-1][l[j-1][i]],r[j-1][r[j-1][i]]);
		}
	}
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		ans=0;
		x=y=a;
		for(j=17;~j;j--)
		{
			tx=min(l[j][x],l[j][y]);
			ty=max(r[j][x],r[j][y]);
			if(ty<b)
			{
				x=tx;
				y=ty;
				ans+=(1<<j);
			}
		}
		a=y;
		x=y=b;
		for(j=17;~j;j--)
		{
			tx=min(l[j][x],l[j][y]);
			ty=max(r[j][x],r[j][y]);
			if(tx>a)
			{
				x=tx;
				y=ty;
				ans+=(1<<j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

