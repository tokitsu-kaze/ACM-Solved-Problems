#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,l,r,now,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		l=r=n/2;
		vector<int> pos;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='(') l--;
			else if(s[i]==')') r--;
			else pos.push_back(i);
		}
		if(l==0 || r==0)
		{
			puts("YES");
			continue;
		}
		for(i=0;i<l;i++) s[pos[i]]='(';
		for(i=l;i<l+r;i++) s[pos[i]]=')';
		swap(s[pos[l-1]],s[pos[l]]);
		now=0;
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='(') now++;
			else now--;
			if(now<0) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
有第二种情况等价于至少有分别一个左右括号要翻转。
贪心考虑，尽可能晚将+1改-1，尽可能早将-1改+1。
换句话说，翻转会影响一段区间，这样能影响最短的区间。
实现方面：
题目保证一定有合法状态，左右括号数一致。
计算左括号需要多少个，右括号需要多少个，前面全填左，后面全填右。
然后将最后一个左改右，第一个右改左，check一遍。
*/
