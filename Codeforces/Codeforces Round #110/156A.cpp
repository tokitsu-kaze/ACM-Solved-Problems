#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e3+10;
const ll mod=1e9+7;
int main()
{
	int i,j,lena,lenb,ans;
	char a[MAX],b[MAX];
	while(~scanf("%s%s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		ans=0;
		for(i=0;i<lena;i++)
		{
			int now=0;
			for(j=0;i+j<lena&&j<lenb;j++)
			{
				if(a[i+j]==b[j]) now++;
			}
			ans=max(ans,now);
		}
		for(i=0;i<lenb;i++)
		{
			int now=0;
			for(j=0;j<lena&&i+j<lenb;j++)
			{
				if(a[j]==b[i+j]) now++;
			}
			ans=max(ans,now);
		}
		printf("%d\n",lenb-ans);
	}
	return 0;
}