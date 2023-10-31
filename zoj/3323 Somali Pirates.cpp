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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,i,k;
	char a[55],ans[55];
	while(~scanf("%d",&t))
	{
		getchar();
		while(t--)
		{
			gets(a);
			mem(ans,0);
			k=0;
			for(i=0;i<strlen(a);i++)
			{
				if(a[i]>='0'&&a[i]<='9');
				else ans[k++]=a[i];
			}
			ans[k]='\0';
			puts(ans);
		}
	}
	return 0;
}