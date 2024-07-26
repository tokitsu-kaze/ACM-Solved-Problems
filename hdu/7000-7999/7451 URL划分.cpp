#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
const int mod=998244353;
int main()
{
	int t,n,i,pos,f;
	char s[202];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlen(s);
		string res;
		for(i=0;i<n;i++)
		{
			if(s[i]==':')
			{
				pos=i+3;
				break;
			}
			res+=s[i];
		}
		cout<<res<<"\n";
		res="";
		for(i=pos;i<n;i++)
		{
			if(s[i]=='/')
			{
				cout<<res<<"\n";
				res="";
				pos=i+1;
				break;
			}
			else res+=s[i];
		}
		f=0;
		for(i=pos;i<n;i++)
		{
			if(s[i]=='/')
			{
				if(f) cout<<res<<"\n";
				f=0;
				res="";
			}
			else
			{
				res+=s[i];
				if(s[i]=='=') f=1;
			}
		}
		if(res.size()&&f) cout<<res<<"\n";
	}
	return 0;
}
