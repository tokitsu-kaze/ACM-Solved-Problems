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
const int MAX=5e5+10;
const ll mod=1e9+7;
string s[MAX];
int main()
{
	int n,i,j,len;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		for(i=n-2;i>=0;i--)
		{
			len=s[i].length();
			len=min(len,(int)s[i+1].length());
			int flag=0;
			for(j=0;j<len;j++)
			{
				if(s[i][j]>s[i+1][j])
				{
					flag=1;
					s[i].resize(j);
					break;
				}
				else if(s[i][j]<s[i+1][j])
				{
					flag=1;
					break;
				}
			}
			if(!flag&&s[i].length()>s[i+1].length()) s[i].resize(s[i+1].length());
		}
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<"\n";
		}
	}
	return 0;
}