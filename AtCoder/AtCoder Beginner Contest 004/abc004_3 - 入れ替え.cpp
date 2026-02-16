#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=900+10;
const int mod=1e9+7;
int main()
{
	int n,i;
	string s="123456";
	scanf("%d",&n);
	n%=30;
	while(n>0)
	{
		for(i=0;i<5;i++)
		{
			if(n==0) break;
			swap(s[i],s[i+1]);
			n--;
		}
	}
	cout<<s<<"\n";
	return 0;
}
