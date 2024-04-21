#include<bits/stdc++.h>
using namespace std;
char s[105][105],tmp[105];
int tot[105];
int main()
{
	int t,i,j,len;
	scanf("%d",&t);
	memset(tot,0,sizeof tot);
	for(i=0;i<t;i++)
	{
		scanf("%s",tmp);
		len=strlen(tmp);
		for(j=0;j<len;j++)
		{
			s[j][tot[j]++]=tmp[j];
		}
	}
	for(i=0;i<t;i++)
	{
		s[i][tot[i]]='\0';
		string a,b;
		a=string(s[i]);
		b=a;
		reverse(b.begin(),b.end());
		if(a==b) puts("YES");
		else puts("NO");
	}
	return 0;
}
