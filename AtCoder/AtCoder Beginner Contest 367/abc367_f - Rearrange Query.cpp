#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
namespace HASH
{
	#define type ll
	const int k=2;
	int m;
	vector<vector<type>> tmp;
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp.resize(k);
		mt19937 rd(time(0));
		for(j=0;j<k;j++)
		{
			tmp[j].resize(m+1);
			tmp[j][0]=0;
			for(i=1;i<=m;i++) tmp[j][i]=rd();
		}
	}
	struct hash_table
	{
		vector<vector<type>> ha;
		void work(int *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha.resize(k);
			for(j=0;j<k;j++)
			{
				ha[j].resize(n+1);
				ha[j][0]=0;
				for(i=1;i<=n;i++) ha[j][i]=ha[j][i-1]+tmp[j][s[i]];
			}
		}
		vector<type> get(int l,int r)
		{
			vector<type> res(k);
			for(int j=0;j<k;j++)
			{
				res[j]=ha[j][r]-ha[j][l-1];
			}
			return res;
		}
	};
	#undef type
}
HASH::hash_table ha1,ha2;
/*
HASH::init(m);
ha.work(s,n);   // n<=m
*/
int x[MAX],y[MAX];
int main()
{
	int n,q,i,a,b,c,d;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&x[i]);
	for(i=1;i<=n;i++) scanf("%d",&y[i]);
	HASH::init(n);
	ha1.work(x,n);
	ha2.work(y,n);
	while(q--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(ha1.get(a,b)==ha2.get(c,d)) puts("Yes");
		else puts("No");
	}
	return 0;
}
