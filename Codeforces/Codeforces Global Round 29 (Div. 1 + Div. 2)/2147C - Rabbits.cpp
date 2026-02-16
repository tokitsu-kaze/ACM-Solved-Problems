#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		string now;
		now+=s[1];
		ok=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]!=s[i-1]) now+=s[i];
			else
			{
//				cout<<now<<endl;
				if(now[0]=='1' && now.back()=='1')
				{
					if((now.size()/2)&1) ok=0;
				}
				now="";
				now+=s[i];
			}
		}
		if(now[0]=='1' && now.back()=='1')
		{
			if((now.size()/2)&1) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
1101010110
1101010100
会发现00没用，11会把序列且分开。
找这种形态的：1 101010101 1
中间没法调整，所以奇数个0肯定不行 
*/
