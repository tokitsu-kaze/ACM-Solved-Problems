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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int c,v0,v1,a,l,cnt,now;
	while(~scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l))
	{
		cnt=0;
		now=0;
		while(now<c)
		{
			if(now) now-=l;
			int temp=v0+a*cnt;
			if(temp>v1) temp=v1;
			now+=temp;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}