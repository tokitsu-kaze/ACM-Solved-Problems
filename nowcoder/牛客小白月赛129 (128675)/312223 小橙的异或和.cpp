import java.util.*
import kotlin.math.*
import kotlin.random.Random

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
data class pair(var first:Int,var second:Int)
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
class Segment_Tree<T:Number>()
{
	class node<Long>(){
		var v=0L
		var mx=0L
	}
	var t=Array<node<Long>>(1){node()}
	var tag=LongArray(1)
	var n:Int=0
	var ql:Int=0
	var qr:Int=0
	var qv=0L
	var qop:Int=0
	var a=LongArray(1)
	
	fun merge(x:node<Long>,y:node<Long>):node<Long>
	{
		var res=node<Long>()
		res.mx=max(x.mx,y.mx)
		res.v=(x.v xor y.v)
		return res
	}
	fun pushup(id:Int){t[id]=merge(t[id shl 1],t[id shl 1 or 1])}
	fun pushdown(l:Int,r:Int,id:Int)
	{
		if(tag[id]==0L) return
		
	}
	fun build(l:Int,r:Int,id:Int)
	{
		tag[id]=0L
		t[id].v=0L
		t[id].mx=0L
		if(l==r)
		{
			t[id].v=a[l]
			t[id].mx=a[l]
			return
		}
		var mid=(l+r) shr 1
		build(l,mid,id shl 1)
		build(mid+1,r,id shl 1 or 1)
		pushup(id)
	}
	fun update(l:Int,r:Int,id:Int)
	{
		if(t[id].mx==0L) return
		if(l==r)
		{
			a[l]=a[l]/(l-qv+1)
			t[id].v=a[l]
			t[id].mx=a[l]
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
	fun build(_n:Int,_a:IntArray)
	{
		n=_n;
		t=Array<node<Long>>((n+5) shl 2){node()}
		tag=LongArray((n+5) shl 2)
		a=LongArray(n+1)
		for(i in 1..n) a[i]=_a[i-1].toLong()
		build(1,n,1)
	}
	fun upd(l:Int,r:Int,v:T)
	{
		if(l>r) return
		ql=l
		qr=r
		qv=v.toLong()
		update(1,n,1)
	}
	fun ask(l:Int,r:Int):T
	{
		if(l>r) return 0 as T
		ql=l
		qr=r
		return query(1,n,1).v as T
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var q=tmp_line[1]
	require(1<=n && n<=2e5)
	require(1<=q && q<=2e5)
	var a=readline_int()
	require(a.size==n)
	var tr=Segment_Tree<Int>()
	tr.build(n,a)
	var res=mutableListOf<Int>()
	while(q-->0)
	{
		var tmp_line=readline_int()
		var op=tmp_line[0]
		require(op==1 || op==2)
		if(op==1)
		{
			require(tmp_line.size==3)
			var l=tmp_line[1]
			var r=tmp_line[2]
			require(1<=l && l<=r && r<=n)
			tr.upd(l+1,r,l)
		}
		else
		{
			require(tmp_line.size==1)
			res.add(tr.ask(1,n))
		}
	}
	println(res.joinToString("\n"))
}
