#include <bits/stdc++.h>
using namespace std;
const int mod=10007;
char s[505];
int main()
{
	int n,i,len;
	scanf("%s",s);
	len=strlen(s);
	n=0;
	for(i=0;i<len;i++) n=(n*10+s[i]-'0')%mod;
	printf("%lld\n",(1LL*n*(n+1)*(n+2)/6)%mod);
	return 0;
}
