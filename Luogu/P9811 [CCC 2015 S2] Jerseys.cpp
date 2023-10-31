#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
char s[MAX][2];
int id[256];
int main()
{
	int n,m,i,ans,x;
	char tmp[2];
	memset(id,0,sizeof id);
	id['S']=1;
	id['M']=2;
	id['L']=3;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",s[i]);
	ans=0;
	while(m--)
	{
		scanf("%s%d",tmp,&x);
		if(id[s[x][0]]>=id[tmp[0]])
		{
			ans++;
			s[x][0]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
