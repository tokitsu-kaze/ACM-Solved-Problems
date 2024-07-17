import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=2e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun lower_bound_pos(a:LongArray,target:Long):Int
{
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
    return a.size
}
const val offset=(1e9).toLong()
const val sd1=131L
const val sd2=233L
const val p1=(1e9).toLong()+7L
const val p2=998244353L
var t1=LongArray(1)
var t2=LongArray(1)
var sumt1=LongArray(1)
var sumt2=LongArray(1)
class Segment_Tree<T:Number>()
{
	class node()
	{
		var len=0
		var ha1=0L
		var ha2=0L
	}
	var t=Array<node>(MAX shl 2){node()}
	var tag=LongArray(MAX shl 2)
	var a=LongArray(MAX)
	var n:Int=0
	var ql:Int=0
	var qr:Int=0
	var qv=0L
	var qop:Int=0
	fun merge(x:node,y:node):node
	{
		var res=node()
		res.len=x.len+y.len
		res.ha1=(x.ha1*t1[y.len]+y.ha1)%p1
		res.ha2=(x.ha2*t2[y.len]+y.ha2)%p2
		return res
	}
	fun pushup(id:Int){t[id]=merge(t[id shl 1],t[id shl 1 or 1])}
	fun pushdown(l:Int,r:Int,id:Int)
	{
		if(tag[id]==-1L) return
		var mid=(l+r) shr 1
		var ls=id shl 1
		var rs=id shl 1 or 1
		t[ls].ha1=tag[id]*sumt1[mid-l]%p1
		t[ls].ha2=tag[id]*sumt2[mid-l]%p2
		t[rs].ha1=tag[id]*sumt1[r-mid-1]%p1
		t[rs].ha2=tag[id]*sumt2[r-mid-1]%p2
		tag[ls]=tag[id]
		tag[rs]=tag[id]
		tag[id]=-1L
	}
	fun build(l:Int,r:Int,id:Int)
	{
		tag[id]=-1L
		t[id]=node()
		if(l==r)
		{
			t[id].len=1
			t[id].ha1=a[l]
			t[id].ha2=a[l]
			return
		}
		var mid=(l+r) shr 1
		build(l,mid,id shl 1)
		build(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun update(l:Int,r:Int,id:Int)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].ha1=qv*sumt1[r-l]%p1
			t[id].ha2=qv*sumt2[r-l]%p2
			tag[id]=qv
			return
		}
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(ql<=mid) update(l,mid,id shl 1)
		if(qr>mid) update(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun query(l:Int,r:Int,id:Int):node
	{
		if(l>=ql&&r<=qr) return t[id]
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(qr<=mid) return query(l,mid,id shl 1)
		if(ql>mid) return query(mid+1,r,id shl 1 or 1)
		return merge(query(l,mid,id shl 1),
                     query(mid+1,r,id shl 1 or 1))
	}
	fun build(_n:Int){n=_n;build(1,n,1)}
	fun upd(l:Int,r:Int,v:T)
	{
		if(l>r) return
		ql=l
		qr=r
		qv=v.toLong()
		update(1,n,1)
	}
	fun ask(l:Int,r:Int):node
	{
		if(l>r) return node()
		ql=l
		qr=r
		return query(1,n,1)
	}
}
var res=LongArray(1)
var tot=0
fun init(n:Int)
{
	t1=LongArray(n+5)
	t2=LongArray(n+5)
	sumt1=LongArray(n+5)
	sumt2=LongArray(n+5)
	t1[0]=1L
	t2[0]=1L
	sumt1[0]=1L
	sumt2[0]=1L
	for(i in 1..n)
	{
		t1[i]=t1[i-1]*sd1%p1
		t2[i]=t2[i-1]*sd2%p2
		sumt1[i]=(sumt1[i-1]+t1[i])%p1
		sumt2[i]=(sumt2[i-1]+t2[i])%p2
	}
	res=LongArray((n/2+1)*50+2){0}
	tot=0
	res[tot]=0
	tot++
	for(j in -25..25)
	{
		if(j==0) continue
		for(i in 0..n/2)
		{
			res[tot]=((j*t1[i]%p1+p1)%p1)*offset+(j*t2[i]%p2+p2)%p2
			tot++
		}
	}
	res.sort()
}
var tr=Segment_Tree<Long>()
var trrev=Segment_Tree<Long>()
fun ck(l:Int,r:Int,n:Int):Boolean
{
	var len=r-l+1
	var res1=tr.ask(l,l+len/2-1)
	var res2=trrev.ask(n-r+1,(n-r+1)+len/2-1)
	var now=((res1.ha1-res2.ha1+p1)%p1)*offset+((res1.ha2-res2.ha2+p2)%p2)
	var pos=lower_bound_pos(res,now)
	if(pos<res.size && res[pos]==now) return true
	return false
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var q=tmp_line[1]
	require(n>=1 && n<=2e5)
	require(q>=1 && q<=2e5)
	var s=readstring()
	require(s.length==n)
	s=" "+s
	init(n)
	for(i in 1..n)
	{
		tr.a[i]=(s[i]-'a').toLong()
		trrev.a[n-i+1]=tr.a[i]
	}
	tr.build(n)
	trrev.build(n)
	var ans=mutableListOf<String>()
	while(q-->0)
	{
		var tmp_line2=readstring().split(" ")
		require(tmp_line2.size>=3)
		var op=tmp_line2[0].toInt()
		var l=tmp_line2[1].toInt()
		var r=tmp_line2[2].toInt()
		require(op>=1 && op<=2)
		require(l>=1 && l<=n)
		require(r>=l && r<=n)
		if(op==1)
		{
			require(tmp_line2.size==3)
			if(ck(l,r,n)) ans.add("YES")
			else ans.add("NO")
		}
		else
		{
			require(tmp_line2.size==4)
			var v=(tmp_line2[3][0]-'a').toLong()
			require(v>=0 && v<=25)
			tr.upd(l,r,v)
			trrev.upd(n-r+1,n-l+1,v)
		}
	}
	println(ans.joinToString("\n"))
}

