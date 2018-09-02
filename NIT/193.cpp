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
const double eps=1e-5;
const int MAX=1000000+10;
const ll mod=1e6;
double a,b,k;
double cal(double x)
{
	return a*x*x*x+b*x-k;
}
int main()
{
	double r,l,rm,lm,tl,tr;
	while(~scanf("%lf%lf%lf",&a,&b,&k))
	{
		l=-INF;
		r=INF;
		while(r-l>eps)  
		{  
			rm=(l+r)/2;  
			lm=(rm+r)/2;
			tl=cal(lm);
			tr=cal(rm);
			if(tr>0) r=lm;
			else l=rm;
		}
		printf("%.2lf\n",l);
	}
	return 0;
}