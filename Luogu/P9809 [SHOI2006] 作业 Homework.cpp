#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int limt=500;
bool f[limt][limt];
int main()
{
	int n,i,x,ans,ok;
	char op[2];
	scanf("%d",&n);
	memset(f,0,sizeof f);
	set<int> s;
	s.insert(-INF);
	s.insert(INF);
	while(n--)
	{
		scanf("%s%d",op,&x);
		if(op[0]=='A')
		{
			for(i=1;i<limt;i++) f[i][x%i]=1;
			s.insert(x);
		}
		else
		{
			ans=x;
			if(x<limt)
			{
				for(i=0;i<x;i++)
				{
					if(f[x][i])
					{
						ans=i;
						break;
					}
				}
			}
			else
			{
				ok=1;
				for(i=0;ok;i+=x)
				{
					auto it=s.lower_bound(i);
					if(*it!=INF) ans=min(ans,*it%x);
					else ok=0;
					it--;
					if(*it!=-INF) ans=min(ans,*it%x);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
