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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
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
	var t=readint()
	while(t-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var k=tmp_line[1]
		var s=readstring()
		var cnt=IntArray(256){0}
		for(it in s) cnt[it.toInt()]++
		var ans=0
		for(i in 'a'.toInt()..'z'.toInt())
		{
			var tmp:Int=min(cnt[i],cnt[i-'a'.toInt()+'A'.toInt()])
			ans+=tmp
			cnt[i]-=tmp
			cnt[i-'a'.toInt()+'A'.toInt()]-=tmp
			tmp=min(k,cnt[i]/2)
			ans+=tmp
			k-=tmp
			tmp=min(k,cnt[i-'a'.toInt()+'A'.toInt()]/2)
			ans+=tmp
			k-=tmp
		}
		println("${ans}")
	}
}
