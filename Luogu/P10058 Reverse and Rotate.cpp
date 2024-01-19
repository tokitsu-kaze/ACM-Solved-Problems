#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
char s[MAX];
int main()
{
	int n,m,x,now,f,i,j;
	char op[5];
	scanf("%s",s);
	n=strlen(s);
	now=f=0;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",op);
		if(op[0]=='r')
		{
			f^=1;
			now=n-1-now;
		}
		else
		{
			scanf("%d",&x);
			if(op[0]=='<') now-=x;
			else now+=x;
			now=(now%n+n)%n;
		}
	}
	string ra,rb;
	j=0;
	if(f)
	{
		for(i=now;~i;i--) ra+=s[j++];
		reverse(ra.begin(),ra.end());
		for(i=n-1;i>now;i--) rb+=s[j++];
		reverse(rb.begin(),rb.end());
	}
	else
	{
		for(i=now;i<n;i++) rb+=s[j++];
		for(i=0;i<now;i++) ra+=s[j++];
	}
	cout<<ra+rb<<"\n";
	return 0;
}
