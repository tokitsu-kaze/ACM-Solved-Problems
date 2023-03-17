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
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
char a[MAX],temp;
int main()
{
	int t,n,i,r,d,cntr,cntd;
	while(~scanf("%d%s",&n,a))
	{
		queue<char> q;
		r=d=0;
		for(i=0;i<n;i++)
		{
			if(a[i]=='R') r++;
			else if(a[i]=='D') d++;
			q.push(a[i]);
		}
		cntr=cntd=0;
		while(sz(q)&&r&&d)
		{
			temp=q.front();
			q.pop();
			if(temp=='D')
			{
				if(cntr)
				{
					cntr--;
					d--;
				}
				else
				{
					cntd++;
					q.push(temp);
				}
			}
			else
			{
				if(cntd)
				{
					cntd--;
					r--;
				}
				else
				{
					cntr++;
					q.push(temp);
				}
			}
		}
		if(r) puts("R");
		else if(d) puts("D");
	}
	return 0;
} 