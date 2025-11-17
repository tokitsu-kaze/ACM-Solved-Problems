#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
int main()
{
	int n,i,j,k,cnt;
	double ans;
	char s[105];
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+2;j<=n;j++)
		{
			cnt=0;
			if(s[i]==s[j] && s[i]=='t')
			{
				for(k=i;k<=j;k++)
				{
					if(s[k]=='t') cnt++;
				}
			}
			ans=max(ans,1.0*(cnt-2)/(j-i+1-2));
		}
	}
	printf("%.10f\n",ans);
	return 0;
}
