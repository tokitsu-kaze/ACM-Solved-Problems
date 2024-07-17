#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int flag[55];
int main()
{
	int t,m,s,i,x,ok,mx;
	scanf("%d",&t);
	while(t--)
	{
		memset(flag,0,sizeof flag);
		scanf("%d%d",&m,&s);
		mx=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			flag[x]++;
			mx=max(mx,x);
		}
		ok=1;
		for(i=1;i<=mx;i++)
		{
			if(flag[i]>1) ok=0;
			if(flag[i]==0) s-=i;
		}
		if(s<0) ok=0;
		while(s>0)
		{
			mx++;
			s-=mx;
		}
		if(s!=0) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
