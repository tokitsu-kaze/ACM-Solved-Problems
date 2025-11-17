#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int id[MAX],n,vis[MAX];
int work(int len)
{
	int i,j,pos,mn;
	vector<int> now;
	for(i=1;i<=n;i++)
	{
		if(mp[id[i]].size()>=len && !vis[id[i]]) now.push_back(id[i]);
	}
	while(now.size()>1)
	{
		vector<int> tmp;
		mn=INF;
		for(auto &it:now)
		{
			if(mp[it].size()<len) return it;
			mn=min(mn,mp[it][len-1]);
		}
		for(auto &it:now)
		{
			if(mp[it].size()<len) continue;
			if(mp[it][len-1]==mn) tmp.push_back(it);
		}
		if(tmp.size()==0) break;
		swap(tmp,now);
		len++;
	}
	return now[0];
}
int main()
{
	int T,i,j,k,pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			mp[i].resize(k);
			for(auto &it:mp[i]) scanf("%d",&it);
			id[i]=i;
			vis[i]=0;
		}
		sort(id+1,id+1+n,[&](int x,int y){
			return mp[x].size()>mp[y].size();
		});
		vector<int> res;
		for(i=1;i<=mp[id[1]].size();i++)
		{
			if(res.size()>=i) continue;
			pos=work(i);
			vis[pos]=1;
			for(j=i-1;j<mp[pos].size();j++) res.push_back(mp[pos][j]);
		}
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
/*
2
4
3 2 2 2
3 3 2 1
2 2 1
1 1
3
3 1 1 2
3 2 1 1
1 1
*/
