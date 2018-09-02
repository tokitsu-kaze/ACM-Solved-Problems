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
#define pi acos(-1.0) 
using namespace std;
int main()
{
	int t,k,i,a,b;
	double sum;
	while(cin>>t)
	{
		for(k=1;k<=t;k++)
		{
			sum=0;
			for(i=2;i<=5;i++)
			{
				cin>>a>>b;
				if(i*500*((double)(250-a)/250)-50*b<i*500*0.4) sum+=i*500*0.4;
				else sum+=i*500*((double)(250-a)/250)-50*b;
			}
			printf("Case #%d: %.0lf\n",k,sum);
		}
	}
	return 0;
}