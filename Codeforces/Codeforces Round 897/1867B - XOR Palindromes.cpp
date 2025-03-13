#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int main()
{
	int T,n,i,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		cnt=0;
		for(i=1;i<=n/2;i++) cnt+=(s[i]!=s[n-i+1]);
		string res="";
		for(i=0;i<=n;i++) res+="0";
		for(i=cnt;i<=n-cnt;i+=2)
		{
			res[i]='1';
			if(i+1<=n && (n&1)) res[i+1]='1';
		}
		puts(res.c_str());
	}
	return 0;
}
