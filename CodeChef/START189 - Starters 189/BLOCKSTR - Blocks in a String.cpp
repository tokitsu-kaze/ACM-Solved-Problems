#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int cnt,tp,val;
	/*
	
	tp=0  尽可能填 1，cnt 小的在前
	1?1
	?1 / 1?
	
	tp=1
	0?1 / 1?0 -> 2  无所谓
	
	tp=2  尽可能填 0，cnt 大的在前
	0?0 -> 1
	?0 / 0?
	
	*/
};
char s[MAX];
int ans[MAX];
int main()
{
	int T,n,i,j,mn1,mx1,pre,now,nowans,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		pre=-1;
		nowans=now=mn1=mx1=0;
		vector<node> res;
		s[0]='\0';
		for(i=1;i<=n;i++)
		{
			if(s[i]=='?')
			{
				now++;
				mx1++;
				s[i]='0';
				if(s[i]!=s[i-1]) nowans++;
			}
			else
			{
				if(s[i]!=s[i-1]) nowans++;
				if(s[i]=='1')
				{
					mn1++;
					mx1++;
				}
				if(now)
				{
					if(pre==-1)
					{
						if(s[i]=='1') res.push_back({now,0,-1});
						else res.push_back({now,2,1});
					}
					else if(pre==s[i])
					{
						if(s[i]=='1') res.push_back({now,0,-2});
						else res.push_back({now,2,2});
					}
					else res.push_back({now,1,0});
					now=0;
				}
				pre=s[i];
			}
		}
		if(now)
		{
			if(pre=='1') res.push_back({now,0,-1});
			else res.push_back({now,2,1});
		}
		sort(res.begin(),res.end(),[](node x,node y){
			if(x.tp!=y.tp) return x.tp<y.tp;
			if(x.tp==0)
			{
				if(x.cnt==y.cnt) return x.val<y.val;
				return x.cnt<y.cnt;
			}
			else if(x.tp==2)
			{
				if(x.cnt==y.cnt) return x.val<y.val;
				return x.cnt>y.cnt;
			}
			else return x.cnt<y.cnt;
		});
		now=0;
		for(i=0,j=0;i<=n;i++)
		{
			if(i<mn1 || i>mx1) ans[i]=-1;
			else
			{
				if(j<res.size() && res[j].tp==0)
				{
					if(now==res[j].cnt) nowans+=res[j].val;
				}
				else if(j<res.size() && res[j].tp==2)
				{
					if(now==1) nowans+=res[j].val;
				}
				if(j<res.size() && now==res[j].cnt)
				{
					j++;
					now=0;
				}
				ans[i]=nowans;
				now++;
			}
			printf("%d%c",ans[i]," \n"[i==n]);
		}
	}
	return 0;
}
