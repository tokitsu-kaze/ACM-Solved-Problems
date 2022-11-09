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
#define MAX 500000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
char c[MAX];
typedef long long ll;
int main()
{
	int n,i,len,flag;
	char a[111],ans[111];
	while(~scanf("%d",&n))
	{
		mem(a,0);
		mem(ans,0);
		itoa(n,a,10);
		len=strlen(a);
		if(len%2) len++;
		for(i=0;i<len/2;i++)
		{
			ans[i]='4';
		}
		for(i=len/2;i<len;i++)
		{
			ans[i]='7';
		}
		flag=0;
		
		do
		{
			if(atof(ans)>=n)
			{
				flag=1;
				break;
			}
			
		}while(next_permutation(ans,ans+len));
		if(!flag)
		{
			printf("44");
			len=len+2;
			len/=2;
			for(i=0;i<len-2;i++)
			{
				printf("4");
			}
			for(i=0;i<len;i++)
			{
				printf("7");
			}
			puts("");
		}
		else printf("%s\n",ans);
	}
    return 0;
}