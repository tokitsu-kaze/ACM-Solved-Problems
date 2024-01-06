#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int lst[MAX],pre[MAX],premx[MAX];
int main()
{
	int n,q,i,x,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) lst[i]=0;
	premx[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(lst[x]) pre[i]=lst[x];
		else pre[i]=0;
		premx[i]=max(pre[i],premx[i-1]);
		lst[x]=i;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(premx[r]>=l) puts("No");
		else puts("Yes");
	}
	return 0;
}
