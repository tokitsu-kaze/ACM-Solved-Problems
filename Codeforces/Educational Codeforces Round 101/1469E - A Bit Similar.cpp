#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
namespace HASH
{
	#define type int
	int m,k;
	vector<type> sd,p;
	vector<vector<type>> tmp;
	void set(vector<type> _sd,vector<type> _p)
	{
		sd=_sd;
		p=_p;
		assert(sd.size()==p.size());
		k=sd.size();
	}
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp.resize(k);
		for(j=0;j<k;j++)
		{
			tmp[j].resize(m+1);
			tmp[j][0]=1;
			for(i=1;i<=m;i++) tmp[j][i]=1ll*tmp[j][i-1]*sd[j]%p[j];
		}
	}
	struct hash_table
	{
		vector<vector<type>> ha;
		void work(char *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha.resize(k);
			for(j=0;j<k;j++)
			{
				ha[j].resize(n+1);
				ha[j][0]=0;
				for(i=1;i<=n;i++) ha[j][i]=(1ll*ha[j][i-1]*sd[j]+s[i])%p[j];
			}
		}
		void upd(char *s,int l,int r)
		{
			int i,j;
			for(j=0;j<k;j++)
			{
				for(i=l;i<=r;i++) ha[j][i]=(1ll*ha[j][i-1]*sd[j]+s[i])%p[j];
			}
		}
		pair<type,type> get(int l,int r)
		{
			vector<type> res(k);
			for(int j=0;j<k;j++)
			{
				res[j]=(ha[j][r]-1ll*ha[j][l-1]*tmp[j][r-l+1])%p[j];
				if(res[j]<0) res[j]+=p[j];
			}
			assert(k==2);
			return {res[0],res[1]};
		}
	};
	#undef type
}
HASH::hash_table ha;
/*
HASH::set({131,233},{402653189,805306457});
HASH::init(m);
ha.work(s,n);   // n<=m
*/
char s[MAX],t[MAX];
map<pair<int,int>,int> mp;
int ok,len;
void dfs(int x,int k)
{
	if(x==k+1)
	{
		ha.upd(t,max(1,k-len+1),k);
		if(!mp.count(ha.get(1,k))) ok=1;
		return;
	}
	dfs(x+1,k);
	if(ok) return;
	
	t[x]='1';
	dfs(x+1,k);
	if(ok) return;
	
	t[x]='0';
}
int main()
{
	int T,n,k,i;
	scanf("%d",&T);
	HASH::set({131,233},{402653189,805306457});
	HASH::init(MAX-10);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(i=1;i<=n;i++) s[i]^=1;
		ha.work(s,n);
		mp.clear();
		for(i=1;i+k-1<=n;i++) mp[ha.get(i,i+k-1)]=1;
		len=0;
		while((1<<len)<=n-k+1) len++;
		for(i=1;i<=k;i++) t[i]='0';
		ha.work(t,k);
		ok=0;
		dfs(max(1,k-len+1),k);
		if(ok)
		{
			puts("YES");
			t[k+1]='\0';
			puts(t+1);
		}
		else puts("NO");
	}
	return 0;
}
