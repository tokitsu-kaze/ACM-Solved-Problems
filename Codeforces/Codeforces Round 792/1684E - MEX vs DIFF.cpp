#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,mex,k,x,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		map<int,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
		}
		now=0;
		mex=0;
		while(now<=k && mex<n)
		{
			if(!mp.count(mex)) now++;
			mex++;
		}
		vector<pair<int,int>> res;
		for(auto &it:mp)
		{
			if(it.first>=mex)
			{
				res.push_back({it.second,it.first});
			}
		}
		sort(res.begin(),res.end());
		for(auto &it:res)
		{
			if(k-it.first>=0)
			{
				k-=it.first;
				mp.erase(it.second);
			}
			else
			{
				k=0;
				mp[it.second]-=k;
				break;
			}
		}
		for(i=0;i<mex;i++)
		{
			if(!mp.count(i)) mp[i]=1;
		}
//		for(auto &it:mp) cout<<it.first<<endl;
		printf("%d\n",mp.size()-mex);
	}
	return 0;
}
/*
1
5 1
0 1 2 3 5
*/
