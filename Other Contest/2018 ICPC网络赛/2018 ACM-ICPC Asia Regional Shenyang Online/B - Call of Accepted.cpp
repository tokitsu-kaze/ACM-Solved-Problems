#include<bits/stdc++.h>
using namespace std;

long long min(long long a,long long b,long long c,long long d)
{
	return min(min(a,b),min(c,d));
}
long long max(long long a,long long b,long long c,long long d)
{
	return max(max(a,b),max(c,d));
}

#define Add 1
#define Muilt 2
#define Sub 3
#define D 4
#define Num 5
#define Left 6
#define Right 7

struct node
{
	long long  type;
	long long  left;
	long long  right;
	node(long long ty)
	{
		type=ty;
		left=0;
		right=0;
	}
	node(long long a,long long b){
		type=Num;
		left=a;
		right=b;
	}
	node mulitipy(node other)
	{
		long long minx=min(this->left*other.left,this->left*other.right,this->right*other.left,this->right*other.right);
		long long maxx=max(this->left*other.left,this->left*other.right,this->right*other.left,this->right*other.right);
		return node(minx,maxx);
	}
	node add(node other)
	{
		long long minx=min(this->left+other.left,this->left+other.right,this->right+other.left,this->right+other.right);
		long long maxx=max(this->left+other.left,this->left+other.right,this->right+other.left,this->right+other.right);
		return node(minx,maxx);
	}
	node substract(node other)
	{
		long long minx=min(this->left-other.left,this->left-other.right,this->right-other.left,this->right-other.right);
		long long maxx=max(this->left-other.left,this->left-other.right,this->right-other.left,this->right-other.right);
		return node(minx,maxx);
	}
	node d(node other)
	{
		long long minx=min(this->left,this->right);
		long long maxx=max(this->left*other.left,this->left*other.right,this->right*other.left,this->right*other.right);
		return node(minx,maxx);
	}
};
vector<node>v;
bool contain(vector<node> &s,int type)
{
	for(auto &i : s)
		if(i.type==type)
			return true;
	return false;
}

node dfs(vector<node> s)
{
	vector<node> s0=s;
	while(contain(s0,Left))
	{
		int left=0;
		int right=0;
		int cnt=1;
		while(s0[left].type!=Left)
		{
			left++;
		}
		right=left+1;
		while(cnt)
		{
			if(s0[right].type==Left)
				cnt++;
			else if(s0[right].type==Right)
			{
				cnt--;
				if(cnt==0)
					break;
			}
			right++;
		}
		vector<node> l;
		vector<node> r;
		vector<node> m;
		for(int i=0;i<left;i++)
		{
			l.push_back(s0[i]);
		}
		for(int i=left+1;i<right;i++)
		{
			m.push_back(s0[i]);
		}
		for(int i=right+1;i<s0.size();i++)
		{
			r.push_back(s0[i]);
		}
		node now=dfs(m);
		//cout<<now.left<<"*"<<now.right<<endl;
		s0.clear();
		for(auto &i:l)
			s0.push_back(i);
		s0.push_back(now);
		for(auto &i:r)
			s0.push_back(i);
	}
	while(contain(s0,D))
	{
		for(int i=s0.size()-1;i>=0;i--)
		{
			if(s0[i].type==D)
			{
				auto left=s0[i-1];
				auto right=s0[i+1];
				s0.erase(s0.begin()+i+1);
				s0.erase(s0.begin()+i);
				s0[i-1]=node(left.d(right));
				break;
			}

		}
	}
	while(contain(s0,D))
	{
		for(int i=s0.size()-1;i>=0;i--)
		{
			if(s0[i].type==D)
			{
				auto left=s0[i-1];
				auto right=s0[i+1];
				s0.erase(s0.begin()+i+1);
				s0.erase(s0.begin()+i);
				s0[i-1]=node(left.d(right));
				break;
			}

		}
	}
	while(contain(s0,Muilt))
	{
		for(int i=0;i<s0.size();i++)
		{
			if(s0[i].type==Muilt)
			{
				auto left=s0[i-1];
				auto right=s0[i+1];
				s0.erase(s0.begin()+i+1);
				s0.erase(s0.begin()+i);
				s0[i-1]=node(left.mulitipy(right));
				break;
			}

		}
	}
	while(contain(s0,Add) || contain(s0,Sub))
	{
		for(int i=0;i<s0.size();i++)
		{
			if(s0[i].type==Add)
			{
				auto left=s0[i-1];
				auto right=s0[i+1];
				s0.erase(s0.begin()+i+1);
				s0.erase(s0.begin()+i);
				s0[i-1]=node(left.add(right));
				break;
			}
			else if(s0[i].type==Sub)
			{
				auto left=s0[i-1];
				auto right=s0[i+1];
				s0.erase(s0.begin()+i+1);
				s0.erase(s0.begin()+i);
				s0[i-1]=node(left.substract(right));
				break;
			}
		}
	}
	return (s0[0]);
}
string s;
int main()
{
	while(cin>>s)
	{
		v.clear();
		string temp;
		for(int i=0;i<s.length();i++)
		{
			//cout<<"temp:"<<temp<<endl;
			if(s[i]=='(')
			{
				if(temp.size()>0)
				{
					v.push_back(node(stoll(temp),stoll(temp)));
					temp.clear();
				}
				v.push_back(node(Left));
			}
			else if(s[i]==')')
			{
				if(temp.size()>0)
				{
					v.push_back(node(stoll(temp),stoll(temp)));
					temp.clear();
				}
				v.push_back(node(Right));
			}
			else if(s[i]=='*')
			{
				if(temp.size()>0)
				{
					v.push_back(node(stoll(temp),stoll(temp)));
					temp.clear();
				}
				v.push_back(node(Muilt));
			}
			else if(s[i]=='+')
			{
				if(temp.size()>0)
				{
					v.push_back(node(stoll(temp),stoll(temp)));
					temp.clear();
				}
				v.push_back(node(Add));
			}
			else if(s[i]=='-')
			{
				if(temp.size()>0)
				{
					v.push_back(node(stoll(temp),stoll(temp)));
					temp.clear();
				}
				v.push_back(node(Sub));
			}
			else if(s[i]=='d')
			{
				if(temp.size()>0)
				{

					v.push_back(node(stoll(temp),stoll(temp)));
					temp.clear();
				}
				v.push_back(node(D));
			}
			else
			{
				temp+=(s[i]);
			}
		}
		//cout<<"temp:"<<temp<<endl;
		if(temp.size()>0)
		{
			v.push_back(node(stoll(temp),stoll(temp)));
			temp.clear();
		}
		node temp0=dfs(v);
		printf("%lld %lld\n",temp0.left,temp0.right);
	}
}
/*
((5d2)-(4d5))*(1-4)
 */