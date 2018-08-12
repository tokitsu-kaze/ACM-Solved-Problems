#include <bits/stdc++.h>
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
char a[MAX];
int main()
{
	int len,x,i,l,r,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&len,&x);
		x--;
		scanf("%s",a);
		l=r=0;
		for(i=1;i<=x;i++)
		{
			if(a[i]=='R') l++;
		}
		for(i=x;i<len-1;i++)
		{
			if(a[i]=='L') r++;
		}
		printf("%d\n",min(l,r));
	}
	return 0;
}
/*
4 3
RRLL
*/