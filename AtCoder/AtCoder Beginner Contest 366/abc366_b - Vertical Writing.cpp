#include <bits/stdc++.h>
using namespace std;
char mp[105][105];
int main()
{
	string s[105];
	int n,i,j,k,l,ok;
	memset(mp,0,sizeof mp);
	cin>>n;
	for(i=0;i<n;i++) cin>>s[i];
	for(i=n-1,l=0;~i;i--,l++)
	{
		for(j=0,k=0;j<s[i].size();j++,k++)
		{
			mp[k][l]=s[i][j];
		}
	}
	for(i=0;i<=100;i++)
	{
		ok=0;
		for(j=100;~j;j--)
		{
			if(ok&&!mp[i][j]) mp[i][j]='*';
			if(mp[i][j]) ok=1;
		}
	}
	for(i=0;i<=100;i++)
	{
		if(mp[i][0]) puts(mp[i]);
	}
	return 0;
}
