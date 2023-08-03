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
const int MAX=1000000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int t,m,n,cas;
	double ans;
	while(~scanf("%d",&t))
	{
		cas=1;
		while(t--)
		{
			scanf("%d%d",&m,&n);
			if(m%2&&n%2) ans=1.0*m*n+0.41;
			else ans=1.0*m*n;
			printf("Scenario #%d:\n",cas++);
			printf("%.2f\n",ans);
			puts("");
		}
	}
	return 0;
}
