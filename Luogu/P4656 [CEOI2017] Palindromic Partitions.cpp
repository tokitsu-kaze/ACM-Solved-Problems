#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
HASH::hash_table ha;
/*
HASH::set({131,233},{402653189,805306457});
HASH::init(m);
ha.work(s,n);   // n<=m
*/
char s[MAX];
int main()
{
	int t,n,i,l,r,ans,f;
	HASH::set({131,233},{402653189,805306457});
	HASH::init(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ha.work(s,n);
		l=1;
		r=n;
		ans=0;
		while(l<=r)
		{
			f=0;
			for(i=1;i<=r-l+1;i++)
			{
				if(ha.get(l,l+i-1)==ha.get(r-i+1,r))
				{
					if(l+i-1>=r-i+1) f=1;
					else f=2;
					l=l+i;
					r=r-i;
					break;
				}
			}
			ans+=f;
			if(f==1) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
