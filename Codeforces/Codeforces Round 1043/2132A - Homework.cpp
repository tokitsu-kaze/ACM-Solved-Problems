#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int main()
{
	int T,n,m,i;
	string s,a,op;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cin>>s;
		scanf("%d",&m);
		cin>>a>>op;
		for(i=0;i<m;i++)
		{
			if(op[i]=='D') s+=a[i];
			else s=a[i]+s;
		}
		cout<<s<<"\n";
	}
	return 0;
}

