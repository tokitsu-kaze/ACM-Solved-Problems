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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=40000+10;
const ll mod=1e6;
int main()
{
	int n,m,flag;
	char a[111],b[111];
	while(~scanf("%d%d",&n,&m))
	{
		getchar();
		flag=0;
		while(m--)
		{
			scanf("%s %s",a,b);
			if(a[0]=='r'&&b[0]=='s')
			{
				n-=4;
				flag=1;
			}
			else if(b[0]=='r'&&a[0]=='s')
			{
				n-=4;
				flag=2;
			}
			else if(a[0]=='p'&&b[0]=='r')
			{
				n-=5;
				flag=1;
			}
			else if(b[0]=='p'&&a[0]=='r')
			{
				n-=5;
				flag=2;
			}
			else if(a[0]=='s'&&b[0]=='p')
			{
				n-=2;
				flag=1;
			}
			else if(b[0]=='s'&&a[0]=='p')
			{
				n-=2;
				flag=2;
			}
			else if(a[0]==b[0]) continue;
			if(n<=0) break;
		}
		if(flag==1) puts("Obj");
		else if(flag==2) puts("Tya");
	}
	return 0;
}