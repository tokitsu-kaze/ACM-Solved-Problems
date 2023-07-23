#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=2.5e5+10;
struct Treap
{
	#define type pair<int,int>
	const type inf={INF,INF};
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v;
		node(){}
		node(type x)
		{
			v=x;
			fix=rand();
			sz=cnt=1;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root;
	void init()
	{
		srand(time(0));
		root=tot=0;
		t[0].sz=t[0].cnt=0;
		memset(t[0].ch,0,sizeof t[0].ch);
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;  
	}  
	void rotate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		pushup(id);
		pushup(y);
		id=y;
	}
	void insert(int &id,type v)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v);
			return;
		}
		if(t[id].v==v) t[id].cnt++;
		else
		{
			int tmp=(v>t[id].v);
			insert(t[id].ch[tmp],v);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void erase(int &id,type v)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			if(t[id].cnt>1)
			{
				t[id].cnt--;
				pushup(id);
				return;
			}
			if(!(t[id].ch[0]&&t[id].ch[1]))
			{
				id=t[id].ch[0]+t[id].ch[1];
				return;
			}
			else
			{
				int tmp=(t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
				rotate(id,tmp);
				erase(t[id].ch[tmp],v);
				pushup(id);
			}
		}
		else
		{
			erase(t[id].ch[v>t[id].v],v);
			pushup(id);
		}
	}
	type kth(int k)//k small
	{
		int id=root;
		if(id==0) return {0,0};
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
	}
	int find(type key,int f)
	{
		int id=root,res=0;
		while(id)
		{
			if(t[id].v<key)
			{
				res+=t[t[id].ch[0]].sz+t[id].cnt;
				if(f&&key==t[id].v) res-=t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	void insert(type v){insert(root,v);}
	void erase(type v){erase(root,v);}
	int upper_bound_count(type key){return find(key,0);}//the count <=key
	int lower_bound_count(type key){return find(key,1);}//the count <key
	int rank(type key){return lower_bound_count(key)+1;}
	int size(){return t[root].sz;}
	#undef type
}tr; //tr.init();
int main()
{
	int n,i,x,tot;
	char op[2],name[11];
	scanf("%d",&n);
	map<string,int> mp,id;
	map<int,string> player;
	vector<string> res;
	tr.init();
	tot=0;
	while(n--)
	{
		scanf("%1s",op);
		if(op[0]=='+')
		{
			scanf("%s%d",name,&x);
			if(mp.count(name)) tr.erase({mp[name],id[name]});
			tot++;
			mp[name]=-x;
			id[name]=tot;
			tr.insert({mp[name],id[name]});
			player[id[name]]=string(name);
	//		puts("now:");
	//		for(i=1;i<=tr.size();i++) cout<<player[tr.kth(i).second]<<endl;
		}
		else if(op[0]=='?')
		{
			scanf("%s",name);
			if(sscanf(name,"%d",&x)==1)
			{
				res.clear();
				for(i=x;i<=min(tr.size(),x+10-1);i++)
				{
					res.push_back(player[tr.kth(i).second]);
				}
				for(i=0;i<res.size();i++)
				{
					printf("%s%c",res[i].c_str()," \n"[i+1==res.size()]);
				}
			}
			else
			{
				assert(mp.count(name));
				printf("%d\n",tr.rank({mp[name],id[name]}));
			}
		}
	}
	return 0;
}
