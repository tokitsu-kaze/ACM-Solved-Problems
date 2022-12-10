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
const int MAX=1500+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int i,j,k,len,flag;
	char a[22],b[22],temp;
	while(~scanf("%s",a))
	{
		len=strlen(a);
		flag=0;
		for(i=0;i<len&&!flag;i++)
		{
			for(j=0;j<26&&!flag;j++)
			{
				temp=a[i];
				strcpy(b,a);
				if(b[i]!='a'+j) b[i]='a'+j;
				else continue;
				a[i]=b[i];
				reverse(b,b+len);
				if(strcmp(a,b)==0) flag=1;
				a[i]=temp;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}