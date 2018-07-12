#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX],n,flag[MAX];
int work(int x,int y)
{
	int i,res=0,d;
	mem(flag,0);
	for(i=0;i<n;i++) b[i]=a[i];
	b[0]+=x;
	b[n-1]+=y;
	if((b[n-1]-b[0])%(n-1)) return INF;
	d=(b[n-1]-b[0])/(n-1);
	res+=abs(x)+abs(y);
	
	for(i=1;i<n-1;i++)
	{
		if(b[i]-b[i-1]-d==1) res++,b[i]--;
		else if(b[i]-b[i-1]-d==-1) res++,b[i]++;
	}
	for(i=2;i<n;i++)
	{
		if(b[i]-b[i-1]!=b[i-1]-b[i-2]) return INF;
	}
	return res;
}
int main()
{
	int i,j,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		if(n==1)
		{
			puts("0");
			continue;
		}
		ans=INF;
		for(i=-1;i<=1;i++)
		{
			for(j=-1;j<=1;j++)
			{
				ans=min(ans,work(i,j));
			}
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
1 3 3
*/