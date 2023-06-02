////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 16:31:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2629
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n=0,i;
	char a[100];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a);
		printf("He/She is from ");
        if(a[0]=='3'&&a[1]=='3') printf("Zhejiang,"); 
        else if(a[0]=='1'&&a[1]=='1') printf("Beijing,");
        else if(a[0]=='7'&&a[1]=='1') printf("Taiwan,");   
        else if(a[0]=='8'&&a[1]=='1') printf("Hong Kong,");      
        else if(a[0]=='8'&&a[1]=='2') printf("Macao,");
        else if(a[0]=='5'&&a[1]=='4') printf("Tibet,");
        else if(a[0]=='2'&&a[1]=='1') printf("Liaoning,");
        else if(a[0]=='3'&&a[1]=='1') printf("Shanghai,");
		printf("and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",a[10],a[11],a[12],a[13],a[6],a[7],a[8],a[9]);
	}
	return 0;
}