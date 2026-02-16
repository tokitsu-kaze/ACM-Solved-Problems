#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int fa[MAX],col[MAX],tot,ck;
vector<int> mp[MAX];
void dfsck(int x,int h)
{
	for(auto &to:mp[x]) dfsck(to,h+1);
	if(mp[x].size()==1) ck|=(1<<(h&1));
}
void dfscol2(int x,int c)
{
	col[x]=c+1;
	for(auto &to:mp[x]) dfscol2(to,c^1);
}
void dfscol3(int x,int c)
{
	col[x]=c+1;
	for(auto &to:mp[x]) dfscol3(to,(c+1)%3);
}
int main()
{
	int n,i,op,cnt[5],cnt1,pos1,cnt0,pos0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		mp[fa[i]].push_back(i);
	}
	if(mp[1].size()==n-1)
	{
		tot=1;
		for(i=2;i<=n;i++) col[i]=1;
	}
	else
	{
		tot=2;
		for(auto &to:mp[1])
		{
			ck=0;
			dfsck(to,0);
			if(ck==3)
			{
				tot=3;
				break;
			}
			if(ck==2) dfscol2(to,1);
			else dfscol2(to,0);
		}
		if(tot==3) dfscol3(1,0);
	}
	printf("%d\n",tot);
	for(i=2;i<=n;i++) printf("%d%c",col[i]," \n"[i==n]);
	fflush(stdout);
	while(1)
	{
		scanf("%d",&op);
		if(op==1) break;
		assert(op!=-1);
		cnt0=cnt1=0;
		for(i=1;i<=tot;i++)
		{
			scanf("%d",&cnt[i]);
			if(cnt[i]==1)
			{
				cnt1++;
				pos1=i;
			}
			else if(cnt[i]==0)
			{
				cnt0++;
				pos0=i;
			}
		}
		if(tot==1) printf("%d\n",1);
		else if(tot==2)
		{
			if(cnt1==1) printf("%d\n",pos1);
			else printf("%d\n",1);
		}
		else
		{
			if(cnt0==1) printf("%d\n",pos0+1>3?pos0+1-3:pos0+1);
			else printf("%d\n",pos1);
		}
		fflush(stdout);
	}
	return 0;
}
/*
先考虑链的情况，发现按深度染色答案为3是可行的，进而发现答案<=3。考虑答案=1的情况，是菊花。现在问题转化成如何判断和构造答案=2。
答案为2时，一个点如果只有一种颜色，肯定往这种颜色走；否则肯定有两种颜色。考虑按深度染色后，如果儿子个数不为1，肯定走颜色数为1的边；
但如果儿子个数为1，那就不知道往哪走了。但此时，如果儿子个数为1的点的深度奇偶性相同，可以钦定往什么颜色走。
最后有一个特殊情况，根节点的儿子边不需要相同，因为走到根就直接成功了。所以对于根连接的子树分开处理。
实现时可以钦定 儿子个数为1时，走颜色1 
*/
