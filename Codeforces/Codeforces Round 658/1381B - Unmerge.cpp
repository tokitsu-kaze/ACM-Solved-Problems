#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4000+10;
int a[MAX],dp[MAX];
int main()
{
	int T,n,i,j,now,pre;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n*=2;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<int> res;
		pre=1;
		for(i=2;i<=n;i++)
		{
			if(a[i]>a[pre])
			{
				res.push_back(i-pre);
				pre=i;
			}
		}
		res.push_back(n-pre+1);
		for(i=0;i<=n;i++) dp[i]=0;
		dp[0]=1;
		for(auto &w:res)
		{
			for(i=n;i>=w;i--) dp[i]|=dp[i-w];
		}
		if(dp[n/2]) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
倒着看
当前数比栈顶都大，非法 
比栈顶都小，随便放
否则一定放在栈顶比他小的那个 
dp[i][j][k]表示前i个数，上一个数放的序列当前长度为j，
另一个序列栈顶的数为k是否可行
这样要n^3
再观察样例
发现第二个样例不合法的本质是把序列分成了
3，1 2 4
这两组
考虑把序列分成 a1 < ak1 < ak2...的形式
统计出个数，然后做背包 
*/
