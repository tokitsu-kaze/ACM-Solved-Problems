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
const val MAX=1e6.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(T>=1 && T<=100)
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=1000);
		var s=readstring()
		require(s.length==n)
		var cnt=IntArray(26){0}
		for(it in s)
		{
			require('a'<=it && it<='z')
			cnt[(it-'a').toInt()]+=1
		}
		var pre=0
		var ok=true
		for(i in 0..25)
		{
			if(cnt[i]>0)
			{
				if(pre!=0)
				{
					if(pre+1!=cnt[i]) ok=false
				}
				pre=cnt[i]
			}
		}
		if(ok) println("YES")
		else println("NO")
	}
}

