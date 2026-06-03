#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int pre[MAX],nex[MAX];
int main()
{
	int n,q,i,x,y,cnt;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) pre[i]=nex[i]=i;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(pre[x]!=x) nex[pre[x]]=pre[x];
		pre[x]=y;
		nex[y]=x;
	}
	for(i=1;i<=n;i++)
	{
		if(pre[i]!=i)
		{
			printf("0%c"," \n"[i==n]);
			continue;
		}
		cnt=0;
		x=i;
		while(1)
		{
			cnt++;
			if(x==nex[x]) break;
			x=nex[x];
		}
		printf("%d%c",cnt," \n"[i==n]);
	}
	return 0;
}
