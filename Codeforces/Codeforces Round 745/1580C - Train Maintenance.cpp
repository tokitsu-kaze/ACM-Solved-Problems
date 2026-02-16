#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int LIMT=450;
int x[MAX],y[MAX],v1[MAX],v2[LIMT][LIMT],lst[MAX];
int main()
{
	int n,m,i,j,op,k,v,ans,s;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	memset(v1,0,sizeof v1);
	memset(v2,0,sizeof v2);
	memset(lst,0,sizeof lst);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&op,&k);
		if(op==1) v=1;
		else v=-1;
		s=x[k]+y[k];
		if(op==1) lst[k]=i;
		if(s>=LIMT)
		{
			for(j=lst[k]+x[k];j<=m;j+=s)
			{
				v1[max(i,j)]+=v;
				if(j+y[k]<=m) v1[max(i,j+y[k])]-=v;
			}
		}
		else
		{
			for(j=lst[k]+x[k];j<lst[k]+s;j++) v2[s][j%s]+=v;
		}
		if(op==2) lst[k]=0;
		v1[i]+=v1[i-1];
		ans=v1[i];
		for(j=1;j<LIMT;j++) ans+=v2[j][i%j];
		printf("%d\n",ans);
	}
	return 0;
}
/*
x+y较大时可以暴力跳倍数，所以考虑根号分治。
x+y>=sq，暴力跳倍数，差分修改；
x+y<sq，可以遍历 x+y，
考虑对不同的 x+y 维护第 i%(x+y) 天的贡献。
因为有减法所以要记录一下上一次出现的天数。 
*/
