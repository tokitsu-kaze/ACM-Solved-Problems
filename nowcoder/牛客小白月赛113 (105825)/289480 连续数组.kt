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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
data class node(var v:Int,var id:Int,var pos:Int)
val node_cmp: Comparator<node> = Comparator{ a,b->
	if (a.v==b.v) a.pos.compareTo(b.pos)
	else a.v.compareTo(b.v)
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	var res=mutableListOf<node>()
	var sumk=0
	for(i in 1..n)
	{
		var a=readline_int()
		var k=a[0]
		require(k>=1 && k<=1e5)
		sumk+=k
		require(sumk<=1e5)
		require(a.size==k+1)
		for(j in 1..k)
		{
			require(a[j]>=1 && a[j]<=1e9)
			res.add(node(a[j],i,j))
		}
	}
	res.sortWith(node_cmp)
	var ok=1
	var lst=IntArray(n+2){0}
	lst[res[0].id]=res[0].pos
	for(i in 1..res.size-1)
	{
		if(res[i].v!=res[i-1].v+1) ok=0
		if(lst[res[i].id]>res[i].pos) ok=0
		lst[res[i].id]=res[i].pos
	}
	if(ok==1) println("YES")
	else println("NO")
}

