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
int main()
{
	int a,b,flag,now;
	while(~scanf("%d%d",&a,&b))
	{
		flag=0;
		now=1;
		while(1)
		{
			if(now%2)
			{
				if(a<now)
				{
					flag=1;
					break;
				}
				else a-=now;
			}
			else
			{
				if(b<now)
				{
					flag=2;
					break;
				}
				else b-=now;
			}
			now++;
		}
		if(flag==1) puts("Vladik");
		else puts("Valera");
	}
	return 0;
} 