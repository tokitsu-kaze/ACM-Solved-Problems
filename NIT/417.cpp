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
char a[MAX],b[MAX];
int bit[MAX][3];
int main()
{
	int i,j,lena,lenb;
	ll ans;
	while(~scanf("%s%s",a+1,b+1))
	{
		ans=0;
		mem(bit,0);
		lena=strlen(a+1);
		for(i=1;i<=lena;i++)
		{
			bit[i][a[i]-'a']++;
			for(j=0;j<2;j++) bit[i][j]+=bit[i-1][j];
		}
		lenb=strlen(b+1);
		for(i=1;i<=lenb;i++)
		{
			ans+=bit[lena-(lenb-i)][(b[i]-'a')^1]-bit[i-1][(b[i]-'a')^1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}