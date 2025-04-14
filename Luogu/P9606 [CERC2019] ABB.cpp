#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
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
		vector<type> get(int l,int r)
		{
			vector<type> res(k);
			for(int j=0;j<k;j++)
			{
				res[j]=(ha[j][r]-1ll*ha[j][l-1]*tmp[j][r-l+1])%p[j];
				if(res[j]<0) res[j]+=p[j];
			}
			return res;
		}
	};
	#undef type
}
HASH::hash_table ha,rha;
/*
HASH::set({131,233},{402653189,805306457});
HASH::init(m);
ha.work(s,n);   // n<=m
*/
char s[MAX],rs[MAX];
int main()
{
	int n,i,ans,r,len;
	HASH::set({131,233},{402653189,805306457});
	HASH::init(4e5);
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1) return 0*puts("0");
	ha.work(s,n);
	for(i=1;i<=n;i++) rs[i]=s[n-i+1];
	rha.work(rs,n);
	if(s[n-1]==s[n])
	{
		ans=2*n-2;
		r=n-2;
	}
	else
	{
		ans=2*n-1;
		r=n-1;
	}
	for(i=1;i<n;i++)
	{
		len=n-i;
		if(len>i-1) continue;
		if(ha.get(i-len,i-1)==rha.get(1,n-(i+1)+1))
		{
			if(ans>n+i-len-1)
			{
				ans=n+i-len-1;
				r=i-len-1;
			}
		}
	}
	for(i=1;i+2<=n;i++)
	{
		if(s[i]!=s[i+1]) continue;
		len=n-i-1;
		if(len>i-1) continue;
		if(ha.get(i-len,i-1)==rha.get(1,n-(i+2)+1))
		{
			if(ans>n+i-len-1)
			{
				ans=n+i-len-1;
				r=i-len-1;
			}
		}
	}
	printf("%d\n",ans-n);
	return 0;
}
/*
abcddcb

abc398_f
*/
