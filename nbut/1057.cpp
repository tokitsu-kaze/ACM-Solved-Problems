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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int i,sum,n,len;
    char c[10001];
    while(~scanf("%d",&n))
    {
		getchar();
        while(n--)
        {
			gets(c);
			len=strlen(c);
			sum=1;
			for(i=0;i<len;i++)
			{
				while(c[i]==c[i+1])
				{
					sum++;
					i++;
				}
				if(sum>1)
				{
					printf("%d%c",sum,c[i]);
					sum=1;
				}
				else printf("%c",c[i]);
			}
			printf("\n");
		}
    }
    return 0;
}