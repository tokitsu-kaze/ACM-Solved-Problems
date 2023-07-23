#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int flag[MAX],v[MAX];
int main()
{
	int n,m,op,l,r,sum,ans,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		flag[i]=1;
		v[i]=0;
	}
	sum=0;
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==0)
		{
			for(i=l;i<=r;i++)
			{
				sum+=v[i];
				flag[i]=v[i]=0;
			}
		}
		else
		{
			for(i=l;i<=r;i++)
			{
				if(!flag[i]&&!v[i])
				{
					flag[i]=v[i]=1;
				}
			}
		}
	}
	ans=0;
	for(i=0;i<=n;i++) ans+=v[i];
	printf("%d\n",ans);
	printf("%d\n",sum);
	return 0;
}
