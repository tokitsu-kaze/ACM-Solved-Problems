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
void change(int b)
{
	if(b)
	{
		change((b-1)/26);
		putchar('A'+(b-1)%26);
	}
}
int main()
{
	int t,a,b,i,ans;
	char s[1111],*p;
	while(~scanf("%d ",&t))
	{
		while(t--)
		{
			gets(s);
			if(sscanf(s,"%*c%d%*c%d",&a,&b)==2)
			{
				change(b);
				printf("%d\n",a);
			}
			else
			{
				ans=0;
				for(p=s;*p>64;++p)
				{
					ans=ans*26+*p-'A'+1;
				}
				printf("R%sC%d\n",p,ans);
			}
		}
	}
	return 0;
}