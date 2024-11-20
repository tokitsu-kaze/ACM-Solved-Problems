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
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var n=readint()
		var s=" "+readstring()
		var sq=sqrt(n+0.5).toInt()
		while(sq*sq<n) sq++
		while(sq*sq>n) sq--
		if(sq*sq!=n)
		{
			println("No")
			continue
		}
		var ok=1
		var k=1
		for(i in 1..sq)
		{
			for(j in 1..sq)
			{
				if(i==1||i==sq||j==1||j==sq)
				{
					if(s[k]!='1') ok=0
				}
				else
				{
					if(s[k]!='0') ok=0
				}
				k++
			}
		}
		if(ok==1) println("Yes");
		else println("No");
	}
}

