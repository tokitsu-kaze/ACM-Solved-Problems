#include <bits/stdc++.h>
using namespace std;
string a;
string b;
set<int>se[500];
const int maxn=(int)1e5+10;
long long  nextTo[maxn][30];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		cin>>a>>b;
		for(int i='a';i<='z';i++)
		{
			se[i-'a'].clear();
		}
		for(int i=0;i+k-1<n;i++)
		{
			se[a[i]-'a'].insert(a[i+k-1]-'a');
		}
		for(int i=0;i<26;i++)
			nextTo[m][i]=0;
		memset(nextTo,0,sizeof(nextTo));
		for(int i=m-1;i>=0;i--)
		{
			for(int j=0;j<=26;j++)
			{
				nextTo[i][j]=nextTo[i+1][j] + (b[i]-'a'==j);
			}
		}
		long long sum=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<=26;j++)
			{
				if(se[b[i]-'a'].count(j))
				{
					sum+=nextTo[i][j];
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}