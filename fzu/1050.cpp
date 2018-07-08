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
	int n,cnt;
	double temp;
	while(~scanf("%d",&n))
	{
		cnt=1;
		temp=1;
		while(n)
		{
			temp*=n;
			while(temp>=10)
			{
				temp/=10;
				cnt++;
			}
			n--;
		}
		printf("%d\n",cnt);
	}
	return 0;
}