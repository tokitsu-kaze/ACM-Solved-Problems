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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int x,y,s;
	void input()
	{
		scanf("%d%d%d",&x,&y,&s);
	}
}a[MAX];
int bit[111][111][15];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x, int y, int v, int t)
{
	int i,j;
	for(i=x;i<=100;i+=lowbit(i))
	{
		for(j=y;j<=100;j+=lowbit(j))
		{
			bit[i][j][t]+=v;
		}
	} 
}
int getsum(int x,int y,int t)
{
	int i,j,res=0;
	for(i=x;i>0;i-=lowbit(i))
	{
		for(j=y;j>0;j-=lowbit(j))
		{
			res+=bit[i][j][t];
		}
	}
	return res;
}
int main()
{
	int n,q,c,i,j,x1,x2,y1,y2,t;
	while(~scanf("%d%d%d",&n,&q,&c))
	{
		mem(bit,0);
		for(i=0;i<n;i++)
		{
			a[i].input();
			for(j=0;j<=c;j++)
			{
				int temp=a[i].s+j;
				if(temp>c) temp-=(c+1);
				update(a[i].x,a[i].y,temp,j);
			}
		}
		while(q--)
		{
			scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
			t%=(c+1);
			x1--;
			y1--;
			printf("%d\n",getsum(x2,y2,t)-getsum(x1,y2,t)-getsum(x2,y1,t)+getsum(x1,y1,t));
		}
	}
	return 0;
}