#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,x,ok,sum,now;
	scanf("%d%d",&n,&m);
	map<int,int> mp;
	sum=0;
	for(i=1;i<=2*n;i++)
	{
		scanf("%d",&x);
		sum=(sum+x)%m;
		mp[x*2%m]++;
	}
	ok=0;
	now=0;
	for(auto &it:mp)
	{
		if(it.second%2) ok=1;
		else now=(now+1LL*it.first*it.second/2)%m;
	}
	if(ok || now!=sum) puts("Alice");
	else puts("Bob");
	return 0;
}
/*
设 Sa,Sb 分别表示两个人拿的数的总和，sum 为所有数的总和。
Bob 的获胜条件为：Sa=Sb (mod m)。
由于 Sa+Sb=sum，推出 2*Sa=sum (mod m)。
问题转化成，将所有数字*2后，令 Alice 拿走 n 个数之和为 newSa，如果 Bob 能够“操控” Alice 的操作，使得 newSa=sum (mod m)，Bob 就能赢。
Bob 如何操控？如果 newSa=sum (mod m)，说明 Bob 拿走另外 n 个数之和 newSb 也满足 newSb=sum (mod m)。也就是说，Bob 只要模仿 Alice 做镜像操作就能尽可能地满足 newSa=sum (mod m)。
所以 Bob 要赢需要同时满足两个条件：
1.每一步 Bob 都能够完成镜像操作。
2.最后 newSa=sum (mod m)。

不*2的话，Bob 可以进行错位匹配，会使得情况变得复杂。
例子就是：
2 4
0 1 2 3
(0,2) 匹配，(1,3) 匹配，这样做镜像操作总能使得 Bob 获胜。

其实根据其他题解推出的 2a=2b (mod m) -> (x,x) 匹配，或者 (x,x+m/2) 匹配，在*2后能把 (x,x+m/2) 这种匹配方式消除掉。
*/
