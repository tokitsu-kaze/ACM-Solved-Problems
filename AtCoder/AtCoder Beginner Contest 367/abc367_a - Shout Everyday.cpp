#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(b<c)
	{
		if(a<b||a>c) puts("Yes");
		else puts("No");
	}
	else
	{
		swap(b,c);
		if(a>b&&a<c) puts("Yes");
		else puts("No");
	}
	return 0;
}
