#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,d,i,cnt;
	char s[111];
	scanf("%d%d",&n,&d);
	scanf("%s",s);
	for(i=n-1;~i;i--)
	{
		if(s[i]=='@')
		{
			if(d>0)
			{
				d--;
				s[i]='.';
			}
		}
	}
	s[n]='\0';
	puts(s);
	return 0;
}
