#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct node{int v,id;};
int ans[MAX];
int main()
{
	int t,n,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			res.push_back({x,i});
		}
		sort(res.begin(),res.end(),[&](node a,node b){
			return a.v<b.v;
		});
		for(i=0;i<n-1;i++) ans[res[i].id]=res[i].v-res[n-1].v;
		ans[res[n-1].id]=res[n-1].v-res[n-2].v;
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
