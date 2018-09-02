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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int mp[10010][15][35];
int cnt[10010][15][35];
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int cal(int y,int m,int d)
{
	char res[11];
	mem(res,0);
	sprintf(res,"%d%d%d",y,m,d);
	int dp[3],flag[3],len;
	mem(dp,0);
	mem(flag,0);
	len=strlen(res);
	for(int i=0;i<len;i++)
	{
		if(res[i]=='5')
		{
			dp[0]++;
			flag[0]++;
		}
		else if(res[i]=='2')
		{
			dp[1]+=dp[0];
			flag[1]++;
		}
		else if(res[i]=='0')
		{
			dp[2]+=dp[1];
			flag[2]++;
		}
	}
	if(dp[2]) return 5;
	if(flag[0]&&flag[1]&&flag[2]) return 1;
	return 0;
}
void init()
{
	int i,j,k,sum=0,flagy,flagm;
	mem(mp,0);
	mem(cnt,0);
	for(i=1;i<=9999;i++)
	{
		flagy=0;
		if(cal(i,1,1)==5) flagy=5;
		for(j=1;j<=12;j++)
		{
			int temp=a[j];
			flagm=0;
			if(!flagy)
			{
				if(cal(i,j,1)==5) flagm=5;
			}
			if(j==2)
			{
				if((i%4==0&&i%100!=0)||(i%400==0))
				{
					temp++;
				}
			}
			for(k=1;k<=temp;k++)
			{
				if(flagy||flagm) cnt[i][j][k]=5;
				else cnt[i][j][k]=cal(i,j,k);
				sum+=cnt[i][j][k];
				mp[i][j][k]=sum;
			}
		}
	}
}
int main()
{
//	cout<<cal(2150,10,2)<<endl;
//	cout<<cal(2152,10,2)<<endl;
	init();
	int y1,m1,d1,y2,m2,d2;
	while(~scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2))
	{
		printf("%d\n",mp[y2][m2][d2]-mp[y1][m1][d1]+cnt[y1][m1][d1]);
	}
	return 0;
}
/*
1234 1 1 5679 2 3

*/