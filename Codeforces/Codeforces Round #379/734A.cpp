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
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
char s[MAX];
int main()
{
	int n,i,a,d;
	while(~scanf("%d",&n))
	{
		a=d=0;
		scanf("%s",s);
		for(i=0;i<n;i++)
		{
			if(s[i]=='A') a++;
			else if(s[i]=='D') d++;
		}
		if(a==d) puts("Friendship");
		else if(a>d) puts("Anton");
		else puts("Danik");
	}
	return 0;
}