#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
string add(string a,string b)
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
		res.push_back(now%10+'0');
		now/=10;
	}
	for(i=a.size();i<b.size();i++)
	{
		now=now+b[i]-'0';
		res.push_back(now%10+'0');
		now/=10;
	}
	while(now)
	{
		res.push_back(now%10+'0');
		now/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string sub(string a,string b)
{
	int i,f,now;
	if(a.size()<b.size() || (a.size()==b.size() && a<b))
	{
		swap(a,b);
		f=1;
	}
	else f=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int> tmp(a.size()+1,0);
	for(i=0;i<b.size();i++)
	{
		tmp[i]+=a[i]-b[i];
		if(tmp[i]<0)
		{
			tmp[i]+=10;
			tmp[i+1]--;
		}
	}
	for(i=b.size();i<a.size();i++)
	{
		tmp[i]+=a[i]-'0';
		if(tmp[i]<0)
		{
			tmp[i]+=10;
			tmp[i+1]--;
		}
	}
	while(tmp.size()>0 && tmp.back()==0) tmp.pop_back();
	reverse(tmp.begin(),tmp.end());
	string res;
	if(f) res="-";
	else res="";
	for(auto &it:tmp) res.push_back('0'+it);
	if(res.size()==0) res="0";
	return res;
}
string mul(string a,string b)
{
	int i,now;
	string res,tmp,bs;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a.size()>b.size()) swap(a,b);
	now=0;
	res="0";
	bs="";
	for(auto &it:a)
	{
		tmp=bs;
		for(i=0;i<b.size();i++)
		{
			now=now+(it-'0')*(b[i]-'0');
			tmp.push_back(now%10+'0');
			now/=10;
		}
		while(now)
		{
			tmp.push_back(now%10+'0');
			now/=10;
		}
		reverse(tmp.begin(),tmp.end());
		res=add(tmp,res);
		bs.push_back('0');
	}
	return res;
}
string C(int n,int m)
{
	if(m>n||m<0||n<0) return "0";
	int i,x,g;
	string res;
	vector<int> tmp;
	for(i=0;i<m;i++)
	{
		tmp.push_back(n);
		n--;
	}
	reverse(tmp.begin(),tmp.end());
	for(i=2;i<=m;i++)
	{
		x=i;
		for(auto &it:tmp)
		{
			if(x==1) break;
			g=__gcd(it,x);
			it/=g;
			x/=g;
		}
		assert(x==1);
	}
	res="1";
	for(auto &it:tmp)
	{
		if(it==1) continue;
		res=mul(res,to_string(it));
	}
	return res;
}
int main()
{
	int n;
	scanf("%d",&n);
	cout<<sub(C(2*n,n),C(2*n,n-1))<<"\n";
	return 0;
}

