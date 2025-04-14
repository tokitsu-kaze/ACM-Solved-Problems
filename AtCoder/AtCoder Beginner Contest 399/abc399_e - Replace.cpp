#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	return toplist;
}
const int N=33;
char a[MAX],b[MAX];
int in[N],vis[N];
vector<int> mp[N],revmp[N],cir;
int flag[N],tag[N];
void dfs(int x)
{
	if(flag[x]) return;
	flag[x]=1;
	cir.push_back(x);
	for(auto &to:mp[x]) dfs(to);
}
int main()
{
	int n,i,ok,ans,f;
	scanf("%d",&n);
	for(i=1;i<=26;i++)
	{
		mp[i].clear();
		revmp[i].clear();
		in[i]=flag[i]=tag[i]=vis[i]=0;
	}
	scanf("%s%s",a+1,b+1);
	map<pair<int,int>,int> ha;
	for(i=1;i<=n;i++)
	{
		vis[b[i]-'a'+1]=1;
		if(a[i]==b[i])
		{
			tag[a[i]-'a'+1]=1;
			continue;
		}
		if(ha.count({a[i]-'a'+1,b[i]-'a'+1})) continue;
		ha[{a[i]-'a'+1,b[i]-'a'+1}]=1;
		mp[a[i]-'a'+1].push_back(b[i]-'a'+1);
		in[b[i]-'a'+1]++;
		revmp[b[i]-'a'+1].push_back(a[i]-'a'+1);
	}
	ok=1;
	f=0;
	for(i=1;i<=26;i++)
	{
		if(mp[i].size()>1) ok=0;
		if(mp[i].size()>0 && tag[i]) ok=0;
		if(!vis[i]) f++;
	}
	if(!ok) return 0*puts("-1");
	vector<int> res=topsort(26,mp,in);
	for(auto &it:res) flag[it]=1;
	ans=ha.size();
	for(i=1;i<=26;i++)
	{
		if(flag[i]) continue;
		if(mp[i].size()==0) continue;
		if(f==0) ok=0;
		cir.clear();
		dfs(i);
		ans++;
		for(auto &it:cir)
		{
			if(revmp[it].size()>1)
			{
				ans--;
				ok=1;
				break;
			}
		}
		if(!ok) break;
	}
	if(!ok) ans=-1;
	printf("%d\n",ans);
	return 0;
}
/*
4
abcz
bcab
*/
