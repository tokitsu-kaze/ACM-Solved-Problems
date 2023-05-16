#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,op,x,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		set<int> s;
		for(i=1;i<=n;i++) s.insert(i);
		ans=-1;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&op,&x);
			if(op==1) s.erase(x);
			else
			{
				if(!s.count(x) && ans==-1) ans=i;
				s.clear();
				s.insert(x);
			}
			if(s.size()==0 && ans==-1) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
