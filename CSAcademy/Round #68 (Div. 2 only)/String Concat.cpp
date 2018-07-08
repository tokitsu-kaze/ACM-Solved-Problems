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
const double eps=1e-6;
const int MAX=1e6+10;
int main()
{
	int n,i,j,k;
	char s[55][55],temp[111];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		vector<int> ans;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(k==j) continue;
					strcpy(temp,s[j]);
					strcat(temp,s[k]);
					if(strcmp(temp,s[i])==0)
					{
						ans.pb(i+1);
						goto end;
					}
				}
			}
			end:;
		}
		for(i=0;i<sz(ans);i++) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}