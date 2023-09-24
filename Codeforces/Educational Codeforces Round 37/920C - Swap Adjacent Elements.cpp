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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX];
char s[MAX];
int main()
{
	int n,l,r,flag,i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		scanf("%s",s+1);
		l=1;
		r=1;
		flag=0;
		for(i=1;i<=n-1;i++)
		{
			if(s[i]=='1') r=i+1;
			else
			{
				sort(a+l,a+1+r);
				for(int j=l;j<=r;j++)
				{
					if(a[j]!=b[j])
					{
						puts("NO");
						goto end;
					}
				}
				l=r=i+1;
			}
		}
		if(l<=r)
		{
			sort(a+l,a+1+r);
			for(j=l;j<=r;j++)
			{
				if(a[j]!=b[j])
				{
					puts("NO");
					goto end;
				}
			}
		}
		puts("YES");
		end:;
	}
	return 0;
}