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
using namespace std;
int main()
{
	int a,b,i;
	double sum;
	while(cin>>a>>b)
	{
		sum=(double)a/100*b;
		for(i=0;i<11;i++)
		{
			cin>>a>>b;
			sum+=(double)a/100*b;
		}
		printf("%.2lf\n",sum);
	}
}