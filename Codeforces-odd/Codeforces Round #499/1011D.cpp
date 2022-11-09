#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int main()
{
	int m,n,i,p[33],ans;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cout<<m<<endl;
		cin>>p[i];
		if(p[i]==0) return 0;
		p[i]*=-1;
	}
	int l=1,r=m,mid;
	i=1;
	while(l<r)
	{
		mid=(l+r)>>1;
		cout<<mid<<endl;
		cin>>ans;
		ans*=p[i++];
		if(i>n) i=1;
		if(ans==0) return 0;
		if(ans==1) l=mid+1;
		else r=mid;
	}
	return 0;
}