import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun main(args: Array<String>){go()}
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
		mid=(l+r) shr 1
		if(a[mid].toLong()>=target.toLong()) r=mid
		else l=mid+1
	}
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
fun sqr(x:Long):Long{return x*x}
class Segment_Tree<T:Number>()
{
	class node<Long>(){
		var len=0L
		var llen=0L
		var rlen=0L
		var lv=0L
		var rv=0L
		var sc=0L
	}
	var a=LongArray(MAX)
	var t=Array<node<Long>>(MAX shl 2){node()}
	var tag=LongArray(MAX shl 2)
	var n:Int=0
	var ql:Int=0
	var qr:Int=0
	var qv=0L
	var qop:Int=0
	
	fun merge(x:node<Long>,y:node<Long>):node<Long>
	{
		var res=node<Long>()
		res.len=x.len+y.len
		res.lv=x.lv
		res.rv=y.rv
		if(x.llen==x.len && x.rv+1L==y.lv) res.llen=x.len+y.llen
		else res.llen=x.llen
		if(y.rlen==y.len && x.rv+1L==y.lv) res.rlen=x.rlen+y.len
		else res.rlen=y.rlen
		res.sc=x.sc+y.sc
		if(x.rv+1L==y.lv) res.sc+=sqr(x.rlen+y.llen)-sqr(x.rlen)-sqr(y.llen)
		return res
	}
	fun pushup(id:Int){t[id]=merge(t[id shl 1],t[id shl 1 or 1])}
	fun pushdown(l:Int,r:Int,id:Int)
	{
		if(tag[id]==0L) return
		var mid=(l+r) shr 1
		var ls=id shl 1
		var rs=id shl 1 or 1
		t[ls].lv+=tag[id]
		t[ls].rv+=tag[id]
		t[rs].lv+=tag[id]
		t[rs].rv+=tag[id]
		tag[ls]+=tag[id]
		tag[rs]+=tag[id]
		tag[id]=0L
	}
	fun build(l:Int,r:Int,id:Int)
	{
		tag[id]=0L
		if(l==r)
		{
			t[id].lv=a[l]
			t[id].rv=a[l]
			t[id].llen=1L
			t[id].rlen=1L
			t[id].sc=1L
			t[id].len=1L
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
			tag[id]+=qv
			t[id].lv+=qv;
			t[id].rv+=qv;
			return
		}
		pushdown(l,r,id)
		var mid=(l+r) shr 1
		if(ql<=mid) update(l,mid,id shl 1)
		if(qr>mid) update(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun query(l:Int,r:Int,id:Int):node<Long>
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
	fun upd(l:Int,r:Int,v:T){
		if(l>r) return
		ql=l
		qr=r
		qv=v.toLong()
		update(1,n,1)
	}
	fun ask(l:Int,r:Int):T{
		if(l>r) return 0 as T
		ql=l
		qr=r
		return query(1,n,1).sc as T
	}
}

fun go()
{
	var tmp_line=readline_int()
    var n=tmp_line[0]
    var m=tmp_line[1]
	require(n>=1 && n<=2e5)
    require(m>=1 && m<=2e5)
    var a=readline_ll()
    require(a.size==n)
    var tr=Segment_Tree<Long>()
    for(i in 1..n){
    	require(a[i-1]>=-1e9 && a[i-1]<=1e9)
    	tr.a[i]=a[i-1]
	}
	tr.build(n)
	var res=mutableListOf<Long>()
	while(m-->0){
		tmp_line=readline_int()
		var l=tmp_line[0]
		require(l>=1 && l<=n)
		var r=tmp_line[1]
		require(r>=l && r<=n)
		var v=tmp_line[2]
		require(v>=-1e9 && v<=1e9)
		tr.upd(l,r,v.toLong())
		res.add(tr.ask(1,n))
	}
	println(res.joinToString("\n"))
}

