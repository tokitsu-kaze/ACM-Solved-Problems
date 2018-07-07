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
int main()
{
	ll a,b,c,k,aa,bb,cc,pre1,pre2,pre3;
	while(cin>>a>>b>>c>>k)
	{
		k=k%2;
		while(k>0)
		{
/*			if(pre1==a-b&&pre2==a-c&&pre3==b-c)
			{
				break;
			}*/
			pre1=a-b;
			pre2=a-c;
			pre3=b-c;
			k=k-1;
			aa=b+c;
			bb=a+c;
			cc=a+b;
			if(abs(aa-bb)>1e18)
			{
				puts("Unfair");
				goto end;
			}
			a=aa;
			b=bb;
			c=cc;
	//		cout<<a<<" "<<b<<" "<<c<<" "<<a-b<<" "<<b-c<<endl;
		}
		if(abs(a-b)>1e18) puts("Unfair");
		else cout<<a-b<<"\n";
		end:;
	} 
	return 0;
} 
