#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int bit[MAX],n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int v)
{
	while(x<=n)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
int x[MAX];
int main()
{
	int m,k,ans,i,j,l,r;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		mem(bit,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		sort(x+1,x+1+n);
		ans=0;
		l=r=1;
		while(r<=n&&x[r]-x[l]+1<=m) r++;
		r--;
		while(l<=r&&r<=n)
		{
//			cout<<x[l]<<" "<<x[r]<<endl;
			int temp=r-l+1-(getsum(r)-getsum(l-1));
			if(temp>=k)
			{
				ans+=temp-k+1;
				temp-=k;
				for(i=r-temp;i<=r;i++)
				{
					update(i,1);
				}
			}
			l++;
			while(r<=n&&x[r]-x[l]+1<=m) r++;
			r--;
		}
		printf("%d\n",ans);
	}
	return 0;
}