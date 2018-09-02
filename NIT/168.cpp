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
const int MAX=1000000+10;
const ll mod=1e6;
int main()
{
	double b[]={5,20,100,400,50,100,400,1600};
	double a[11];
	double s;
	while(~scanf("%lf",&a[0]))
	{
		for(int i=1;i<8;i++)
		{
			scanf("%lf",&a[i]);
		}
		s=0;
		for(int i=0;i<8;i++)
		{
			s+=a[i]*b[i];
		}
		s*=5;
		printf("%.2lf\n",s+eps);
	}
	return 0;
}