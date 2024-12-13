#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
ll ask(ll l,ll r)
{
	cout<<"xor "<<l<<" "<<r<<endl;
	ll res;
	cin>>res;
	return res;
}
int main()
{
	int T;
	ll n,l,r,mid,a,b,c,i,L;
	cin>>T;
	while(T--)
	{
		cin>>n;
		b=ask(1,n);
		if(b==0)
		{
			for(i=0;i<60;i++)
			{
				if((1LL<<(i+1))-1>n) break;
				a=ask(1,(1LL<<(i+1))-1);
				if(a)
				{
					L=a+1;
					break;
				}
			}
			l=L;
			r=n;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ask(mid,n)==0) r=mid;
				else l=mid+1;
			}
			c=ask(l,n);
			if(c==0) c=ask(l-1,n);
			b=b^a^c;
		}
		else
		{
			l=1;
			r=n;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ask(mid,n)==0) r=mid;
				else l=mid+1;
			}
			a=ask(l,n);
			if(a==0) a=ask(l-1,n);
			
			l=1;
			r=n;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ask(1,mid+1)==0) l=mid+1;
				else r=mid;
			}
			c=ask(1,l);
			if(c==0) c=ask(1,l+1);
			b=b^a^c;
		}
		cout<<"ans "<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}

