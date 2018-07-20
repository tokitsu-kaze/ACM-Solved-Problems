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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e5+10;
int main()
{
	int n,m,a,b;
	while(~scanf("%d%d%d%d",&n,&m,&a,&b))
	{
		if(b==n&&b%m) b=m*(b/m+1);
		if(m==1||a==b||m>=n)
		{
			puts("1");
			continue;
		}
		if((a-1)%m==0&&b%m==0)
		{
			puts("1");
			continue;
		}
		if(b-a+1<=m)
		{
			int ta,tb;
			ta=a%m==0?m:a%m;
			tb=b%m==0?m:b%m;
			if(tb>ta)
			{
				puts("1");
				continue;
			}
			else
			{
				puts("2");
				continue;
			}
		}
		else
		{
			if(a%m-b%m==1||b%m-a%m==m-1)
			{
				puts("2");
				continue;
			}
			int ans=0;
			if((a-1)%m)
			{
				ans++;
				if(a%m) a=m*(a/m+1);
			}
			if(b%m)
			{
				ans++;
				b=m*(b/m+1);
			}
			if((b-a)/m==1)
			{
				puts("2");
				continue;
			}
			else ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
21 3 6 11
21 5 3 12
*/