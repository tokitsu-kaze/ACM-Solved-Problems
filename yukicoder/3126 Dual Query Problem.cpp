#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int op,p,x;};
int main()
{
	int n,q,i,x,tot;
	scanf("%d%d",&n,&q);
	vector<node> res;
	map<int,int> mp;
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(mp.count(x)) res.push_back({2,mp[x],0});
		else
		{
			mp[x]=++tot;
			res.push_back({1,mp[x],x});
			res.push_back({2,mp[x],0});
		}
	}
	if(res.size()>q) puts("No");
	else
	{
		while(res.size()<q) res.push_back({1,1,1});
		puts("Yes");
		for(auto &it:res)
		{
			printf("%d %d",it.op,it.p);
			if(it.op==1) printf(" %d",it.x);
			puts("");
		}
	}
	return 0;
}
