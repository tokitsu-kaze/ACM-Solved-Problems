#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
	int n,k,i,j,a,b;
	while(~scanf("%d%d",&n,&k))
	{
		a=b=1;
		for(i=0,j=n;i<k;i++,j--)
		{
			a*=j;
		}
		for(i=k;i>=2;i--)
		{
			b*=i;
		}
		printf("%d\n",a/b);
	}
	return 0;
}