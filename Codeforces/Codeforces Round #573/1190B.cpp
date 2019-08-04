#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int n;
	cin>>n;
	map<int,int> mp;
	int ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		ok&=(mp[a[i]]<3); //situation 1: one >=3 
	}
	int cnt=0;
	for(auto it:mp)
	{
		if(it.second>=2) cnt++;
	}
	ok&=(cnt<=1);// situation 2: more than two >=2
	for(auto it:mp)
	{
		if(it.second==2)
		{
			ok&=(mp.count(it.first-1)==0);// situation 3: reduce one but add another
			if(it.first==0) ok=0;// situation 4: two pile is zero
		} 
	}
	if(!ok) return 0*puts("cslnb");
	// normal situation 
	sort(a+1,a+1+n);
	ll s=0;
	for(int i=1;i<=n;i++)
	{
		assert(a[i]>=i-1);
		s+=a[i]-(i-1);
	}
	s%=2;
	return 0*puts(s?"sjfnb":"cslnb");
}
