#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e6+10;
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
char a[MAX],b[MAX];
int main()
{
	HASH::set({131,233},{402653189,805306457});
	HASH::init(2e6);
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);
		scanf("%s",b+1);
		n=strlen(a+1);
		ha.work(b,n);
		auto res=ha.get(1,n);
		for(i=n+1;i<=2*n;i++) a[i]=a[i-n];
		ha.work(a,2*n);
		ans=-1;
		for(i=1;i<=n;i++)
		{
			if(ha.get(i,i+n-1)==res)
			{
				ans=i-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
