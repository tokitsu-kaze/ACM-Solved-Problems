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
char s[100010];
long long dp[100010];
int main()
{
	long long t,n,a,b,i,j,k,sum,len;
	map<long long,long long> m;
	for(i='a',k=1;i<='z';i++)
	{
		m[i]=k++;
	}
	for(i='A';i<='Z';i++)
	{
		m[i]=k++;
	}
	while(cin>>t)
	{
		while(t--)
		{
			cin>>s;
			len=strlen(s);
			sum=0;
			memset(dp,0,sizeof(dp));
			for(i=0;i<len;i++)
			{
				
				sum^=1L<<m[s[i]];
				dp[i+1]=sum;
		//		cout<<dp[i+1]<<endl;
		//		cout<<endl;
			}
			cin>>n;
			while(n--)
			{
				scanf("%lld%lld",&a,&b);
				if(dp[a-1]!=dp[b]) puts("No");
				else puts("Yes");
			}
		}
	}
	
	return 0;
}