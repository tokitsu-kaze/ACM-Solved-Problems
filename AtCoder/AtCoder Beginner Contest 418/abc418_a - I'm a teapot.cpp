#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
int main()
{
	int n,i;
	char s[22];
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n<3) return 0*puts("No");
	if(s[n-2]=='t' && s[n-1]=='e' && s[n]=='a') puts("Yes");
	else puts("No");
	return 0;
}
