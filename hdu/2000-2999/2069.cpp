////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-20 15:48:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1588KB
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
using namespace std;
int main()
{
	int n,i,j,k,l,count;
	while(cin>>n)
	{
		count=0;
		for(i=0;i*50<=n;i++)
		{
			for(j=0;j*25<=n;j++)
			{
				for(k=0;k*10<=n;k++)
				{
					for(l=0;l*5<=n;l++)
					{
						if(n-i*50-j*25-k*10-l*5>=0&&i+j+k+l+(n-i*50-j*25-k*10-l*5)<=100)
						{
							count++;
						}
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}