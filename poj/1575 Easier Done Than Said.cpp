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
	int i,len,flag,a,b;
    char c[10001];
    while(gets(c))
    {
		if(strcmp(c,"end")==0) break;
		len=strlen(c);
		flag=a=b=0;
		for(i=0;i<len;i++)
		{
			if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u')
			{
				flag=1;
				a++;
				b=0;
			}
			else
			{
				a=0;
				b++;
			}
			if((a==2||b==2)&&(c[i]==c[i-1]&&(c[i]!='e'&&c[i]!='o'))||a==3||b==3) break;
		}
		if(flag==1&&i==len) printf("<%s> is acceptable.\n",c);
		else printf("<%s> is not acceptable.\n",c);
    }
    return 0;
}