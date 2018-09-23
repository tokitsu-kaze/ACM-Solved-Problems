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
const int MAX=1e6+10;
const ll mod=1e9+7;
int dep[MAX],v[MAX];
int main()
{
	int i,j,n,ans,pos,l,r,tmp,now;
	while(~scanf("%d",&n))
	{
		priority_queue<int> q[111];
		l=100;r=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&dep[i]);
			l=min(l,dep[i]);
			r=max(r,dep[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			q[dep[i]].push(v[i]);
		}
		now=ans=0;
		for(i=1;i<=n;i++)
		{
			tmp=0;
			while(!sz(q[l])&&l<r) l++;
			while(!sz(q[r])&&l<r) r--;
			for(j=l;j<=r;j++)
			{
				if(!sz(q[j])) continue;
				int temp=max(now,j);
				if(temp*2+q[j].top()>tmp)
				{
					tmp=temp*2+q[j].top();
					pos=j;
				}
			}
			now=max(now,pos);
			ans+=q[pos].top();
			q[pos].pop();
			printf("%d\n",ans+2*now);
		}
	}
	return 0;
}
/*
5
5 4 3 2 1
1 2 3 4 5
*/