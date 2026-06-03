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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var k=tmp_line[1]
		var aa=readline_ll()
		var bb=readline_ll()
		aa.sort()
		bb.sort()
		var a=LongArray(n+2)
		for(i in 1..n) a[i]=aa[i-1]
		a[n+1]=LLINF
		var b=LongArray(n+2)
		for(i in 1..n) b[i]=bb[i-1]
		b[n+1]=LLINF
		var nega=0
		var cnt=n
		var ans=0L
		var i=0
		var j=0
		while(i<n || j<n)
		{
			var tmp=min(a[i+1],b[j+1])
			if(nega<=k) ans=max(ans,1L*tmp*cnt)
			while(a[i+1]==tmp)
			{
				i++
				nega++
			}
			while(b[j+1]==tmp)
			{
				j++
				cnt--
				nega--
			}
		}
		println("${ans}")
	}
}
