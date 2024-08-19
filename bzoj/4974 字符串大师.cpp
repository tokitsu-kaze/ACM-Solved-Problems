#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int nex[MAX];
char s[MAX];
int main()
{
	int n,i,j,ban[33];
	scanf("%d",&n);
	nex[0]=0;
	s[1]='a';
	scanf("%d",&nex[1]);
	nex[1]=1-nex[1];
	for(i=2;i<=n;i++)
	{
		scanf("%d",&nex[i]);
		nex[i]=i-nex[i];
		if(!nex[i])
		{
			memset(ban,0,sizeof ban);
			for(j=nex[i-1];j;j=nex[j]) ban[s[j+1]-'a']=1;
			ban[s[1]-'a']=1;
			for(j=0;j<26;j++)
			{
				if(!ban[j])
				{
					s[i]=j+'a';
					break;
				}
			}
		}
		else s[i]=s[nex[i]];
	}
	s[n+1]=0;
	puts(s+1);
	return 0;
}
