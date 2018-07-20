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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int cnt,k,i;
	char a[5],b[5],ans[1111][5];
	while(~scanf("%s %s",a,b))
	{
		cnt=0;
		mem(ans,0);
		while(a[0]!=b[0]||a[1]!=b[1])
		{
			k=0;
			if(a[0]<b[0])
			{
				ans[cnt][k++]='R';
				a[0]++;
			}
			else if(a[0]>b[0])
			{
				ans[cnt][k++]='L';
				a[0]--;
			}
			if(a[1]<b[1])
			{
				ans[cnt][k++]='U';
				a[1]++;
			}
			else if(a[1]>b[1])
			{
				ans[cnt][k++]='D';
				a[1]--;
			}
			cnt++;
		}
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			puts(ans[i]);
		}
	}
	return 0;
}