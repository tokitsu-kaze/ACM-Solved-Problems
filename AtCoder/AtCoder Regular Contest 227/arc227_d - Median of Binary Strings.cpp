#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
char s[MAX];
int tag[MAX][MAX][2][2];
int main()
{
	int n,m,q,i,j,ok;
	scanf("%d%d%d",&n,&m,&q);
	memset(tag,0,sizeof tag);
	while(n--)
	{
		scanf("%s",s+1);
		for(i=1;i<=m;i++)
		{
			for(j=i;j<=m;j++)
			{
				tag[i][j][s[i]-'0'][s[j]-'0']=1;
			}
		}
	}
	while(q--)
	{
		scanf("%s",s+1);
		ok=1;
		for(i=1;i<=m;i++)
		{
			for(j=i;j<=m;j++)
			{
				ok&=tag[i][j][s[i]-'0'][s[j]-'0'];
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
感觉这个题相当困难啊。
应该考虑：n=1，n=2，n=3，n=4，从短的情况入手。
另外可以根据数据范围猜一下，可能是一个O(n^2)的东西，考虑二元条件。

最后发现结论是，对于 T 中任意一对字符 (Tx,Ty)，
满足存在某个 S，使得对应 (x,y) 满足 Sx=Tx,Sy=Ty。
*/
