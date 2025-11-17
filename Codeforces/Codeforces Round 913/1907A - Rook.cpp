#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,i;
	char s[11];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		for(i=1;i<s[1]-'0';i++) printf("%c%d\n",s[0],i);
		for(i=s[1]-'0'+1;i<=8;i++) printf("%c%d\n",s[0],i);
		for(i='a';i<s[0];i++) printf("%c%c\n",i,s[1]);
		for(i=s[0]+1;i<='h';i++) printf("%c%c\n",i,s[1]);
	}
	return 0;
}
