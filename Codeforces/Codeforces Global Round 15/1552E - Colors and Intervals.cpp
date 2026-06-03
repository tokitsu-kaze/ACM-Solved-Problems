#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
vector<int> pos[MAX];
struct node{int l,r,col;} ans[MAX];
int vis[MAX];
int main()
{
	int n,k,i,j,x,now;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		pos[i].clear();
		vis[i]=0;
	}
	for(i=1;i<=n*k;i++)
	{
		scanf("%d",&x);
		pos[x].push_back(i);
	}
	x=1;
	while(x<=n)
	{
		vector<node> res;
		for(i=x;i<=min(n,x+k-2);i++)
		{
			for(j=1;j<pos[i].size();j++)
			{
				res.push_back({pos[i][j-1],pos[i][j],i});
			}
		}
		sort(res.begin(),res.end(),[](node x,node y){
			return x.r<y.r;
		});
		now=0;
		for(auto &it:res)
		{
			if(vis[it.col]) continue;
			if(it.l>now)
			{
				now=it.r;
				ans[it.col]=it;
				vis[it.col]=1;
			}
		}
		x+=k-1;
	}
	for(i=1;i<=n;i++) printf("%d %d\n",ans[i].l,ans[i].r);
	return 0;
}
/*
感觉有点神秘。
每k-1颜色分组，每一组覆盖序列最多1次，这样就是覆盖不超过n/(k-1)次。
会发现同色选相邻不劣，每种颜色有k-1种选择。
可以证明每一组，每种颜色都能选出至少一个线段。
然后就做完了。
*/
