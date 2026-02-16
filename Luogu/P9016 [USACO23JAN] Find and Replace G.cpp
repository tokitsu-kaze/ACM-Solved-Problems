#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+30;
int now_id[26],tot;
vector<int> mp[MAX];
char s[3],t[MAX],ha[MAX],ans[MAX];
int dl[MAX],dr[MAX];
ll sz[MAX],l,r;
void newnode(char x)
{
	now_id[x-'a']=++tot;
	ha[tot]=x;
	mp[tot].clear();
	sz[tot]=-1;
	dl[tot]=dr[tot]=-1;
}
void dfs0(int x)
{
	if(sz[x]!=-1) return;
	sz[x]=0;
	for(auto &to:mp[x])
	{
		dfs0(to);
		sz[x]+=sz[to];
		sz[x]=min(sz[x],(ll)1e18);
	}
}
void dfs(int x,ll now)
{
	if(now+sz[x]<l) return;
	if(now+1>r) return;
	if(mp[x].size()==0)
	{
		if(l<=now+1 && now+1<=r) ans[++tot]=ha[x];
		return;
	}
	if(dr[x]!=-1 && dr[x]-dl[x]==sz[x])
	{
		for(int i=dl[x]+1;i<=dr[x];i++)
		{
			if(tot==r-l+1) return;
			ans[++tot]=ans[i];
		}
		return;
	}
	if(dl[x]==-1) dl[x]=tot;
	for(auto &to:mp[x])
	{
		if(now>r) return;
		dfs(to,now);
		now+=sz[to];
		now=min(now,(ll)2e18);
	}
	if(dr[x]==-1) dr[x]=tot;
}
int main()
{
	int n,len,i,id,rt;
	scanf("%lld%lld%d",&l,&r,&n);
	tot=0;
	for(i=0;i<26;i++) newnode(i+'a');
	rt=now_id[0];
	while(n--)
	{
		scanf("%s%s",s,t);
		id=now_id[s[0]-'a'];
		newnode(s[0]);
		len=strlen(t);
		for(i=0;i<len;i++) mp[id].push_back(now_id[t[i]-'a']);
	}
	for(i=0;i<26;i++) sz[now_id[i]]=1;
	dfs0(rt);
	tot=0;
	dfs(rt,0);
	ans[tot+1]='\0';
	puts(ans+1);
	return 0;
}
/*
考虑每次替换直接与 si 的所有字母连边。
有出边的字母需要新建一个节点。
维护一个now_id[26]表示当前每种字母的节点编号。
这样点的数量是操作次数，边的数量是O(sum{|si|})。 
发现 t 飞了是因为，一条链每次都走那么多边。
子树的答案一定是连续的一段，考虑记录子树对应答案哪一段， 
如果发现整个子树都记录过答案，不用往下递归，直接记录答案。
*/
