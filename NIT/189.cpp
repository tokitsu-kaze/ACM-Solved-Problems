#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-5;
const int MAX=1e3+10;
const ll mod=1e9+6;
ll mp[MAX][MAX];
int main()
{
	ll x[MAX],y[MAX],t,i,j,n,m,k,a,b,sum;
	char op[111];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		mem(mp,0);
		mem(x,0);
		mem(y,0);
		sum=0;
		for(i=1;i<=n;i++)
		{
			x[i]=i;
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&mp[i][j]);
				sum+=mp[i][j];
				y[j]=j;
			}
		}
		while(k--)
		{
			getchar();
			scanf("%s %lld%lld",op,&a,&b);
	//		cout<<op<<endl;
			if(op[0]=='r') swap(x[a],x[b]);
			else if(op[0]=='c') swap(y[a],y[b]);
			else if(op[0]=='s')
			{
				printf("%lld\n",mp[x[a]][y[b]]);
				sum-=mp[x[a]][y[b]];
				mp[x[a]][y[b]]=0;
			}
			if(sum==0) break;
		}
	}
	return 0;
}