#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=400+10;
int ask(string s)
{
	cout<<s<<endl;
	int res;
	cin>>res;
	return res;
}
int main()
{
	int n,i,pre,now;
	string s;
	pre=ask("a");
	if(pre==0) return 0;
	n=pre+1;
	if(n>300)
	{
		s="";
		for(i=0;i<n-1;i++) s+="b";
		ask(s);
		return 0;
	}
	s="";
	for(i=0;i<n;i++) s+="a";
	pre=ask(s);
	if(pre==0) return 0;
	if(pre==n)
	{
		s="";
		for(i=0;i<n-1;i++) s+="b";
		ask(s);
		return 0;
	}
	for(i=0;i<n-1;i++)
	{
		s[i]='b';
		now=ask(s);
		if(now==0) return 0;
		if(now>pre)
		{
			s[i]='a';
			now--;
		}
		pre=now;
	}
	if(pre) s[n-1]='b';
	ask(s);
	return 0;
}
/*
感觉做法很显然啊，先问一次a一次b，求出长度。
然后显然每个位置问一次，反正不是a就是b。
所以先全填一样的问一次，一个一个字符改一下问过去。
但发现这样是n+3次。
发现可以不用问两次单字母，可以先把全a或者全b判出来。
具体的，先问1个a得到k，再问k+1个a，结果等于k+1就是全b。
*/
