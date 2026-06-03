#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e6+10;
struct node{int l,r,mid;};
struct Manacher
{
	int p[MAX];
	vector<node> work(char *s,int n) //s[1..n]
	{
		int r,mid,i;
		//even
		r=mid=0;
		for(i=0;i<=n;i++) p[i]=0;
		vector<node> res;
		for(i=2;i<=n;i++)
		{
			if(r>i) p[i]=min(p[2*mid-i],r-i+1);
			while(i+p[i]<=n&&s[i+p[i]]==s[i-p[i]-1])
			{
				//palindrome substring s[i-p[i]-1,i+p[i]]
				p[i]++;
			}
			//palindrome substring s[i-p[i],i+p[i]-1]
			res.push_back({i-p[i],i+p[i]-1,i});
			if(i+p[i]-1>r)
			{
				r=i+p[i]-1;
				mid=i;
			}
		}
		return res;
	}
}la;
/*
la.work(s,n); // s[1..n]
*/
char s[MAX];
int main()
{
	int n,i,l,r;
	scanf("%s",s+1);
	n=strlen(s+1);
	vector<node> res=la.work(s,n);
	l=1;
	r=n;
	for(auto &it:res)
	{
		if(it.l<=l) l=it.mid;
	}
	reverse(res.begin(),res.end());
	for(auto &it:res)
	{
		if(it.mid-1<=l) break;
		if(it.r>=r) r=it.mid-1;
	}
//	printf("%d %d\n",l,r);
	printf("%d\n",r-l+1);
	return 0;
}
