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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun cal2(x:Long):Long {return x*(x+1)/2}
fun cal(x:Long,p:Long,q:Long):Long
{
	return x/q*cal2(p-1)+cal2(min(x%q,p-1))
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e5)
	while(T-->0)
	{
		var tmp_line=readline_ll()
		require(tmp_line.size==4)
		var l=tmp_line[0]
		var r=tmp_line[1]
		var p=tmp_line[2]
		var q=tmp_line[3]
		require(1<=l && l<=r && r<=1e9)
		require(2<=p && p<=q && q<=1e9)
		println("${cal(r,p,q)-cal(l-1,p,q)}")
	}
}

