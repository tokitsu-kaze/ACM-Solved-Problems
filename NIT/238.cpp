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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int i,j,k,n,a,b,c,v[666];
	while(~scanf("%d",&n))
	{
		a=b=c=0;
		mem(v,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(i=1,j=5,k=15;i<=n;i++,j+=2,k+=3)
		{
			while(!v[i]&&i<n) i++;
			while(!v[j]&&j<n) j++;
			while(!v[k]&&k<n) k++;
			a+=v[i];
			b+=v[j];
			c+=v[k];
	//		cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
			v[i]=v[j]=v[k]=0;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}