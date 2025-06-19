#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Trie
{
	#define type int
	static const int K=26;
	int nex[MAX][K],cnt1[MAX],cnt2[MAX];
	int root,tot;
	int getid(char c){return c-'a';}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt1[tot]=cnt2[tot]=0;
		return tot;
	}
	void init()
	{
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		cnt1[0]=cnt2[0]=0;
		root=newnode();
	}
	int insert(char *s,int n,int v) // s[0..n-1]
	{
		int now,i,t,res;
		now=root;
		res=0;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			res+=cnt1[now];
			cnt2[now]+=v;
			now=nex[now][t];
		}
		cnt1[now]+=v;
		res+=cnt2[now];
		return res;
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
char op[2],s[MAX];
ll res[MAX];
int main()
{
	int n,i,len;
	ll ans;
	scanf("%d",&n);
	ans=0;
	tr.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",op,s);
		len=strlen(s);
		reverse(s,s+len);
		if(op[0]=='+') ans+=tr.insert(s,len,1);
		else ans-=tr.insert(s,len,-1);
		res[i]=ans;
	}
	for(i=1;i<=n;i++) printf("%lld%c",res[i]," \n"[i==n]);
	return 0;
}
