#include<bits/stdc++.h>
using namespace std;
string s[11];
int x[6]={0,3,3,3,3,6};
int y[6]={3,0,3,6,9,3};
int a[8]={0,0,0,0,5,5,5,5};
int b[8]={2,3,4,1,1,2,3,4};
int c[8]={1,2,3,4,2,3,4,1};
bool pos[1010];
int ax[8]={2,2,0,0,0,0,2,2};
int ay[8]={0,2,2,0,0,2,2,0};
int bx[8]={0,0,0,0,2,2,2,2};
int by[8]={0,0,0,0,2,2,2,2};
int cx[8]={0,0,0,0,2,2,2,2};
int cy[8]={2,2,2,2,0,0,0,0};
int main()
{
	int t,i,A,B,C,ok;
	scanf("%d",&t);
	while(t--)
	{
		memset(pos,0,sizeof(pos));
		for(i=0;i<9;i++) cin>>s[i];
		for(i=0;i<8;i++)
		{
			A=s[x[a[i]]+1][y[a[i]]+1]-'0';
			B=s[x[b[i]]+1][y[b[i]]+1]-'0';
			C=s[x[c[i]]+1][y[c[i]]+1]-'0';
			pos[A*100+B*10+C]=1;
			pos[B*100+C*10+A]=1;
			pos[C*100+A*10+B]=1;
		}
		ok=1;
		for(i=0;i<8;i++)
		{
			A=s[x[a[i]]+ax[i]][y[a[i]]+ay[i]]-'0';
			B=s[x[b[i]]+bx[i]][y[b[i]]+by[i]]-'0';
			C=s[x[c[i]]+cx[i]][y[c[i]]+cy[i]]-'0';
			if(pos[A*100+B*10+C]) continue;
			ok=0;
			int tmp[3]={A,B,C};
			sort(tmp,tmp+3);
			printf("%d %d %d\n",tmp[0],tmp[1],tmp[2]);
			break;
		}
		if(ok) puts("No problem");
	}
	return 0;
}

