#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
struct node{int to,w;};
vector<node> mp[MAX];
struct op{int x,y,w;};
vector<op> res;
int leaf[MAX][2],nowval[MAX],rt;
void dfs0(int x,int fa)
{
	int to;
	for(auto &it:mp[x])
	{
		to=it.to;
		if(to==fa) continue;
		dfs0(to,x);
		if(!leaf[x][0]) leaf[x][0]=leaf[to][0];
		else if(!leaf[x][1]) leaf[x][1]=leaf[to][0];
	}
	if(x!=rt && mp[x].size()==1) leaf[x][0]=x;
}
void dfs(int x,int fa)
{
	int to;
	for(auto &it:mp[x])
	{
		to=it.to;
		if(to==fa) continue;
		nowval[to]=it.w;
		dfs(to,x);
		if(leaf[to][0] && leaf[to][1])
		{
			res.push_back({rt,leaf[to][0],nowval[to]/2});
			res.push_back({rt,leaf[to][1],nowval[to]/2});
			res.push_back({leaf[to][0],leaf[to][1],-nowval[to]/2});
		}
		nowval[x]-=it.w;
	}
	if(x!=rt && mp[x].size()==1) res.push_back({rt,x,nowval[x]});
}
int main()
{
	int n,i,a,b,c,ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		leaf[i][0]=leaf[i][1]=0;
		nowval[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	ok=1;
	rt=1;
	for(i=1;i<=n;i++)
	{
		if(mp[i].size()==1) rt=i;
		if(mp[i].size()==2) ok=0;
	}
	if(!ok) return 0*puts("NO");
	dfs0(rt,0);
	res.clear();
	dfs(rt,0);
	puts("YES");
	printf("%d\n",(int)res.size());
	for(auto &it:res) printf("%d %d %d\n",it.x,it.y,it.w);
	return 0;
}
/*
如果能够发现无解条件，后面就简单了。
如果一个点度数为 2，那么这个点相邻的两条边一定是一起操作的。
题目保证是互不相同的偶数，所以如果有度数为 2 的点就是无解的。
那么度数>=3的话，说明一定有 3 个叶子。
那么以一个叶子为根，操作 2 次根到叶子，每次 val/2；
再操作一次两个叶子，每次 -val/2，就ok了。
*/
