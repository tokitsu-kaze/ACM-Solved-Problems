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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int c[MAX],cnt[(int)1e6+10];
int main()
{
	int n,a,b,i,acnt;
	while(~scanf("%d%d",&n,&a))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		mem(cnt,0);
		acnt=0;
		for(i=0;i<n;i++)
		{
			if(c[i]==a)	acnt++;
			else if(cnt[c[i]]>=acnt) cnt[c[i]]++;
		}
		b=-1;
		for(i=1;i<=1e6;i++)
		{
			if(cnt[i]>=acnt&&i!=a)
			{
				b=i;
				break;
			}
		}
		printf("%d\n",b);
	}
	return 0;
} 
/*
4 1
2 1 4 2
5 2
2 2 4 5 3
3 10
1 2 3
*/