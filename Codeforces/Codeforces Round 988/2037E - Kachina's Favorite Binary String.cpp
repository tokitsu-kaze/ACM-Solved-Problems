#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
char s[MAX];
int ask(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int res;
	cin>>res;
	return res;
}
int main()
{
	int T,n,i,j,res,f,cnt0,dp;
	cin>>T;
	while(T--)
	{
		cin>>n;
		f=0;
		cnt0=dp=0;
		for(i=2;i<=n;i++)
		{
			res=ask(1,i);
			if(f==1)
			{
				if(dp+cnt0==res)
				{
					s[i]='1';
					dp=res;
				}
				else
				{
					assert(dp==res);
					cnt0++;
					s[i]='0';
				}
			}
			else if(res>0 && f==0)
			{
				s[i]='1';
				for(j=i-res;j<i;j++) s[j]='0';
				for(j=1;j<i-res;j++) s[j]='1';
				f=1;
				cnt0=dp=res;
			}
		}
		s[n+1]='\0';
		if(f) cout<<"! "<<(s+1)<<endl;
		else cout<<"! IMPOSSIBLE"<<endl;
	}
	return 0;
}
/*
11
10
00

*/
