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
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=1000)
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==5)
		var n=tmp_line[0]
		var m=tmp_line[1]
		var x=tmp_line[2]
		var y=tmp_line[3]
		var k=tmp_line[4]
		require(1<=n && n<=100)
		require(1<=m && m<=100)
		require(1<=x && x<=100)
		require(1<=y && y<=100)
		require(1<=k && k<=100)
		var ans=n*x+m*y
		for(i in 0..min(k,n/3))
		{
			var j=min(k-i,m/4)
			ans=min(ans,(n-i)*x+(m-j)*y)
		}
		println("${ans}")
	}
}

