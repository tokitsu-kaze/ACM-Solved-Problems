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
	while(T-->0)
	{
		var n=readint()
		var a=readline_int()
		var pw2=LongArray(n+1)
		pw2[0]=1
		for(i in 1..n) pw2[i]=pw2[i-1]*2L%mod
		var sum0=0
		for(x in a)
		{
			if(x==0) sum0++
		}
		var pre0=0
		var suf0=sum0
		var ans=0L
		var mp:MutableMap<Int,Long> = mutableMapOf()
		for(x in a)
		{
			if(x!=0)
			{
				ans=(ans+(mp[x]?:0L)*pw2[suf0])%mod
				mp[x]=((mp[x]?:0L)+pw2[pre0])%mod
			}
			else
			{
				pre0++
				suf0--
			}
		}
		ans=(ans+pw2[sum0])%mod
		println("${ans}")
	}
}

