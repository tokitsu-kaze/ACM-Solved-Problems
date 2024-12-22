#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2000+10;
int dp[MAX][MAX];
char a[MAX],b[MAX],c[MAX];
int main()
{
	int T,lena,lenb,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);
		scanf("%s",b+1);
		scanf("%s",c+1);
		lena=strlen(a+1);
		lenb=strlen(b+1);
		for(i=0;i<=lena;i++)
		{
			for(j=0;j<=lenb;j++)
			{
				dp[i][j]=INF;
			}
		}
		dp[0][0]=0;
		for(i=0;i<=lena;i++)
		{
			for(j=0;j<=lenb;j++)
			{
				if(i==0 && j==0) continue;
				if(i==0) dp[i][j]=dp[i][j-1]+(b[j]!=c[i+j]);
				else if(j==0) dp[i][j]=dp[i-1][j]+(a[i]!=c[i+j]);
				else dp[i][j]=min(dp[i-1][j]+(a[i]!=c[i+j]),
								  dp[i][j-1]+(b[j]!=c[i+j]));
			}
		}
		printf("%d\n",dp[lena][lenb]);
	}
	return 0;
}

