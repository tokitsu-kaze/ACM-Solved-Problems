////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 21:37:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1716
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[4],b[24],flag=0,i,j;
	while (cin>>a[0]>>a[1]>>a[2]>>a[3])
	{
		if(a[0]+a[1]+a[2]+a[3]==0) break;
		if (flag!=0)
		{
			cout<<endl;
		}
		flag=1;
		i=0;
		sort(a,a+4);
		do
		{
			if(a[0]) b[i++]=a[0]*1000+a[1]*100+a[2]*10+a[3];
		}
		while(next_permutation(a,a+4));
		for(j=0;j<i;j++)
		{
			if(j+1==i) cout<<b[j]<<endl;
			else if(b[j]/1000==b[j+1]/1000) cout<<b[j]<<" ";
			else cout<<b[j]<<endl;
		}
	}
	return 0;
}