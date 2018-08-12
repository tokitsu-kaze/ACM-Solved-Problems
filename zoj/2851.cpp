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
#define eps 1e-12
#define MAX 200+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
//	freopen("in.txt","r",stdin);	
	int t,cnt1,cnt2,i,t1,t2;
	char a[111];
    while(~scanf("%d",&t))
    {
		getchar();
		while(t--)
		{
			cnt1=cnt2=0;
			while(gets(a))
			{
				if(strcmp(a,"##")==0) break;
				t1=t2=0;
				for(i=0;i<strlen(a);i++)
				{
					if(a[i]=='\t') t1++;
					if(a[i]==' ') t2++;
					else if(a[i]=='\t') t2+=4;
					if(a[i]!=' '&&a[i]!='\t') t2=0;
				}
				cnt1+=t1;
				cnt2+=t2;
			}
			printf("%d tab(s) replaced\n",cnt1);
			printf("%d trailing space(s) removed\n",cnt2);
		}
	}
    return 0;
}