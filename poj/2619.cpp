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
using namespace std;
int main()
{
	int m,n,a1,a2,b1,b2,c1,c2;
	while(~scanf("%d%d",&m,&n))
	{
		a1=sqrt(m-1)+1;
		a2=sqrt(n-1)+1;
		b1=(m-(a1-1)*(a1-1)+1)/2;
		b2=(n-(a2-1)*(a2-1)+1)/2;
		c1=(a1*a1-m+2)/2;
		c2=(a2*a2-n+2)/2;
		printf("%d\n",abs(a1-a2)+abs(b1-b2)+abs(c1-c2));
	}
}