#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int a[510][510],n,m;
int search(int x,int y)
{
	int i,j,ans=0;
	for(i=1;i<=m;i++)
	{
		ans+=a[x][i];
	}
	for(j=1;j<=n;j++)
	{
		ans+=a[j][y];
	}
	return ans-a[x][y];
	
}
int main()
{
	int i,j,k,l,sum1,sum2,max1,max2,x,y,max3,temp,cas=1;
	while(cin>>n>>m)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		max1=max2=0;
		for(i=1;i<=n;i++)
		{
			sum1=0;
			for(j=1;j<=m;j++)
			{
				sum1+=a[i][j];
			}
			if(sum1>max1)
			{
				max1=sum1;
				x=i;
			}
			for(k=1;k<=m;k++)
			{
				sum2=0;
				for(l=1;l<=n;l++)
				{
					sum2+=a[l][k];
				}
				if(sum2>max2)
				{
					max2=sum2;
					y=k;
				}
			}
		}
	//	cout<<max1+max2-a[x][y]<<endl;
		max3=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				temp=search(i,j);
				if(temp>max3) max3=temp;
			}
		}
		printf("Case %d: ",cas++);
		if(max3==max1+max2-a[x][y]) puts("Weak");
		else puts("Strong");
	}
    return 0;
}