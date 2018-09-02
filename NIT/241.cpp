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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int i,cnt;
	char a[111],b[111],c[111],d[111];
	while(gets(a))
	{
		gets(b);
		cnt=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]!=' ')
			{
				if(a[i]>='A'&&a[i]<='Z') a[i]=a[i]-'A'+'a';
				c[cnt++]=a[i];
			}
		}
		c[cnt]='\0';
		cnt=0;
		for(i=0;i<strlen(b);i++)
		{
			if(b[i]!=' ')
			{
				if(b[i]>='A'&&b[i]<='Z') b[i]=b[i]-'A'+'a';
				d[cnt++]=b[i];
			}
		}
		d[cnt]='\0';
		strcmp(c,d)==0?puts("YES"):puts("NO");
	}
	return 0;
}