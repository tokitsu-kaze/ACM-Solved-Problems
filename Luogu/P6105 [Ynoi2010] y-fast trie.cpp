#include <bits/stdc++.h>
using namespace std;
int mod;
map<int,int> mp,lk;
multiset<int> s;
void match(int x)
{
	auto it=mp.upper_bound(mod-1-x);
	if(it==mp.begin()) return;
	it--;
	int y=(*it).first;
	if(lk.count(y))
	{
		if(y+lk[y]<=x+y)
		{
			s.erase(s.find(y+lk[y]));
			lk.erase(lk[y]);
			lk[y]=x;
			lk[x]=y;
			s.insert(x+y);
		}
	}
	else
	{
		lk[x]=y;
		lk[y]=x;
		s.insert(x+y);
	}
}
void del(int x)
{
	if(mp[x]==1) mp.erase(x);
	else mp[x]--;
	if(mp.count(x) && mp[x]>=2) return;
	if(!lk.count(x)) return;
	if(mp.count(x) && lk[x]!=x) return;
	int y=lk[x];
	s.erase(s.find(x+y));
	lk.erase(x);
	lk.erase(y);
	if(mp[y]==1) mp.erase(y);
	else mp[y]--;
	match(y);
	mp[y]++;
}
void ins(int x)
{
	if(mp.count(x) && mp[x]>=2)
	{
		mp[x]++;
		return;
	}
	if(lk.count(x))
	{
		s.erase(s.find(x+lk[x]));
		lk.erase(lk[x]);
		lk.erase(x);
	}
	match(x);
	mp[x]++;
}
int ask()
{
	if(mp.size()==0) return -1;
	int res=-1;
	if(s.size()>0) res=*s.rbegin();
	auto it=--mp.end();
	if((*it).second==1)
	{
		if(mp.size()==1) return res;
		auto it2=it;
		it2--;
		res=max(res,((*it).first+(*it2).first)%mod);
	}
	else res=max(res,((*it).first+(*it).first)%mod);
	return res;
}
int main()
{
	int n,op,x,i,lst,ans;
	scanf("%d%d",&n,&mod);
	mp.clear();
	lk.clear();
	s.clear();
	lst=0;
	while(n--)
	{
		scanf("%d%d",&op,&x);
		x^=lst;
		x%=mod;
//		cout<<"true x: "<<x<<endl;
		if(op==1) ins(x);
		else del(x);
		ans=ask();
		if(ans==-1)
		{
			puts("EE");
			lst=0;
		}
		else printf("%d\n",lst=ans);
//		cout<<"link begin"<<endl;
//		for(auto &it:lk) cout<<it.first<<" "<<it.second<<endl;
//		cout<<"link end\n"<<endl;
	}
	return 0;
}
