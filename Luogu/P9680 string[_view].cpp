#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
char op[22],s[MAX];
int ck(char c)
{
	if(c>='a'&&c<='z') return 1;
	if(c>='A'&&c<='Z') return 1;
	return 0;
}
int main()
{
	int n,i,ans,len,f,type;
	scanf("%d",&n);
	ans=0;
	map<string,int> mp;
	while(n--)
	{
		scanf("%s%s",op,s);
		len=strlen(s);
		string a,b;
		f=0;
		type=0;
		for(i=0;i<len;i++)
		{
			if(f==0&&ck(s[i])) a+=s[i];
			else if(f&&ck(s[i])) b+=s[i];
			if(s[i]=='(') f=1;
			if(s[i]=='"') type=1;
		}
	//	cout<<a<<" "<<b<<" "<<type<<endl;
		if(strlen(op)==6)
		{
			if(type==1)
			{
				ans+=b.size();
				mp[a]=b.size();
			}
			else
			{
				ans+=mp[b];
				mp[a]=mp[b];
			}
		}
		else
		{
			if(type==1)
			{
				mp[a]=b.size();
			}
			else
			{
				mp[a]=mp[b];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

