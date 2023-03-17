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
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	int i,len,cnt;
	char a[1111];
	while(~scanf("%s",a))
	{
		cnt=0;
		for(i=4;i<strlen(a);i++)
		{
			if(a[i-4]=='D'&&a[i-3]=='a'&&a[i-2]=='n'&&a[i-1]=='i'&&a[i]=='l') cnt++;
		}
		for(i=3;i<strlen(a);i++)
		{
			if(a[i-3]=='O'&&a[i-2]=='l'&&a[i-1]=='y'&&a[i]=='a') cnt++;
		}
		for(i=4;i<strlen(a);i++)
		{
			if(a[i-4]=='S'&&a[i-3]=='l'&&a[i-2]=='a'&&a[i-1]=='v'&&a[i]=='a') cnt++;
		}
		for(i=2;i<strlen(a);i++)
		{
			if(a[i-2]=='A'&&a[i-1]=='n'&&a[i]=='n') cnt++;
		}
		for(i=5;i<strlen(a);i++)
		{
			if(a[i-5]=='N'&&a[i-4]=='i'&&a[i-3]=='k'&&a[i-2]=='i'&&a[i-1]=='t'&&a[i]=='a') cnt++;
		}
		if(cnt==1) puts("YES");
		else puts("NO");
	}
	return 0;
}