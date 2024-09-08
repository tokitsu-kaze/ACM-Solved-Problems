#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
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
			ha.resize(k);
			for(j=0;j<k;j++)
			{
				ha[j].resize(n+1);
				ha[j][0]=0;
				map<int,int> lst;
				for(i=1;i<=n;i++)
				{
					if(lst.count(s[i])) ha[j][i]=ha[j][i-1];
					else ha[j][i]=ha[j][i-1]+tmp[j][s[i]];
					lst[s[i]]=i;
				}
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
	int n,q,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		d.add(x[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&y[i]);
		d.add(y[i]);
	}
	d.work();
	for(i=1;i<=n;i++)
	{
		x[i]=d.get_pos(x[i]);
		y[i]=d.get_pos(y[i]);
	}
	HASH::init(d.size());
	ha1.work(x,n);
	ha2.work(y,n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if(ha1.get(1,a)==ha2.get(1,b)) puts("Yes");
		else puts("No");
	}
	return 0;
}

