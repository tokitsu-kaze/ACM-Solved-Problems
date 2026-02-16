#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[105][105];
int main()
{
	int n,i,len,mxlen;
	scanf("%d",&n);
	mxlen=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		len=strlen(s[i]+1);
		mxlen=max(mxlen,len);
	}
	for(i=1;i<=n;i++)
	{
		string res="";
		len=strlen(s[i]+1);
		while(res.size()<(mxlen-len)/2) res+=".";
		res+=string(s[i]+1);
		while(res.size()<mxlen) res+=".";
		puts(res.c_str());
	}
	return 0;
}
