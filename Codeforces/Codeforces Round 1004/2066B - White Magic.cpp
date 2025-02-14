#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
int ck(vector<int> v)
{
	int i,n,mex;
	n=v.size();
	vector<int> premn(n,0);
	premn[0]=v[0];
	for(i=1;i<n;i++) premn[i]=min(premn[i-1],v[i]);
	set<int> s;
	mex=0;
	for(i=n-1;i;i--)
	{
		s.insert(v[i]);
		while(s.count(mex)) mex++;
		if(premn[i-1]<mex) return 0;
	}
	return 1;
}
int main()
{
	int T,n,i,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> a(n);
		for(auto &it:a) scanf("%d",&it);
		if(ck(a))
		{
			printf("%d\n",n);
			continue;
		}
		vector<int> tmp;
		f=0;
		for(auto &it:a)
		{
			if(it==0)
			{
				if(!f)
				{
					tmp.push_back(it);
					f=1;
				}
			}
			else tmp.push_back(it);
		}
		if(ck(tmp))
		{
			printf("%d\n",(int)tmp.size());
			continue;
		}
		tmp.clear();
		reverse(a.begin(),a.end());
		f=0;
		for(auto &it:a)
		{
			if(it==0)
			{
				if(!f)
				{
					tmp.push_back(it);
					f=1;
				}
			}
			else tmp.push_back(it);
		}
		reverse(a.begin(),a.end());
		reverse(tmp.begin(),tmp.end());
		if(ck(tmp))
		{
			printf("%d\n",(int)tmp.size());
			continue;
		}
		printf("%d\n",(int)tmp.size()-1);
	}
	return 0;
}
