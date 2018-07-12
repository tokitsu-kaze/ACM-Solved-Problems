#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=2e5+10;
const ll mod=1e9+7;
hash_map<int,int> flag;
void init(int n)
{
	flag.clear();
	int i;
	for(i=1;i*i<=n;i++) flag[i*i]=1;
}
int main()
{
	init((int)2e9);
	char s[111];
	int i,j,now,len,ans,cnt;
	while(~scanf("%s",s))
	{
		len=strlen(s);
		ans=INF;
		for(i=1;i<(1<<len);i++)
		{
			now=0;
			cnt=0;
			for(j=0;j<len;j++)
			{
				if((1<<j)&i)
				{
					if(now==0&&s[j]=='0') break;
					now=now*10+s[j]-'0';
					cnt++;
				}
			}
			if(flag.count(now)) ans=min(ans,len-cnt);
		}
		ans==INF?puts("-1"):printf("%d\n",ans);
	}
	return 0;
}