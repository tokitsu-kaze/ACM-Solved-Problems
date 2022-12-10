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
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int cnt=0,flag=0,i,p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	char op[111];
	for(i=0;i<20;i++)
	{
		cnt++;
		printf("%d\n",p[i]);
		fflush(stdout);
		scanf("%s",op);
		if(op[0]=='y')
		{
			flag++;
			if(p[i]<10)
			{
				cnt++;
				printf("%d\n",p[i]*p[i]);
				fflush(stdout);
				scanf("%s",op);
				if(op[0]=='y') flag++;
			}
		}
		if(cnt==20) break;
		if(flag>=2) break;
	}
	if(flag>=2) puts("composite");
	else puts("prime");
	return 0;
}