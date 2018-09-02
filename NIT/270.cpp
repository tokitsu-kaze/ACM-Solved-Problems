#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
char a[MAX],b[MAX];
int main()
{
	int i,lena,lenb,bita[333],bitb[333],flag;
	while(~scanf("%s %s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		if(lena!=lenb)
		{
			puts("No");
			continue;
		}
		mem(bita,0);
		mem(bitb,0);
		flag=0;
		for(i=0;i<lena;i++) bita[a[i]]++;
		for(i=0;i<lenb;i++) bitb[b[i]]++;
		for(i='a';i<='z';i++)
		{
			if(bita[i]!=bitb[i]) flag=1;
		}
		for(i='A';i<='Z';i++)
		{
			if(bita[i]!=bitb[i]) flag=1;
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}