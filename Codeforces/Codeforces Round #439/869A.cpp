#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
int a[2222],b[2222];
int main()
{
	int n,i,j,ans;
	while(~scanf("%d",&n))
	{
		map<int,int> flag;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			flag[a[i]]=1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			flag[b[i]]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(flag.count(a[i]^b[j])) ans++;
			}
		}
		if(ans%2) puts("Koyomi");
		else puts("Karen");
	}
	return 0;
}