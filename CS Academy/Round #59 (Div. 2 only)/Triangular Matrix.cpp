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
const int MAX=3e4+10;
const ll mod=1e9+7;
char ans[3005],a[3005];
vector<int> p[2];
int main()
{
	int n,i,j,flag,temp;
	char minn;
	while(~scanf("%d",&n))
	{
		flag=0;
		vector<int> ().swap(p[flag]);
		p[flag].pb(0);
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			minn='z';
			for(j=0;j<sz(p[flag]);j++)
			{
				if(a[p[flag][j]]<minn) minn=a[p[flag][j]];
			}
			temp=flag^1;
			vector<int> ().swap(p[temp]);
			for(j=0;j<sz(p[flag]);j++)
			{
				if(a[p[flag][j]]==minn)
				{
					if(p[temp].empty()||p[flag][j]>p[temp].back()) p[temp].pb(p[flag][j]);
					p[temp].pb(p[flag][j]+1);
				}
			}
			flag^=1;
			ans[i]=minn;
		}
		ans[n]='\0';
		puts(ans);
	}
	return 0;
}
/*
5
a
aa
aba
acab
bcbcb
*/