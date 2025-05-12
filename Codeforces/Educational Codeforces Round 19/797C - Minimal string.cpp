#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX],mn[MAX],st[MAX];
int top;
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	mn[n]=s[n];
	for(i=n-1;i;i--) mn[i]=min(mn[i+1],s[i]);
	top=0;
	string res;
	for(i=1;i<=n;i++)
	{
		st[top++]=s[i];
		while(top && st[top-1]<=mn[i+1])
		{
			res+=st[top-1];
			top--;
		}
	}
	while(top>0) res+=st[--top];
	cout<<res<<"\n";
	return 0;
}
