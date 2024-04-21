#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e6+10;
struct Trie
{
	#define type int
	static const int K=26;
	int nex[MAX][K],cnt[MAX];
	int root,tot;
	int getid(char c){return c-'a';}
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	int insert(char *s,int n) // s[0..n-1]
	{
		int now,i,t,res;
		now=root;
		res=1;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
			res+=cnt[now];
		}
		cnt[now]++;
		return res;
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
char s[MAX];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	tr.init();
	ans=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		ans=max(ans,tr.insert(s,strlen(s)));
	}
	printf("%d\n",ans);
	return 0;
}
