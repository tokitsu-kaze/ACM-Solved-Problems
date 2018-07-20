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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 40000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,m,k,t,i,j,a,b,mp[1010],cnt,temp;
	while(~scanf("%d%d%d%d",&n,&m,&k,&t))
	{
		mem(mp,0);
		map<int,int> flag;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&a,&b);
			mp[i]=(a-1)*m+b;
			flag[(a-1)*m+b]=1;
		}
		sort(mp,mp+k);
		while(t--)
		{
			scanf("%d%d",&a,&b);
			cnt=0;
			temp=(a-1)*m+b;
			for(i=0;i<k;i++)
			{
				if(temp>mp[i]) cnt++;
				else break;
			}
			temp=(temp-cnt)%3;
			if(flag[(a-1)*m+b]==1) puts("Waste");
			else if(temp==1) puts("Carrots");
			else if(temp==2) puts("Kiwis");
			else if(temp==0) puts("Grapes");
		}
	}
    return 0;
}