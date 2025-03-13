#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX];
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=n-1;i;i--)
	{
		if(s[i]=='W' && s[i+1]=='A')
		{
			s[i]='A';
			s[i+1]='C';
		}
	}
	s[n+1]='\0';
	puts(s+1);
	return 0;
}
