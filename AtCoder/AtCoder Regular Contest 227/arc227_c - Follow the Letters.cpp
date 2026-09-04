#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
const int K=26;
int nex[MAX][K];
void work(char *s,int len)
{
	int i,j;
	for(i=0;i<K;i++)
	{
		for(j=1;j<=len;j++)
		{
			if(s[j]-'a'==i)
			{
				nex[len][i]=j;
				break;
			}
		}
	}
	for(i=len;i;i--)
	{
		for(j=0;j<K;j++) nex[i-1][j]=nex[i][j];
		nex[i-1][s[i]-'a']=i;
	}
}
char s[MAX];
int posnow[MAX],posnex[MAX],totnow,totnex,vis[MAX];
int main()
{
	int n,i,j,k,pos;
	scanf("%d",&n);
	scanf("%s",s+1);
	work(s,n);
	for(i=1;i<=n;i++)
	{
		posnow[i]=i;
		vis[i]=0;
	}
	totnow=n;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			totnex=0;
			for(j=1;j<=totnow;j++)
			{
				pos=nex[posnow[j]][s[i]-'a'];
				if(!vis[pos])
				{
					posnex[++totnex]=pos;
					vis[pos]=1;
				}
			}
			for(j=1;j<=totnex;j++) vis[posnex[j]]=0;
			swap(posnow,posnex);
			swap(totnow,totnex);
		}
	}
	printf("%d\n",totnow);
	printf("%d\n",n*n);
	for(i=1;i<=n;i++) printf("%s",s+1);
	puts("");
	return 0;
}
/*
第二问很好猜，反正是个O(n^2)的操作量，很可能是直接输出 n 次原串。
第一问结论感觉不太好猜，但有个比较人类的做法是，考虑直接模拟。
复杂度是O(n^3)，n=1000，常数较小，以及可能跑不满。
*/
