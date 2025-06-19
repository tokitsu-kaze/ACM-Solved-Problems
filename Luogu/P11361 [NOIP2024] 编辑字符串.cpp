#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s1[MAX],s2[MAX],t1[MAX],t2[MAX];
int nex1[MAX],nex2[MAX],pre1[MAX],pre2[MAX];
set<int> p1[2],p2[2];
void myswap(int f,int x,int y)
{
	if(x==y) return;
//	cout<<f<<" "<<x<<" "<<y<<endl;
	if(f==1)
	{
		if(s1[x]==s1[y]) return;
		p1[s1[x]-'0'].erase(x);
		p1[s1[y]-'0'].erase(y);
		swap(s1[x],s1[y]);
		p1[s1[x]-'0'].insert(x);
		p1[s1[y]-'0'].insert(y);
	}
	else
	{
		if(s2[x]==s2[y]) return;
		p2[s2[x]-'0'].erase(x);
		p2[s2[y]-'0'].erase(y);
		swap(s2[x],s2[y]);
		p2[s2[x]-'0'].insert(x);
		p2[s2[y]-'0'].insert(y);
	}
}
int main()
{
//	freopen("edit2.in","r",stdin);
	int T,n,i,ans,now1,now2,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		scanf("%s",t1+1);
		scanf("%s",t2+1);
		now1=now2=0;
		for(i=1;i<=n;i++)
		{
			if(t1[i]=='0') now1=0;
			else now1++;
			if(t2[i]=='0') now2=0;
			else now2++;
			pre1[i]=i;
			if(now1>0) pre1[i]=i-now1+1;
			pre2[i]=i;
			if(now2>0) pre2[i]=i-now2+1;
		}
		now1=now2=0;
		for(i=n;i;i--)
		{
			if(t1[i]=='0') now1=0;
			else now1++;
			if(t2[i]=='0') now2=0;
			else now2++;
			nex1[i]=i;
			if(now1>0) nex1[i]=i+now1-1;
			nex2[i]=i;
			if(now2>0) nex2[i]=i+now2-1;
		}
		p1[0].clear();
		p1[1].clear();
		p2[0].clear();
		p2[1].clear();
		for(i=1;i<=n;i++)
		{
			p1[s1[i]-'0'].insert(i);
			p2[s2[i]-'0'].insert(i);
		}
		for(i=1;i<=n;i++)
		{
			if(s1[i]==s2[i]) continue;
			auto itx=p2[s1[i]-'0'].lower_bound(i);
			if(itx!=p2[s1[i]-'0'].end())
			{
				x=*itx;
				if(nex1[i]>=pre2[x])
				{
					myswap(2,x,max(pre2[x],i));
					myswap(1,i,max(pre2[x],i));
				}
			}
			
			if(s1[i]==s2[i]) continue;
			itx=p1[s2[i]-'0'].lower_bound(i);
			if(itx!=p1[s2[i]-'0'].end())
			{
				x=*itx;
				if(nex2[i]>=pre1[x])
				{
					myswap(1,x,max(pre1[x],i));
					myswap(2,i,max(pre1[x],i));
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=s1[i]==s2[i];
		printf("%d\n",ans);
	}
	return 0;
}
/*
20分：5-8 性质A，送分，ans=sum{s1[1]==s2[i]}
20分：9-12 性质B，把可交换的位置搞成一些连通块，分组匹配。 

100分，2.5h 
最开始想的是往前交换，前面那个位置已经匹配就不换，发现怎么搞都过不了大样例。
后来发现往前匹配最近的一个不一定是最优的，于是考虑对往后交换。
往后交换，在之后遍历就有机会变得更优。

首先要预处理能交换的范围，然后交换还有一个限制：
就是你不可能跨越一个相同的字符，比如 10010 不可能一次交换变成 00011，
---
不对，发现解释不通为什么需要有这个限制。
因为会发现总能进行若干次交换从 10010 变成 00011，所以直接换就行。

然后用set维护位置，因为每次需要找到 要换到哪。
 
虽然不能证明做法正确性，而且常数很大，但是过了。
*/
