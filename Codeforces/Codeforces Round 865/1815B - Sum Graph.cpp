#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
void add(int x)
{
	printf("+ %d\n",x);
	fflush(stdout);
	scanf("%d",&x);
}
int ask(int i,int j)
{
	int res;
	printf("? %d %d\n",i,j);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
int id[MAX],dis[MAX],ans[MAX];
int main()
{
	int T,n,i,mx,pos,tmp,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		add(n);
		add(n+1);
		pos=1;
		mx=0;
		for(i=2;i<=n;i++)
		{
			tmp=ask(1,i);
			if(tmp>mx)
			{
				mx=tmp;
				pos=i;
			}
		}
		dis[pos]=1;
		for(i=1;i<=n;i++)
		{
			if(i==pos) continue;
			dis[i]=ask(pos,i)+1;
		}
		l=1;
		r=n;
		for(i=1;i<=n;i++)
		{
			if(i&1) id[i]=r--;
			else id[i]=l++;
		}
		printf("!");
		for(i=1;i<=n;i++) printf(" %d",id[dis[i]]);
		for(i=1;i<=n;i++) printf(" %d",id[n-dis[i]+1]);
		puts("");
		fflush(stdout);
		scanf("%d",&tmp);
	}
	return 0;
}
/*
要么从连通性去考虑，要么想办法构造任意两个点的距离不同。
手玩一下看看连边是怎么一回事，
发现对n和n+1操作，两次就能连成一条链，这样任意两点距离不同。
考虑找端点，对1做n-1次询问，距离最长的是端点。

1 2 3 4 5 6
6-1-5-2-4-3

1
6
1
1
2
4
3
1
1
4
2
1
3
5

*/
