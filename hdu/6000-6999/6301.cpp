#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
PII a[MAX];
int ans[MAX];
int main()
{
	int n,i,j,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d%d",&a[i].fi,&a[i].se);
		sort(a+1,a+1+m);
		priority_queue<int> q;
		for(i=1;i<=n;i++) q.push(-i);
		for(i=1,j=1;i<=n;i++)
		{
			if(j<=m&&i>=a[j].fi&&i<=a[j].se)
			{
				ans[i]=-q.top();
				q.pop();
			}
			else ans[i]=1;
			int tmp=j;
			while(j<=m&&i>=a[j].se) j++;
			if(tmp!=j)
			{
				for(int k=a[tmp].fi;k<min(a[j].fi,i+1);k++) q.push(-ans[k]);
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
