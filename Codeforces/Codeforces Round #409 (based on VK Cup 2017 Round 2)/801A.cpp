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
	int i,j,cnt,ans;
	char a[111],temp;
	while(~scanf("%s",a))
	{
		ans=0;
		cnt=0;
		for(j=1;j<strlen(a);j++)
		{
			if(a[j-1]=='V'&&a[j]=='K') cnt++;
		}
		ans=max(ans,cnt);
		for(i=0;i<strlen(a);i++)
		{
			temp=a[i];
			if(temp=='V') a[i]='K';
			else a[i]='V';
			cnt=0;
			for(j=1;j<strlen(a);j++)
			{
				if(a[j-1]=='V'&&a[j]=='K') cnt++;
			}
			ans=max(ans,cnt);
			a[i]=temp;
		}
		printf("%d\n",ans);
	}
	return 0;
}