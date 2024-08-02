#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int nex[MAX][36];
void work(char *s,int len)
{
	int i,j;
	for(j=0;j<36;j++) nex[len][j]=len+1;
	for(i=len;i;i--)
	{
		for(j=0;j<36;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		if(s[i-1]>='a'&&s[i-1]<='z') nex[i-1][s[i-1]-'a']=i;
		else nex[i-1][s[i-1]-'0'+26]=i;
	}
}
char s[MAX];
int suf[MAX],day[MAX],daycnt[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m,i,j,x,bt,len;
	ll ans;
	char name[22];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>s;
		work(s,m);
		suf[m+1]=0;
		day[m+1]=0;
		daycnt[m+1]=0;
		for(i=m;i;i--)
		{
			day[i]=day[i+1];
			for(j=1;j<=31;j++)
			{
				if((day[i]>>(j-1))&1) continue;
				x=nex[i-1][26+j/10];
				if(x<=m) x=nex[x][26+j%10];
				if(x<=m) day[i]|=1<<(j-1);
			}
			daycnt[i]=__builtin_popcount(day[i]);
			suf[i]=0;
			for(j=1;j<=12;j++)
			{
				x=nex[i-1][26+j/10];
				if(x<=m) x=nex[x][26+j%10];
				if(x>m) continue;
				suf[i]+=daycnt[x+1];
				if(j==2||j==4||j==6||j==9||j==11)
				{
					if((day[x+1]>>30)&1) suf[i]--;
				}
				if(j==2&&((day[x+1]>>29)&1)) suf[i]--;
			}
		}
		ans=0;
		while(n--)
		{
			cin>>name;
			len=strlen(name);
			x=0;
			for(i=0;i<len;i++)
			{
				if(x<=m) x=nex[x][name[i]-'a'];
			}
			if(x<=m) ans+=suf[x];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

