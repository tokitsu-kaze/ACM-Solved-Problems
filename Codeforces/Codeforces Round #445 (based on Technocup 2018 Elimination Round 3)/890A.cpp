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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int i,a[11],s,j,temp,cnt;
	while(~scanf("%d",&a[0]))
	{
		s=a[0];
		for(i=1;i<6;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		for(i=0;i<(1<<6);i++)
		{
			temp=0;
			cnt=0;
			for(j=0;j<6;j++)
			{
				if((1<<j)&i)
				{
					temp+=a[j];
					cnt++;
				}
			}
			if(cnt!=3) continue;
			if(temp==s-temp)
			{
				puts("YES");
				return 0;
			}
		}
		puts("NO");
	}
	return 0;
}