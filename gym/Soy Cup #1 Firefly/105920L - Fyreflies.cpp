#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
vector<int> tmp={13,5,10,8,9,6,1};
int cnt;
int ask(int x)
{
	cnt++;
	cout<<"? "<<x<<endl;
	int res=0;
	cin>>res;
//	for(auto &it:tmp) res+=abs(it-x);
	return res;
}
int main()
{
	int T,n,i,l,r,mid;
	cin>>T;
	while(T--)
	{
		cin>>n;
		l=1;
		r=1e5;
		cnt=0;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ask(mid)>ask(mid+1)) l=mid+1;
			else r=mid;
		}
		cout<<"! "<<l<<endl;
//		cout<<cnt<<endl;
	}
	return 0;
}
