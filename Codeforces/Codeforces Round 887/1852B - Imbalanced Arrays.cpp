#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int res[MAX];
int main()
{
	int T,n,i,cnt,x,pos,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		set<pair<int,int>> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s.insert({x,i});
		}
		cnt=0;
		ok=1;
		for(i=n;i;i--)
		{
			auto itr=*s.rbegin();
			x=itr.first;
			pos=itr.second;
			if(x==i+cnt)
			{
				res[pos]=i;
				cnt++;
				s.erase(itr);
				continue;
			}
			auto itl=*s.begin();
			x=itl.first;
			pos=itl.second;
			if(x==cnt)
			{
				res[pos]=-i;
				s.erase(itl);
				continue;
			}
			ok=0;
			break;
		}
		if(ok)
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
		}
		else puts("NO");
	}
	return 0;
}
