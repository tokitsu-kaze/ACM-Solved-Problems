#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],pos[MAX];
int main()
{
	int n,q,i,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		pos[a[i]]=i;
	}
	while(q--)
	{
		scanf("%d",&x);
		x=pos[x];
		if(x+1>n)
		{
			if(x-1>0)
			{
				swap(a[x],a[x-1]);
				pos[a[x]]=x;
				pos[a[x-1]]=x-1;
			}
		}
		else
		{
			swap(a[x],a[x+1]);
			pos[a[x]]=x;
			pos[a[x+1]]=x+1;
		}
	}
	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}
