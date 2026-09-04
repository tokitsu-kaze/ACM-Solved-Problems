#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct node
{
	int v,x,y,cnt;
	friend bool operator<(node a,node b)
	{
		if(a.cnt==b.cnt) return a.v>b.v;
		return a.cnt>b.cnt;
	}
};
char s[MAX],ans[MAX];
int tag[MAX],l[MAX],r[MAX],n;
int ck(int x,int y)
{
	if(x<1 || y>n) return 0;
	if(tag[x] || tag[y]) return 0;
	if(s[x]+1==s[y]) return 1;
	if(s[x]=='9' && s[y]=='0') return 1;
	return 0;
}
void del(int x)
{
	r[l[x]]=r[x];
	l[r[x]]=l[x];
	
	tag[x]=1;
}
int main()
{
	int T,cas,i,tot,nexcnt;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			l[i]=i-1;
			r[i]=i+1;
			tag[i]=0;
		}
		priority_queue<node> q;
		for(i=1;i<n;i++)
		{
			if(ck(i,i+1)) q.push({s[i]-'0',i,i+1,1});
		}
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(!ck(t.x,t.y)) continue;
//			printf("%d %d %c%c %d\n",t.x,t.y,s[t.x],s[t.y],t.cnt);
			if(s[t.y]=='9') s[t.y]='0';
			else s[t.y]++;
			if(ck(l[t.x],t.y))
			{
				if(s[t.y]=='1') nexcnt=t.cnt+1;
				else nexcnt=t.cnt;
				q.push({s[l[t.x]]-'0',l[t.x],t.y,nexcnt});
			}
			if(ck(t.y,r[t.y]))
			{
				if(s[t.y]=='0' || s[t.y]=='1') nexcnt=t.cnt+1;
				else nexcnt=t.cnt;
				q.push({s[t.y]-'0',t.y,r[t.y],nexcnt});
			}
			del(t.x);
		}
		tot=0;
		for(i=1;i<=n;i++)
		{
			if(!tag[i]) ans[++tot]=s[i];
		}
		ans[tot+1]='\0';
		printf("Case #%d: %s\n",cas,ans+1);
	}
	return 0;
}
/*
按题意模拟，把两位数的第一位放入堆里维护。
注意 89->0 和 90->1 放进去的可能是下一轮的，维护一个轮数。

3
11
0133456789
4
9891
6
987890
*/
