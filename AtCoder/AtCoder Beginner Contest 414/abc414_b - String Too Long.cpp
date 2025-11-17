#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int main()
{
	int n,i;
	ll len;
	char s[2];
	scanf("%d",&n);
	string res="";
	for(i=1;i<=n;i++)
	{
		scanf("%s%lld",s,&len);
		while(len>0)
		{
			if(res.size()>101) break;
			res+=s[0];
			len--;
		}
	}
	if(res.size()<=100) cout<<res<<"\n";
	else puts("Too Long");
	return 0;
}
