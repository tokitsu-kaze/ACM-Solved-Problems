#include <bits/stdc++.h>
using namespace std;
int m,x[15],y[15],ok,flag[15],dict[15];
char op[15][5];
void out()
{
	int i;
	for(i=0;i<m;i++)
	{
		printf("%c",op[i][0]);
		if(op[i][0]=='+') printf(" %d/%d",x[i],y[i]);
		else if(op[i][0]=='-') printf(" %d",x[i]);
		else if(op[i][0]=='.');
		puts("");
	}
}
void dfs(int pos,int cnt,int tot,int nowt,int t)
{
	if(nowt>t||cnt>tot) return;
	if(pos==m)
	{
		if(cnt!=tot) return;
		t-=nowt;
		int i,tmp,tmpx[15],tmpy[15];
		for(i=0;i<m;i++)
		{
			tmpx[i]=x[i];
			tmpy[i]=y[i];
		}
		for(i=0;i<m;i++)
		{
			if(!flag[i]) continue;
			tmp=min(dict[i],t/20);
			t-=tmp*20;
			x[i]+=tmp;
		}
		for(i=0;i<m;i++)
		{
			if(!flag[i]) continue;
			tmp=min(t,59);
			t-=tmp;
			y[i]+=tmp;
		}
		if(t==0) ok=1;
		else
		{
			for(i=0;i<m;i++)
			{
				x[i]=tmpx[i];
				y[i]=tmpy[i];
			}
		}
		return;
	}
	if(op[pos][0]=='+')
	{
		dfs(pos+1,cnt+1,tot,nowt+(x[pos]-1)*20+y[pos],t);
		return;
	}
	if(op[pos][0]!='?')
	{
		dfs(pos+1,cnt,tot,nowt,t);
		return;
	}
	int tx,ty;
	tx=x[pos];
	ty=y[pos];
	
	op[pos][0]='+';
	x[pos]=ty-tx+1;
	y[pos]=240;
	flag[pos]=1;
	dict[pos]=tx-1;
	dfs(pos+1,cnt+1,tot,nowt+y[pos]+(ty-tx)*20,t);
	if(ok) return;
	
	op[pos][0]='-';
	x[pos]=ty;
	flag[pos]=0;
	dict[pos]=0;
	dfs(pos+1,cnt,tot,nowt,t);
	if(ok) return;
	
	op[pos][0]='?';
	x[pos]=tx;
	y[pos]=ty;
}
int main()
{
	int n,i,cnt,t;
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d%d",&cnt,&t);
		for(i=0;i<m;i++)
		{
			scanf("%s",op[i]);
			if(op[i][0]=='+') scanf("%d/%d",&x[i],&y[i]);
			else if(op[i][0]=='-') scanf("%d",&x[i]);
			else if(op[i][0]=='.');
			else if(op[i][0]=='?') scanf("%d%d",&x[i],&y[i]);
		}
		memset(flag,0,sizeof flag);
		memset(dict,0,sizeof dict);
		ok=0;
		dfs(0,0,cnt,0,t);
		if(ok)
		{
			puts("Yes");
			out();
		}
		else puts("No");
	}
	return 0;
}
