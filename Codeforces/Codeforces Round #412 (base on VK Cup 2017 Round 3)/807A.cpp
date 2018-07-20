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
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int n,i,a,b,flag,t;
	while(~scanf("%d",&n))
	{
		flag=2;
		t=INF;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a!=b) flag=1;
			if(flag==2&&a>t) flag=0;
			t=min(t,a);
		}
		if(!flag) puts("unrated");
		else if(flag==1) puts("rated");
		else puts("maybe");
	}
	return 0;
}