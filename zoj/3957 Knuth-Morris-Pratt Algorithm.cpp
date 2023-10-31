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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,cnt;
	char a[1111];
	while(~scanf("%d ",&t))
	{
		while(t--)
		{
			gets(a);
			cnt=0;
			for(int i=0;i<strlen(a)-2;i++)
			{
				if((a[i]=='c'&&a[i+1]=='a'&&a[i+2]=='t')||(a[i]=='d'&&a[i+1]=='o'&&a[i+2]=='g')) cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}