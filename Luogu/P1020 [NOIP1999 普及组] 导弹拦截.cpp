#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
vector<int> LIS(vector<int> a,bool strict)
{
	int i,pos,len,mx,n;
	n=a.size();
	vector<int> b(n,INF),tmp(n),res;
	for(i=0;i<n;i++)
	{
		//    strict: lower_bound
		//not strict: upper_bound
		if(strict) pos=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		else pos=upper_bound(b.begin(),b.end(),a[i])-b.begin();
		b[pos]=a[i];
		tmp[i]=pos;
	}
	len=lower_bound(b.begin(),b.end(),INF)-b.begin();
	mx=INF;
	for(i=n-1;~i;i--)
	{
		if(!len) break;
		//    strict LIS: >
		//not strict LIS: >=
		if(tmp[i]+1==len&&((strict && mx>a[i]) || (!strict && mx>=a[i])))
		{
			len--;
			res.push_back(i);
			mx=a[i];
		}
	}
	return res;
}
int main()
{
	int x,y;
	vector<int> a;
	while(~scanf("%d",&x)) a.push_back(x);
	y=LIS(a,1).size();
	for(auto &it:a) it=-it;
	x=LIS(a,0).size();
	printf("%d\n%d\n",x,y);
	return 0;
}
