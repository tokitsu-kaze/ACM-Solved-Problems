#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i;
	char mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		mn='9';
		for(i=n;i;i--)
		{
			if(s[i]>mn) s[i]=min((char)(s[i]+1),'9');
			mn=min(mn,s[i]);
		}
		sort(s+1,s+1+n);
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
/*
一个数字后面有比他小的就要动。
由于可以自行决定插入的位置，所以直接在最后sort即可。
*/
