#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAX=5e5+10;
mt19937_64 rd(time(0));
ull ha[MAX],out_sum[MAX],out_now[MAX];
int main()
{
	int n,m,i,q,op,a,b;
	ull tar,now;
	scanf("%d%d",&n,&m);
	tar=0;
	for(i=1;i<=n;i++)
	{
		ha[i]=rd();
		tar+=ha[i];
		out_sum[i]=out_now[i]=0;
	}
	now=0;
	while(m--)
	{
		scanf("%d%d",&a,&b);
		now+=ha[a];
		out_sum[b]+=ha[a];
		out_now[b]+=ha[a];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&a,&b);
			now-=ha[a];
			out_now[b]-=ha[a];
		}
		else if(op==2)
		{
			scanf("%d",&a);
			now-=out_now[a];
			out_now[a]=0;
		}
		else if(op==3)
		{
			scanf("%d%d",&a,&b);
			now+=ha[a];
			out_now[b]+=ha[a];
		}
		else if(op==4)
		{
			scanf("%d",&a);
			now-=out_now[a];
			out_now[a]=out_sum[a];
			now+=out_now[a];
		}
		if(now==tar) puts("YES");
		else puts("NO");
	}
	return 0;
}
