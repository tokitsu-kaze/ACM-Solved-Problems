#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=1e6+10;
int id[MAX],now[MAX],pos[MAX];
int main()
{
	int n,i,q,op,a,b;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		id[i]=i;
		now[i]=i;
		pos[i]=i;
	}
	while(q--)
	{
		scanf("%d%d",&op,&a);
		if(op==1||op==2) scanf("%d",&b);
		if(op==1) now[a]=pos[b];
		else if(op==2)
		{
			swap(id[pos[a]],id[pos[b]]);
			swap(pos[a],pos[b]);
		}
		else printf("%d\n",id[now[a]]);
	}
	return 0;
}
