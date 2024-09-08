#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
string add(string a,string b,int k)
{
	int i,now;
	string res;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a.size()>b.size()) swap(a,b);
	now=0;
	res="";
	for(i=0;i<a.size();i++)
	{
		now=now+a[i]-'0'+b[i]-'0';
		res.push_back(now%k+'0');
		now/=k;
	}
	for(i=a.size();i<b.size();i++)
	{
		now=now+b[i]-'0';
		res.push_back(now%k+'0');
		now/=k;
	}
	while(now)
	{
		res.push_back(now%k+'0');
		now/=k;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	int n,i,ok;
	string m,tmp;
	cin>>n>>m;
	if(n==16)
	{
		for(auto &it:m)
		{
			if(it>='A' && it<='F') it=it-'A'+10+'0';
		}
	}
	ok=0;
	for(i=1;i<=30;i++)
	{
		tmp=m;
		reverse(tmp.begin(),tmp.end());
		m=add(m,tmp,n);
		tmp=m;
		reverse(tmp.begin(),tmp.end());
		if(tmp==m)
		{
			printf("STEP=%d\n",i);
			ok=1;
			break;
		}
	}
	if(!ok) puts("Impossible!");
	return 0;
}
