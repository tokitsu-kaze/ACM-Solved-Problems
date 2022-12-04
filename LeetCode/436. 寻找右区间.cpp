const int MAX = 2e6;
const int INF = 0x3f3f3f3f;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],pos[MAX<<2],qv,qp;
	void pushup(int id)
	{
		if(v[ls]<v[rs])
        {
            v[id]=v[ls];
            pos[id]=pos[ls];
        }
        else
        {
            v[id]=v[rs];
            pos[id]=pos[rs];
        }
	}
	void build(int l,int r,int id)
	{
		if(l==r)
		{
			//init
            v[id]=INF;
            pos[id]=-1;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
            v[id]=min(v[id],qv);
            pos[id]=qp;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
    int resp;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
            if(v[id]<=res)
            {
                resp=pos[id];
                res=v[id];
            }
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,int p)
	{
		ql=l;
		qr=r;
		qv=v;
        qp=p;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=INF;
        resp=-1;
		query(1,n,1);
		return resp;
	}
	#undef type
	#undef ls
	#undef rs
}tr;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals)
    {
        int i;
        int n=(int)intervals.size();
        vector<pair<pair<int,int>,int> > res;
        i=0;
        for(auto it:intervals)
        {
            res.push_back(make_pair(make_pair(it[0]+1000000,it[1]+1000000),i));
            i++;
        }
        sort(res.begin(),res.end());
        vector<int> ans(n);
        tr.build(2000000);
        for(i=n-1;~i;i--)
        {
            tr.upd(res[i].first.first,res[i].first.first,res[i].first.first,res[i].second);
            ans[res[i].second]=tr.ask(res[i].first.second,2000000);
        }
        return ans;

    }
};
