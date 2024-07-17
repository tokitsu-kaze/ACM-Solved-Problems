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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=(1e9).toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=1 && n<=1e5)
	require(m>=1 && m<=1e5)
	require(n.toLong()*m>=1 && n.toLong()*m<=1e5)
	var w=readline_int()
	require(w.size==n)
	var wbit=LongArray(n+5)
	wbit[0]=0
	for(i in 0..n-1)
	{
		wbit[i+1]=wbit[i]+w[i]
		require(w[i]>=1 && w[i]<=1e5)
	}
	var v=readline_ll()
	require(v.size==n)
	for(it in v) require(it>=-1e9 && it<=1e9)
	var x=readline_ll()
	require(x.size==m)
	var res=mutableListOf<pair>()
	for(it in x)
	{
		require(it>=0 && it<wbit[n])
		res.add(pair(-it,v[0]))
		for(j in 1..n-1) res.add(pair(wbit[j]-it,v[j]-v[j-1]))
		res.add(pair(wbit[n]-it,-v[n-1]))
	}
	res.sortWith(cmp)
	var s=TreeSet<Long>()
	var now=0L
	for(i in 0..res.size-1)
	{
		now+=res[i].se
		if(i==res.size-1 || res[i].fi!=res[i+1].fi) s.add(now)
	}
	println("${s.size}")
}

