#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	long long i,k,l,flag1,flag2;
	double m,n;
	char a[31],b[31],c[31],d[31];
	while(~scanf("%s %s",a,b))
	{
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		l=k=flag1=flag2=0;
		for(i=0;i<strlen(a);i++)
		{
			if(isdigit(a[i]))
			{
				c[k++]=a[i];
				flag1=1;
			}
		}
		for(i=0;i<strlen(b);i++)
		{
			if(isdigit(b[i]))
			{
				d[l++]=b[i];
				flag2=1;
			}
		}
		if(flag1) m=atof(c);
		else m=214216;
		if(flag2) n=atof(d);
		else n=214216;
		if(m==0) m=214216;
		if(n==0) n=214216;
		printf("%.0lf\n",m*n);
	}
	return 0;
}