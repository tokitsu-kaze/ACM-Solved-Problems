#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX],ss[MAX];
int to[MAX],vis[MAX],st[MAX],top,in[MAX],incir[MAX];
vector<int> mp[MAX],leaf,cir,ans,ra,rb;
void dfs(int x,int fa)
{
	int i,f;
	if(vis[x]) return;
	vis[x]=2;
	st[top++]=x;
	f=0;
	for(auto &to:mp[x])
	{
		if(to==fa)
		{
			if(f==0)
			{
				f++;
				continue;
			}
		}
		if(vis[to]==2)
		{
			for(i=top-1;~i;i--)
			{
				cir.push_back(st[i]);
				incir[st[i]]=1;
				if(st[i]==to) break;
			}
		}
		else dfs(to,x);
	}
	top--;
	vis[x]=1;
	if(in[x]==0) leaf.push_back(x);
}
void dfs2(int x,int f)
{
	if(vis[x]) return;
	vis[x]=1;
	if(ss[x]=='1')
	{
		if(f==0) ra.push_back(x);
		else rb.push_back(x);
		ss[x]^=1;
		ss[to[x]]^=1;
	}
	dfs2(to[x],f);
}
int work(int x)
{
	int mn,cnt;
	top=0;
	leaf.clear();
	cir.clear();
	dfs(x,0);
	
	cnt=0;
	queue<int> q;
	for(auto &it:leaf) q.push(it);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(s[t]=='1')
		{
			cnt++;
			s[t]^=1;
			s[to[t]]^=1;
			ans.push_back(t);
		}
		in[to[t]]--;
		if(!in[to[t]]) q.push(to[t]);
	}
//	for(auto &it:cir) cout<<it<<" ";
//	puts("");
//	puts(s+1);
	int now=0;
	for(auto &it:cir)
	{
		now+=s[it]-'0';
		if(s[it]=='1') x=it;
	}
	if(now&1) return -1;
	ra.clear();
	for(auto &it:cir)
	{
		ss[it]=s[it];
		vis[it]=0;
	}
	dfs2(x,0);
	rb.clear();
	for(auto &it:cir)
	{
		ss[it]=s[it];
		vis[it]=0;
	}
	dfs2(to[x],1);
	if(ra.size()>rb.size()) swap(ra,rb);
	cnt+=ra.size();
	for(auto &it:ra) ans.push_back(it);
	
	return cnt;
}
int main()
{
	int T,n,i,ok,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			vis[i]=in[i]=incir[i]=0;
			mp[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&to[i]);
			in[to[i]]++;
			mp[i].push_back(to[i]);
			mp[to[i]].push_back(i);
		}
		ans.clear();
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			tmp=work(i);
			if(tmp==-1)
			{
				ok=0;
				break;
			}
		}
		if(!ok) puts("-1");
		else
		{
			printf("%d\n",ans.size());
			for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
		}
	}
	return 0;
}
