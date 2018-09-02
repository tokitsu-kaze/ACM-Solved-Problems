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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e3+10;
const ll mod=1e6;
int main()
{
	int n,m,i,ans,a[MAX],t,v;
	while(~scanf("%d%d",&n,&m))
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&t,&v);
			a[t]+=v;
		}
		ans=0;
		for(i=1;i<=3001;i++)
		{
			int temp=m;
			if(a[i-1]<=temp)
			{
				ans+=a[i-1];
				temp-=a[i-1];
			}
			else
			{
				ans+=temp;
				temp=0;
			}
			if(a[i]<=temp)
			{
				ans+=a[i];
				a[i]=0;
			}
			else
			{
				ans+=temp;
				a[i]-=temp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5 20
1 50
2 30
4 10
5 30
7 50
*/