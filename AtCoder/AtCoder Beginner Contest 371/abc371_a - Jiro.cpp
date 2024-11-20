#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int main()
{
	char s[3][2];
	scanf("%s %s %s",s[0],s[1],s[2]);
	if(s[0][0]==s[2][0]) puts("B");
	else if(s[0][0]!=s[1][0]) puts("A");
	else puts("C");
	return 0;
}

