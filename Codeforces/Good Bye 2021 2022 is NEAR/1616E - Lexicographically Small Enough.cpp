#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res+=bit[x];
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]+=v;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr;
char s[MAX],t[MAX];
int main()
{
	int T,n,i,j,p,nex[26];
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		vector<int> pos[26];
		for(i=1;i<=n;i++) pos[s[i]-'a'].push_back(i);
		for(i=0;i<26;i++) pos[i].push_back(n+1);
		memset(nex,0,sizeof nex);
		tr.init(n);
		now=0;
		ans=LLINF;
		for(i=1;i<=n;i++)
		{
			for(j=(t[i]-'a')-1;j>=0;j--)
			{
				p=pos[j][nex[j]];
				if(p>n) continue;
				ans=min(ans,now+(p+tr.ask(p,n)-i));
			}
			j=t[i]-'a';
			p=pos[j][nex[j]];
			if(p>n) break;
			now+=(p+tr.ask(p,n)-i);
			tr.upd(p,1);
			nex[j]++;
		}
		if(ans==LLINF) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
枚举1..i-1相同，s[i]!=t[i]
树状数组维护p后面有几个挪到前面的 
*/
