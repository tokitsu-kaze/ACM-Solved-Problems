#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
char s[MAX];
int tag[105];
int main()
{
	int n,i,j,ans,x;
	memset(tag,0,sizeof tag);
	tag[0]=tag[1]=1;
	for(i=2;i<=99;i++)
	{
		for(j=i+i;j<=99;j+=i) tag[j]=1;
	}
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	for(i=1;i<n;i++)
	{
		x=(s[i]-'0')*10+s[i+1]-'0';
		if(!tag[x]) ans+=x;
	}
	printf("%d\n",ans);
	return 0;
}
