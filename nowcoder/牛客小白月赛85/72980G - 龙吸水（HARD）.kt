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
class Discretization<T:Number>()
{
    var a=mutableListOf<Long>()
    fun add(x:T){a.add(x.toLong())}
    fun work(){
        a.sort()
        var tmp=mutableListOf<Long>()
        var pre=-1L
        if(a.size>0) pre=a[0]-1L;
        for(it in a){
            if(it!=pre) {tmp.add(it)}
            pre=it
        }
        a=tmp
    }
    fun get_pos(x:T):Int{return lower_bound_pos<Long>(a,0,a.size-1,x.toLong())+1}
    fun get_val(pos:Int):T {return a[pos-1] as T}
    fun size():Int{return a.size}
}
class Segment_Tree<T:Number>()
{
    class node<Long>(){
        var v=0L
    }
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
        res.v=max(x.v,y.v)
        return res
    }
    fun pushup(id:Int){t[id]=merge(t[id shl 1],t[id shl 1 or 1])}
    fun pushdown(l:Int,r:Int,id:Int)
    {
        if(tag[id]==0L) return
        var mid=(l+r) shr 1
        var ls=id shl 1
        var rs=id shl 1 or 1
        t[ls].v+=tag[id]
        t[rs].v+=tag[id]
        tag[ls]+=tag[id]
        tag[rs]+=tag[id]
        tag[id]=0L
    }
    fun build(l:Int,r:Int,id:Int)
    {
        tag[id]=0L
        t[id].v=0L
        if(l==r) return
        var mid=(l+r) shr 1
        build(l,mid,id shl 1)
        build(mid+1,r,id shl 1 or 1)
        pushup(id)
    }
    fun update(l:Int,r:Int,id:Int)
    {
        if(l>=ql&&r<=qr)
        {
            if(qop==1){
                tag[id]+=qv
                t[id].v+=qv
            }
            else{
                t[id].v=max(t[id].v,qv)
            }
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
    fun upd(l:Int,r:Int,v:T,op:Int){
        if(l>r) return
        ql=l
        qr=r
        qv=v.toLong()
        qop=op
        update(1,n,1)
    }
    fun ask(l:Int,r:Int):T{
        if(l>r) return 0 as T
        ql=l
        qr=r
        return query(1,n,1).v as T
    }
}
fun go()
{
    var tmp_line=readline_int()
    var n=tmp_line[0]
    var l=tmp_line[1]
    var r=tmp_line[2]
    require(n>=1 && n<=1e5)
    require(l>=1 && l<=1e9)
    require(r>=l && r<=1e9)
    var a=readline_int()
    require(a.size==n)
    var d=Discretization<Int>()
    for(it in a) {
        require(it>=0 && it<=1e9)
        d.add(it)
        d.add(max(0,it-r))
    }
    d.add(0)
    d.work()
//  for(i in 1..d.size()){println(d.get_val(i))}
    var tr=Segment_Tree<Int>()
    tr.build(d.size())
    for(i in 0..n-1){
        var pos0=1
        var pos1=d.get_pos(a[i]-r)
        var pos2=d.get_pos(a[i])
        var tmp1=tr.ask(pos0,pos1)
        var tmp2=0
        if(i>0) tmp2=tr.ask(pos2,d.get_pos(a[i-1]))
        tr.upd(pos1,pos1,tmp1,2)
        tr.upd(pos2,pos2,tmp2,2)
        tr.upd(pos1,d.get_pos(a[i]-l+1)-1,1,1)
    }
    println("${tr.ask(1,d.size())}")
}
