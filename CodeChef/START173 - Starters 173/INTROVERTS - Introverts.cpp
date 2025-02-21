#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int pos[MAX],a[MAX];
int main()
{
	int T,n,i,ok,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		map<int,set<int>> mp;
		set<int> s;
		mp[INF].insert(1);
		mp[INF].insert(n);
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(mp.size()==0)
			{
				ok=0;
				break;
			}
			auto &nex=(*mp.rbegin()).second;
/*			cout<<((*mp.rbegin()).first)<<endl;
			for(auto &it:nex) printf("%d ",it);
			puts("");*/
			if(nex.count(pos[i]))
			{
				if(s.size()>=2)
				{
					auto it=s.lower_bound(pos[i]);
					y=*it;
					it--;
					x=*it;
					mp[(y-x)/2].erase((x+y)/2);
					mp[(y-x)/2].erase((x+y+1)/2);
					if(mp[(y-x)/2].size()==0) mp.erase((y-x)/2);
				}
				else
				{
					nex.erase(pos[i]);
					if(nex.size()==0) mp.erase((*mp.rbegin()).first);
				}
				s.insert(pos[i]);
				if(s.size()>=2)
				{
					auto it=s.lower_bound(pos[i]);
					if(it!=s.end())
					{
						x=pos[i];
						it++;
						y=*it;
						mp[(y-x)/2].insert((x+y)/2);
						mp[(y-x)/2].insert((x+y+1)/2);
					}
					it=s.lower_bound(pos[i]);
					if(it!=s.begin())
					{
						it--;
						x=*it;
						y=pos[i];
						mp[(y-x)/2].insert((x+y)/2);
						mp[(y-x)/2].insert((x+y+1)/2);
					}
				}
			}
			else
			{
				ok=0;
				break;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8
x     o       x
*/
