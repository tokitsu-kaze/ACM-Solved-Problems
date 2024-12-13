#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int main()
{
	int q,op,x,cnt[33],now[33],i,j,tmp,need,ok;
	scanf("%d",&q);
	memset(cnt,0,sizeof cnt);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1) cnt[x]++;
		else
		{
			ok=1;
			for(i=0;i<=30;i++) now[i]=cnt[i];
			for(i=30;~i;i--)
			{
				if(!((x>>i)&1)) continue;
				need=1;
				for(j=i;~j;j--)
				{
					tmp=min(need,now[j]);
					need-=tmp;
					now[j]-=tmp;
					need*=2;
					if(need>1e6) break;
				}
				if(need)
				{
					ok=0;
					break;
				}
			}
			if(ok) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
