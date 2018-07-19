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
const double eps=1e-10;
const int MAX=5e4+10;
const ll mod=1e9+7;
int main()
{
	int len,i,s,f;
	char a[111];
	while(~scanf("%d%s",&len,a))
	{
		s=f=0;
		for(i=1;i<len;i++)
		{
			if(a[i]=='F'&&a[i-1]=='S') s++;
			else if(a[i]=='S'&&a[i-1]=='F') f++;
		}
		if(s>f) puts("YES");
		else puts("NO");
	} 
	return 0;
}