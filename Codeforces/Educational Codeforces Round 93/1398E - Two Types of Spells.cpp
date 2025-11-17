#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,tp,d,cnt,x,y,nx,ny;
	ll ans;
	scanf("%d",&n);
	ans=0;
	cnt=0;
	set<int> s[2],now[2];
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&tp,&d);
		if(d>0) cnt+=tp;
		else cnt-=tp;
		ans+=d;
		if(d<0)
		{
			if(s[tp].count(-d)) s[tp].erase(-d);
			else
			{
				now[tp].erase(-d);
				ans+=d;
			}
		}
		else s[tp].insert(d);
		
		if(s[1].size()==0 && now[1].size()>0)
		{
			y=*now[1].begin();
			ans-=y;
			now[1].erase(y);
			s[1].insert(y);
		}
		
		while(now[0].size()+now[1].size()<cnt)
		{
			if(s[0].size()>0) x=*s[0].rbegin();
			else x=-1;
			if(s[1].size()>1) y=*s[1].rbegin();
			else y=-1;
			if(max(x,y)==-1) break;
			ans+=max(x,y);
			if(x>y)
			{
				s[0].erase(x);
				now[0].insert(x);
			}
			else
			{
				s[1].erase(y);
				now[1].insert(y);
			}
		}
		while(now[0].size()+now[1].size()>cnt)
		{
			if(now[0].size()>0) nx=*now[0].begin();
			else nx=2e9;
			if(now[1].size()>0) ny=*now[1].begin();
			else ny=2e9;
			if(min(nx,ny)==2e9) break;
			ans-=min(nx,ny);
			if(nx<ny)
			{
				now[0].erase(nx);
				s[0].insert(nx);
			}
			else
			{
				now[1].erase(ny);
				s[1].insert(ny);
			}
		}
		
		while(1)
		{
			if(now[0].size()>0) nx=*now[0].begin();
			else nx=2e9;
			if(now[1].size()>0) ny=*now[1].begin();
			else ny=2e9;
			
			if(s[0].size()>0) x=*s[0].rbegin();
			else x=-1;
			if(s[1].size()>0) y=*s[1].rbegin();
			else y=-1;
			
			if(min(nx,ny)>=max(x,y)) break;
			if(nx<x)
			{
				now[0].erase(nx);
				now[0].insert(x);
				s[0].erase(x);
				s[0].insert(nx);
				ans+=x-nx;
			}
			else if(ny<y)
			{
				now[1].erase(ny);
				now[1].insert(y);
				s[1].erase(y);
				s[1].insert(ny);
				ans+=y-ny;
			}
			else if(ny<x)
			{
				now[1].erase(ny);
				now[0].insert(x);
				s[0].erase(x);
				s[1].insert(ny);
				ans+=x-ny;
			}
			else if(nx<y)
			{
				if(s[1].size()==1) break;
				now[0].erase(nx);
				now[1].insert(y);
				s[1].erase(y);
				s[0].insert(nx);
				ans+=y-nx;
			}
			else break;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
/*
选最大的 x 个翻倍，x为 雷 的个数。
雷留一个，不能翻倍 
*/
