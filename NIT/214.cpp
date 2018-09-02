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
const int MAX=1e3+10;
const ll mod=1e6;
struct node
{
	int n,v;
	void input()
	{
		scanf("%d%d",&n,&v);
	}
	friend bool operator <(node a,node b)
	{
		if(a.v==b.v) return a.n<b.n;
		return a.v>b.v;
	}
}a[MAX];
int main()
{
	int n,k,i,j,ans,b[MAX],flag[MAX];
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			a[i].input();
		} 
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+k);
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
			{
				if(a[i].n<=b[j]&&!flag[j])
				{
					flag[j]=1;
					ans+=a[i].v;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 