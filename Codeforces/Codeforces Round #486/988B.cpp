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
string s[111];
int main()
{
	int n,i,j,flag;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>i;j--)
			{
				if(s[j].find(s[j-1])==-1) swap(s[j],s[j-1]);
			}
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(s[j].find(s[i])!=-1);
				else flag=1;
			}
		}
		if(flag)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=0;i<n;i++) cout<<s[i]<<"\n";
	}
	return 0;
}