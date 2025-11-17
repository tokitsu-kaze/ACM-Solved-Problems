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
fun qpow(aa:Long,bb:Int,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var s=readstring()
		var cnt0=0
		var cnt=0
		for(it in s)
		{
			if(it=='0') cnt0++
			else if(it=='?') cnt++
		}
		if(s[0]=='1') println("${qpow(2,cnt,mod)}")
		else if(s[0]=='?')
		{
			if(cnt0==0) println("${qpow(2,cnt,mod)-1}")
			else println("${qpow(2,cnt,mod)}")
		}
		else
		{
			if(cnt==0)
			{
				if(cnt0==1) println("0")
				else println("1")
			}
			else
			{
				if(cnt0>=2) println("${qpow(2,cnt,mod)}")
				else println("${qpow(2,cnt,mod)-1}")
			}
		}
	}
}

