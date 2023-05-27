////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-06 15:20:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2141
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:3588KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
const int MAX=501;
__int64 s[3][MAX];
__int64 A[300000];
using namespace std;
int main()
{
	__int64 a,b,c,v,i,j,t,p,k;
	int find(__int64 *A,int x,int y,int v);
	int num;
	k=1;
	while(cin>>a>>b>>c)
	{
		for(i=0;i<a;i++)
		scanf("%I64d",&s[0][i]);
		for(i=0;i<b;i++)
		scanf("%I64d",&s[1][i]);
		for(i=0;i<c;i++)
		scanf("%I64d",&s[2][i]);
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				A[i*b+j]=s[0][i]+s[1][j];
			}
		}
		sort(A,A+a*b);
		printf("Case %d:\n",k++);
		scanf("%d",&num);
		while(num--)
		{
			scanf("%d",&v);
			p=0;
			for(j=0;j<c;j++)
			{
				t=v-s[2][j];
				p=find(A,0,a*b,t);
				if(p)
				break;
			}
			if(p)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
	return 0;
}
int find(__int64 *A,int x,int y,int v)
{
	int mid; 
	while(x<=y)
	{
		mid=(x+y)/2;
		if(A[mid]==v)
		return 1;
		else if(A[mid]>v)
		y=mid-1;
		else if(A[mid]<v)
		x=mid+1;
	}
	return 0;
}