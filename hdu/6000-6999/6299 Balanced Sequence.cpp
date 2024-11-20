#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct node{int l,r;};
char s[MAX];
bool cmp(node x,node y)
{
	if(min(x.l,y.r)==min(y.l,x.r))
	{
		if(x.l==y.l) return x.r<y.r;
		return x.l>y.l;
	}
	return min(x.l,y.r)>min(y.l,x.r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,i,j,len,tmp,ans;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<node> res;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>s;
			len=strlen(s);
			node t={0,0};
			for(j=0;j<len;j++)
			{
				if(s[j]=='(') t.l++;
				else
				{
					if(t.l)
					{
						t.l--;
						ans++;
					}
					else t.r++;
				}
			}
			res.push_back(t);
		}
		sort(res.begin(),res.end(),cmp);
		tmp=0;
		for(i=0;i<res.size();i++)
		{
			ans+=min(tmp,res[i].r);
			tmp-=min(tmp,res[i].r);
			tmp+=res[i].l;
		}
		cout<<ans*2<<"\n";
	}
	return 0;
}
/*
1
3
(((
)))
)(
*/
