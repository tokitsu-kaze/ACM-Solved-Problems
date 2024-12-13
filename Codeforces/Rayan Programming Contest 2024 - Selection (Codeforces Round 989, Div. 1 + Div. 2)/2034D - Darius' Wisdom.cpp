#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
set<int> pos[3];
int a[MAX],b[MAX];
int main()
{
	int T,n,i,cnt[3];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(i=0;i<3;i++) pos[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
			cnt[a[i]]++;
			pos[a[i]].insert(i);
		}
		vector<pair<int,int>> res;
		for(i=1;i<=cnt[0];i++)
		{
			if(a[i]==0) continue;
			pos[a[i]].erase(i);
			if(a[i]==1)
			{
				res.push_back({i,*pos[0].rbegin()});
				a[*pos[0].rbegin()]=1;
				pos[1].insert(*pos[0].rbegin());
				pos[0].erase(*pos[0].rbegin());
				
				a[i]=0;
			}
			else
			{
				res.push_back({i,*pos[1].rbegin()});
				a[*pos[1].rbegin()]=2;
				pos[2].insert(*pos[1].rbegin());
				pos[1].erase(*pos[1].rbegin());
				
				res.push_back({i,*pos[0].rbegin()});
				a[*pos[0].rbegin()]=1;
				pos[1].insert(*pos[0].rbegin());
				pos[0].erase(*pos[0].rbegin());
				
				a[i]=0;
			}
		}
		for(i=cnt[0]+cnt[1]+1;i<=n;i++)
		{
			if(a[i]==2) continue;
			assert(a[i]==1);
			res.push_back({i,*pos[2].begin()});
			a[*pos[2].begin()]=1;
			pos[2].erase(*pos[2].begin());
		}
		printf("%d\n",res.size());
		assert(res.size()<=n);
		for(auto &it:res)
		{
			printf("%d %d\n",it.first,it.second);
			assert(abs(b[it.first]-b[it.second])==1);
			swap(b[it.first],b[it.second]);
		}
		for(i=2;i<=n;i++) assert(b[i]>=b[i-1]);
	}
	return 0;
}
/*
1
4
1 2 0 0
*/
