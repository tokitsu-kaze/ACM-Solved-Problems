#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,m,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		reverse(s+1,s+1+n);
		reverse(t+1,t+1+m);
		i=j=1;
		while(i<=n && j<=m)
		{
			if(s[i]==t[j])
			{
				i++;
				j++;
			}
			else i+=2;
		}
		if(j<=m) puts("NO");
		else puts("YES");
	}
	return 0;
}
/*
考虑倒着匹配。
退格操作实际上是跳过偶数个字符，
如果当前不匹配，那就必须使用退格操作。
否则能匹配尽量匹配。
那有没有一种可能，当前虽然能够匹配上，但是跳过匹配会更优？
要知道，跳过匹配一定要使用退格操作，
这样不会改变当前需要匹配的位置的奇偶性，
也就是说，第 i 个字符一定匹配奇数/偶数位的字符，
换句话说，每个字符要匹配的位置是固定的，要么全奇要么全偶
跳过一个不会改变匹配位置的奇偶性，所以不可能变优。
*/
