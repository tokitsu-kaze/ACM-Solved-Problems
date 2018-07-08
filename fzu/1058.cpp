#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <list> 
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
int main()  
{
	int n,i;
	double sum;
	while(cin>>n)
	{	
		sum=0;
		for(i=n;i>=1;i--)
		{
			sum+=(double)1/i;
		}
		printf("%.12lf\n",sum);
    }
    return 0;  
}  