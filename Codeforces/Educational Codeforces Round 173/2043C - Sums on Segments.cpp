#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
int gao(vector<int> &res,int f)
{
	int mx,now;
	mx=now=0;
	for(auto &it:res)
	{
		now+=f*it;
		now=max(0,now);
		mx=max(mx,now);
	}
	return f*mx;
}
int gao2(vector<int> &res,int f)
{
	int mx,now;
	mx=now=0;
	for(auto &it:res)
	{
		now+=f*it;
		mx=max(mx,now);
	}
	return f*mx;
}
int main()
{
	int T,n,i,x,cnt,tmp,mn,mx,now,f,tt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> tmp[2];
		f=0;
		tt=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(abs(x)==1) tmp[f].push_back(x);
			else
			{
				f^=1;
				tt=x;
			}
		}
		set<int> s;
		s.insert(0);
		if(tmp[0].size()>0)
		{
			mn=gao(tmp[0],-1);
			mx=gao(tmp[0],1);
//			printf("%d %d\n",mn,mx);
			for(i=mn;i<=mx;i++) s.insert(i);
		}
		if(tmp[1].size()>0)
		{
			mn=gao(tmp[1],-1);
			mx=gao(tmp[1],1);
//			printf("%d %d\n",mn,mx);
			for(i=mn;i<=mx;i++) s.insert(i);
		}
		if(tt!=-1)
		{
			vector<int> revtmp0=tmp[0];
			reverse(revtmp0.begin(),revtmp0.end());
			mn=gao2(revtmp0,-1)+gao2(tmp[1],-1)+tt;
			mx=gao2(revtmp0,1)+gao2(tmp[1],1)+tt;
//			printf("%d %d\n",mn,mx);
			for(i=mn;i<=mx;i++) s.insert(i);
		}
		
		vector<int> ans;
		for(auto &it:s) ans.push_back(it);
		printf("%d\n",ans.size());
		for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	}
	return 0;
}

