#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int l[MAX],r[MAX],now[MAX];
int main()
{
	int t,n,i,j,ans,ok,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			now[i]=l[i];
		}
		ans=0;
		for(j=30;~j;j--)
		{
			ok=1;
			for(i=1;i<=n;i++)
			{
				tmp=(now[i]-(now[i]&((1<<j)-1)))|(1<<j);
				if(tmp>r[i]) ok=0;
			}
			if(ok)
			{
				ans|=(1<<j);
				for(i=1;i<=n;i++)
				{
					if((now[i]|(1<<j))>r[i]) now[i]-=(now[i]&((1<<j)-1));
					now[i]|=(1<<j);
				}
			}
			else
			{
				for(i=1;i<=n;i++)
				{
					if(!((now[i]>>j)&1)) continue;
					tmp=(now[i]-(1<<j))|(now[i]&((1<<j)-1));
					if(tmp>=l[i]) now[i]=tmp;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

