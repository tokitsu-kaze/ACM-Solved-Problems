#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int ck(int x)
{
	string s=to_string(x);
	int sum=0;
	for(auto &it:s) sum+=it-'0';
	if(x%sum==0) return 1;
	return 0;
}
void bf(int x)
{
	int i;
	for(i=x;i<2*x;i++)
	{
		if(ck(i) && ck(i+1))
		{
			printf("%d\n",i);
			return;
		}
	}
	puts("-1");
}
char s[MAX];
int main()
{
	int n,i,now,zr;
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n<=6)
	{
		now=0;
		for(i=1;i<=n;i++) now=now*10+s[i]-'0';
		bf(now);
		return 0;
	}
	string ra;
	if(s[1]>='6')
	{
		ra+="1";
		for(i=1;i<=n-2;i++) ra+="0";
		ra+="10";
	}
	else if(s[1]=='5')
	{
		ra+="8";
		for(i=2;i<=n;i++) ra+="0";
	}
	else if(s[1]=='4')
	{
		zr=0;
		for(i=2;i<=n;i++) zr+=(s[i]=='0');
		if(zr==n-1)
		{
			ra+="44";
			for(i=3;i<=n;i++) ra+="0";
		}
		else
		{
			ra+="8";
			for(i=2;i<=n;i++) ra+="0";
		}
	}
	else if(s[1]=='3')
	{
		ra+="44";
		for(i=3;i<=n;i++) ra+="0";
	}
	else if(s[1]=='2')
	{
		ra+="35";
		for(i=3;i<=n;i++) ra+="0";
	}
	else if(s[1]=='1')
	{
		if(s[2]=='0')
		{
			ra+="11";
			for(i=3;i<=n;i++) ra+="0";
		}
		else
		{
			ra+="2";
			for(i=2;i<=n;i++) ra+="0";
		}
	}
	cout<<ra<<"\n";
	return 0;
}
