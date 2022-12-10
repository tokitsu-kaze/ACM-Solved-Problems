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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=10000;
int main()
{
	int n,i,stk[MAX],now,cnt,top;
	char op[111];
	while(~scanf("%d",&n))
	{
		n*=2;
		now=top=cnt=0;
		while(n--)
		{
			scanf("%s",op);
			if(op[0]=='a')
			{
				scanf("%d",&stk[++top]);
			}
			else
			{
				if(top)
				{
					if(stk[top]==now+1) top--;
					else
					{
						top=0;
						cnt++;
					}
				}
				now++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}