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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val mod=998244353//1e9.toInt()+7
const val MAX=300000+10
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e4)
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var x=tmp_line[0]
		var y=tmp_line[1]
		require(x>=0 && x<=1e9)
		require(y>=0 && y<=1e9)
		var ans=y/(x+1)
		y-=ans*(x+1)
		ans*=2
		if(x==0 && ans>0) ans--
		if(y>0)
		{
			ans++
			y--
		}
		if(y>0)
		{
			ans++
			y-=x
		}
		require(y<=0)
		println("${ans}")
	}
}

