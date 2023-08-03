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
const int MAX=1000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int i,len,flag;
	char a[111],b[111],ans[111];
	while(~scanf("%s %s",a,b))
	{
		flag=0;
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(b[i]>a[i]) flag=1;
			else if(b[i]==a[i]) ans[i]='z';
			else if(b[i]<a[i]) ans[i]=b[i];
		}
		if(flag) puts("-1");
		else
		{
			ans[len]='\0';
			puts(ans);
		}
	}
	return 0;
}