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
data class pair(var fi:Long,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun ask(l:Int,r:Int):Int
{
	println("? ${l} ${r}")
	System.out.flush()
	var res=readint()
	return res;
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var n=readint()
		var f=0
		var cnt0=0
		var dp=0
		var s=CharArray(n)
		for(i in 2..n)
		{
			var res=ask(1,i);
			if(f==1)
			{
				if(dp+cnt0==res)
				{
					s[i-1]='1'
					dp=res
				}
				else
				{
					cnt0++
					s[i-1]='0'
				}
			}
			else if(res>0 && f==0)
			{
				s[i-1]='1'
				for(j in i-res..i-1) s[j-1]='0'
				for(j in 1..i-res-1) s[j-1]='1'
				f=1
				cnt0=res
				dp=res
			}
		}
		if(f==1) println("! "+s.joinToString(""))
		else println("! IMPOSSIBLE")
		System.out.flush()
	}
}

