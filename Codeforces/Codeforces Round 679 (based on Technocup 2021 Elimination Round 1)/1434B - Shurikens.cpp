#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int st[MAX],top,v[MAX];
char op[MAX][2];
int main()
{
	int n,i,x,ok;
	scanf("%d",&n);
	top=0;
	ok=1;
	for(i=1;i<=2*n;i++)
	{
		scanf("%s",op[i]);
		if(op[i][0]=='+') st[top++]=i;
		else
		{
			scanf("%d",&x);
			if(top>0)
			{
				v[st[top-1]]=x;
				top--;
			}
			else ok=0;
		}
	}
	vector<int> res;
	top=0;
	for(i=1;i<=2*n;i++)
	{
		if(op[i][0]=='+')
		{
			if(top>0)
			{
				if(v[st[top-1]]<v[i]) ok=0;
			}
			st[top++]=i;
			res.push_back(v[i]);
		}
		else top--;
	}
	if(ok)
	{
		puts("YES");
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	}
	else puts("NO");
	return 0;
}
/*
先模拟一遍给所有手里剑标价格，
再模拟一遍看看栈里是不是递减的。
*/
