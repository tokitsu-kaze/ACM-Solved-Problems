////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-30 10:18:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
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
	int i,k;
	double b[201],a,sum;
	char c;
	while(cin>>a)
	{
		c=getchar();
		if (a==0&&c=='\n') break;
		k=sum=0;
		b[k++]=a;
		while(1)
		{
			scanf("%c %lf",&c,&a);
    		switch(c)
			{
	    		case '+':b[k++]=a;break;
        		case '-':b[k++]=-a;break;
        		case '*':b[k-1]*=a;break;
        		case '/':b[k-1]/=a;break;
			}
			if(getchar()=='\n') break;
		}
		for(i=0;i<k;i++)
		{
			sum+=b[i]; 
		}
		printf("%.2lf\n",sum);
	}
}