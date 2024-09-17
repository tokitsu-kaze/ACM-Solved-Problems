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
const int MAX=1e3+10;
const ll mod=1e9+7;
int main()
{
	int l,r,mid,a,ans,c1,c2,cnt,rr;
	cnt=0;
	l=0;
	r=(int)1e6;
	while(l<r)
	{
		mid=(l+r)>>1;
		cout<<"Q "<<mid+1<<endl;
		cnt++;
		cin>>a;
		if(a) l=mid+1,rr=l;
		else r=mid;
	}
	assert(cnt<=100);
	c1=c2=0;
	c2=3;
	for(ans=5;;ans++)
	{
		int tt=ans;
		while(tt%5==0) c1++,tt/=5;
		while(tt%2==0) c2++,tt/=2;
		int temp=min(c1,c2);
		rr-=temp;
		c1-=temp;
		c2-=temp;
		if(rr<=0) break;
	}
	cout<<"A "<<ans<<endl;
	return 0;
}