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
int a[MAX],b[MAX];
int main()
{
	int t,n,i,flag,ans,tag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		flag=0;
		tag=0;
		for(i=0;i<n;i++)
		{
			if(b[i])
			{
				if(a[i]%2&&b[i]==2) tag=1;
				else if(a[i]%2==0&&b[i]==2) flag++;
				else if(a[i]%2&&a[i]>1&&b[i]==1) flag++;
				else if(a[i]%2==0&&b[i]==1) flag++;
			}
		}
		if(tag)
		{
			puts("Bob");
			continue;
		}
		if(flag)
		{
			if(flag>1) puts("Bob");
			else
			{
				
				ans=0;
				for(i=0;i<n;i++)
				{
					if(b[i])
					{
						if(a[i]%2==0&&b[i]==2) a[i]=0;
						else if(a[i]%2&&a[i]>1&&b[i]==1) a[i]=0;
						else if(a[i]%2==0&&b[i]==1) a[i]=1;
					}
					ans^=a[i];
				}
				if(ans) puts("Bob");
				else puts("Alice");
			}
		}
		else
		{
			ans=0;
			for(i=0;i<n;i++) ans^=a[i];
			if(ans) puts("Alice");
			else puts("Bob");
		}
	}
	return 0;
} 