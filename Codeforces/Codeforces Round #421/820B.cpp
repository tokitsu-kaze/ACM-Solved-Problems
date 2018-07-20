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
const ll mod=1e9+7;
int main()
{
	int i,j,n,pos;
	double a,ang,ans;
	while(~scanf("%d%lf",&n,&a))
	{
		ans=INF;
		pos=n;
		ang=360.0/n/2;
		for(i=n,j=1;i>=3;i--,j++)
		{
			double temp=fabs(j*ang-a);
			if(temp<ans)
			{
				ans=temp;
				pos=i;
			}
		}
		printf("1 2 %d\n",pos);
	}
	return 0;
}