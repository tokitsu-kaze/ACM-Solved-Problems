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
const long double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,l,r;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=r=-1;
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				l=r=i;
				while(r<n&&a[r]>a[r+1]) r++;
				break;
			}
		}
		if(l==-1)
		{
			puts("yes");
			puts("1 1");
			continue;
		}
		reverse(a+l,a+r+1);
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				puts("no");
				goto end;
			}
		}
		puts("yes");
		printf("%d %d\n",l,r);
		end:;
	}
	return 0;
}
/*
4
1 2 4 3
*/