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
const int N=55;
char a[MAX],b[MAX];
int in[N],vis[N],id[128];
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
	int T,n,i,ok,ans,f;
	memset(id,0,sizeof id);
	for(i='a';i<='z';i++) id[i]=i-'a'+1;
	for(i='A';i<='Z';i++) id[i]=i-'A'+1+26;
	scanf("%d",&T);
	while(T--)
	{
		for(i=1;i<=52;i++)
		{
			mp[i].clear();
			revmp[i].clear();
			in[i]=flag[i]=tag[i]=vis[i]=0;
		}
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1);
		map<pair<int,int>,int> ha;
		for(i=1;i<=n;i++)
		{
			vis[id[b[i]]]=1;
			if(a[i]==b[i])
			{
				tag[id[a[i]]]=1;
				continue;
			}
			if(ha.count({id[a[i]],id[b[i]]})) continue;
			ha[{id[a[i]],id[b[i]]}]=1;
			mp[id[a[i]]].push_back(id[b[i]]);
			in[id[b[i]]]++;
			revmp[id[b[i]]].push_back(id[a[i]]);
		}
		ok=1;
		f=0;
		for(i=1;i<=52;i++)
		{
			if(mp[i].size()>1) ok=0;
			if(mp[i].size()>0 && tag[i]) ok=0;
			if(!vis[i]) f++;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		vector<int> res=topsort(52,mp,in);
		for(auto &it:res) flag[it]=1;
		ans=ha.size();
		for(i=1;i<=52;i++)
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
	}
	return 0;
}
/*
abc399_e

abcz
bcab
*/
