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
const int MAX=20000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int i,n,s,e,w;
	char a[1111];
	while(~scanf("%s",a))
	{
		n=s=e=w=0;
		for(i=0;i<strlen(a);i++)
		{
			
			if(a[i]=='N')
			{
				n=1;
			}
			else if(a[i]=='S')
			{
				s=1;
			}
			else if(a[i]=='E')
			{
				e=1;
			}
			else if(a[i]=='W')
			{
				w=1;
			}
		}
		if((n+s==2&&e+w==0)||(n+s==0&&e+w==2)||n+s+e+w==4) puts("Yes");
		else puts("No");
	}
	return 0;
}
