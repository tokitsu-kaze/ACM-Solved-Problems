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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,p,i,flag;
	char s[2222];
	while(~scanf("%d%d",&n,&p))
	{
		scanf("%s",s+1);
		flag=0;
		for(i=1;i<=n&&i+p<=n;i++)
		{
			if(s[i]!='.')
			{
				if(s[i+p]=='.')
				{
					s[i+p]=(s[i]-'0')^1+'0';
					flag=1;
					break;
				}
				else
				{
					if(s[i+p]!=s[i])
					{
						flag=1;
						break;
					}
				}
			}
			else
			{
				if(s[i+p]!='.')
				{
					s[i]=(s[i+p]-'0')^1+'0';
					flag=1;
					break;
				}
				else
				{
					s[i]='0';
					s[i+p]='1';
					flag=1;
					break;
				}
			}
		}
		if(!flag)
		{
			puts("No");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(s[i]=='.') s[i]='0';
		}
		puts(s+1);
	}
	return 0;
}
