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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353;
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
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=2 && n<=1e5)
	require(m>=1 && m<=200)
	var a=mutableListOf<pair>()
	var d=Discretization<Int>()
	for(i in 1..m)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var l=tmp_line[0]
		var r=tmp_line[1]
		require(l>=1 && l<=n)
		require(r>=l && r<=n)
		d.add(l)
		d.add(l-1)
		d.add(r)
		a.add(pair(l,r))
	}
	d.add(0)
	d.add(n)
	d.work()
	for(i in 0..m-1) a[i]=pair(d.get_pos(a[i].fi),d.get_pos(a[i].se))
	a.sortWith(cmp)
	n=d.get_pos(n)
	var f=Array(n+2){IntArray(n+2){0}}
	f[d.get_pos(0)][d.get_pos(0)]=1
	for(i in 0..m-1)
	{
		var g=Array(n+2){IntArray(n+2){0}}
		for(j in a[i].fi-1..n)
		{
			for(k in d.get_pos(0)..n)
			{
				g[j][k]=(g[j][k]+f[j][k])%mod
				g[max(j,min(k,a[i].se))][max(k, a[i].se)]+=f[j][k]
				g[max(j,min(k,a[i].se))][max(k, a[i].se)]%=mod
			}
		}
		f=g
	}
	println("${f[n][n]}")
}

