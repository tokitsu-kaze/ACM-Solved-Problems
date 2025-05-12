#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int ask(int k,int x)
{
	printf("? 1 %d %d\n",k,x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}
void upd(int x)
{
	printf("? 2 %d\n",x);
	fflush(stdout);
}
int ans[MAX];
int main()
{
	int T,n,i,j,a,b,tmp,rt,ok,res1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++) scanf("%d%d",&a,&b);
		res1=ask(1,1);
		if(res1==1||res1==-1)
		{
			ans[1]=res1;
			for(i=2;i<=n;i++) ans[i]=ask(1,i)-ans[1];
		}
		else
		{
			upd(1);
			tmp=ask(1,1);
			ans[1]=(tmp-res1)/2;
			if(tmp!=0)
			{
				upd(1);
				ans[1]*=-1;
			}
			for(i=2;i<=n;i++) ans[i]=ask(1,i);
		}
		printf("!");
		for(i=1;i<=n;i++) printf(" %d",ans[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}

