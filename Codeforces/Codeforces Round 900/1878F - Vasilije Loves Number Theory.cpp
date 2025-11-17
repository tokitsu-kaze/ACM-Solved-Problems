#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
map<int,int> gao(int x)
{
	int i,sq;
	sq=sqrt(x+0.5);
	map<int,int> res;
	for(i=2;i<=sq;i++)
	{
		while(x%i==0)
		{
			x/=i;
			res[i]++;
		}
	}
	if(x>1) res[x]++;
	return res;
}
int main()
{
	int T,n,q,op,x,i;
	ll cnt,newn;
	scanf("%d",&T);
	while(T--)
	{
		map<int,int> now,tmp;
		scanf("%d%d",&n,&q);
		now=gao(n);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d",&x);
				tmp=gao(x);
				for(auto &it:tmp) now[it.first]+=it.second;
				cnt=1;
				for(auto &it:now) cnt*=(it.second+1);
				newn=1;
				for(auto &it:now)
				{
					for(i=0;i<it.second;i++)
					{
						newn=newn*it.first%cnt;
					}
				}
				newn%=cnt;
				if(newn==0) puts("YES");
				else puts("NO");
			}
			else now=gao(n);
		}
	}
	return 0;
}
