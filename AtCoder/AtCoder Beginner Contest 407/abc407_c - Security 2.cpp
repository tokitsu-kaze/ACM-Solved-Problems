#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
char s[MAX];
int main()
{
	int n,i,now,ans,tmp;
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=now=0;
	for(i=n;i;i--)
	{
		tmp=(s[i]-'0'-now+10)%10;
		ans+=tmp;
		now=(now+tmp)%10;
//		cout<<i<<" "<<tmp<<endl;
	}
	printf("%d\n",ans+n);
	return 0;
}
