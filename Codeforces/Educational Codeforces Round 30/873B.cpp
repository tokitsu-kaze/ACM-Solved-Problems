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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
char a[MAX];
int l[2*MAX],r[2*MAX],bit[MAX];
int main()
{
	int i,len,ans;
	while(~scanf("%d%s",&len,a+1))
	{
		mem(l,0);
		mem(r,0);
		mem(bit,0);
		ans=0;
		for(i=1;i<=len;i++)
		{
			bit[i]=(a[i]=='0'?-1:1);
			bit[i]+=bit[i-1];
			if(bit[i]&&!l[bit[i]+(int)1e5]) l[bit[i]+(int)1e5]=i;
			else r[bit[i]+(int)1e5]=max(r[bit[i]+(int)1e5],i),ans=max(ans,r[bit[i]+(int)1e5]-l[bit[i]+(int)1e5]);
		}
		printf("%d\n",ans);
	}
	return 0;
}