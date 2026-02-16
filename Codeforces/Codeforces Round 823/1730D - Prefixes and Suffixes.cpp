#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,i,ok,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		reverse(t+1,t+1+n);
		map<pair<char,char>,int> mp;
		for(i=1;i<=n;i++)
		{
			if(s[i]>t[i]) swap(s[i],t[i]);
			mp[{s[i],t[i]}]++;
		}
		ok=1;
		cnt=0;
		for(auto &it:mp)
		{
			if(it.second%2==0) continue;
			if(it.first.first!=it.first.second) ok=0;
			else cnt++;
		}
		if(cnt>1) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
原始操作比较别扭，先把 T 串 reverse 过来。
将 (Si,Ti) 捆绑，发现：
1.Si 和 Ti 可以随意swap
2.(Si,Ti) 二元组可以任意排列
问题转化成能否将 (Si,Ti) 二元组组成一个回文。
根据 (Si,Ti) 的个数奇偶性讨论，奇数情况 恰好有一个 Si=Ti。
*/
