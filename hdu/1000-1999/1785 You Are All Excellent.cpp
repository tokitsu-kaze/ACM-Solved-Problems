////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 16:57:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1785
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1460KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
struct student
{
	double x,y,t;
}stu[105];
bool cmp(student a,student b)
{
	return a.t>b.t;
}
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		if(n<0) break;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&stu[i].x,&stu[i].y);
			stu[i].t=stu[i].x/stu[i].y;
		}
		sort(stu,stu+n,cmp);
		for(i=0;i<n;i++)
		{
			printf("%.1lf %.1lf",stu[i].x,stu[i].y);
			if(i!=n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}