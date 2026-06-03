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
	var T=readint()
	require(1<=T && T<=5e4)
	var sumn=0
	var ans=mutableListOf<String>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==3)
		var n=tmp_line[0]
		var a0=tmp_line[1]
		var a1=tmp_line[2]
		require(1<=n && n<=2e5)
		require(0<=a0 && a0<=2e5)
		require(0<=a1 && a1<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var c0=0L
		var c1=0L
		var res=CharArray(n)
		for(i in 1..n)
		{
			var r0=abs((c0+1)*a1-c1*a0);
			var r1=abs(c0*a1-(c1+1)*a0);
			if(r0<r1)
			{
				res[i-1]='0'
				c0++
			}
			else
			{
				res[i-1]='1'
				c1++
			}
		}
		ans.add(res.joinToString(""))
	}
	println(ans.joinToString("\n"))
}

