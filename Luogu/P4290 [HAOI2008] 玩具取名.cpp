#include <bits/stdc++.h>
using namespace std;
const string tmp="WING";
int get_id(char c)
{
	for(int i=0;i<4;i++)
	{
		if(c==tmp[i]) return i;
	}
	assert(0);
	return -1;
}
int flag[4][4][4],dp[205][205][5];
int main()
{
	int a,b,c,d,i,len,l,r,n;
	char s[205];
	memset(flag,0,sizeof flag);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(a--)
	{
		scanf("%s",s);
		flag[0][get_id(s[0])][get_id(s[1])]=1;
	}
	while(b--)
	{
		scanf("%s",s);
		flag[1][get_id(s[0])][get_id(s[1])]=1;
	}
	while(c--)
	{
		scanf("%s",s);
		flag[2][get_id(s[0])][get_id(s[1])]=1;
	}
	while(d--)
	{
		scanf("%s",s);
		flag[3][get_id(s[0])][get_id(s[1])]=1;
	}
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i][get_id(s[i])]=1;
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(i=l;i<r;i++)
			{
				for(a=0;a<4;a++)//[l,r] -> a
				{
					for(b=0;b<4;b++)//[l,i] -> b
					{
						for(c=0;c<4;c++)//[i+1,r] -> c
						{
							dp[l][r][a]|=(dp[l][i][b]&dp[i+1][r][c]&flag[a][b][c]);
						}
					}
				}
			}
			
		}
	}
	string res;
	for(i=0;i<4;i++)
	{
		if(dp[1][n][i]) res+=tmp[i];
	}
	if(res.size()==0) puts("The name is wrong!");
	else cout<<res<<"\n";
	return 0;
}
