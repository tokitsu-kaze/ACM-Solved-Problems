#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],d[MAX];
int main()
{
	int T,n,m,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		map<int,int> mp;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[i]) mp[b[i]]++;
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&d[i]);
			if(mp.count(d[i]))
			{
				mp[d[i]]--;
				if(mp[d[i]]==0) mp.erase(d[i]);
			}
		}
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(d[m]==b[i]) ok=1;
		}
		if(mp.size()==0 && ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
