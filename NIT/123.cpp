#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define pi acos(-1.0)
using namespace std;
int main()
{
	double r,n,l;
	while(cin>>r>>n)
	{
		printf("%.6lf\n",r/(1/sin(pi/n)+1));
	}
}