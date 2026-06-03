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
fun go()
{
	var n=readint()
	require(1<=n && n<=1e5)
	var a=readline_int()
	require(a.size==n)
	var now=1000
	var ans=IntArray(7){0}
	for(it in a)
	{
		require(-1000<=it && it<=1000)
		now+=it
		require(now>=0)
		if(now<=699) ans[0]++
		else if(now<=1099) ans[1]++
		else if(now<=1499) ans[2]++
		else if(now<=1999) ans[3]++
		else if(now<=2399) ans[4]++
		else if(now<=2799) ans[5]++
		else ans[6]++
	}
	println(ans.joinToString(" "))
}
