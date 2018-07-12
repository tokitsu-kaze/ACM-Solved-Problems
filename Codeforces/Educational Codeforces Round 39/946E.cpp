#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
char s[MAX];
int cnt[MAX][10];
void solve()
{
	int i,j,k,len,tmp;
	len=strlen(s+1);
	mem(cnt[0],0);
	for(i=1;i<=len;i++)
	{
		for(j=0;j<10;j++)
		{
			cnt[i][j]=cnt[i-1][j]^(s[i]-'0'==j);
		}
	}
	for(i=len;i;i--)
	{
		for(j=s[i]-'0'-1;j>=(i==1);j--)
		{
			tmp=0;
			for(k=0;k<10;k++)
			{
				tmp+=cnt[i-1][k]^(k==j);
			}
			if(tmp<=len-i)
			{
				s[i]='\0';
				printf("%s",s+1);
				printf("%d",j);
				for(k=1;k<=len-i-tmp;k++)
				{
					printf("9");
				}
				cnt[i-1][j]^=1;
				for(k=9;~k;k--)
				{
					if(cnt[i-1][k]) printf("%d",k);
				}
				puts("");
				return;
			}
		}
	}
	for(i=0;i<len-2;i++) printf("9");
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		solve();
	}
	return 0;
}