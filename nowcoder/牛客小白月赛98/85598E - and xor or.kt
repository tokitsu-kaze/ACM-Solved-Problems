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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
var a=LongArray(1)
var n=1
fun gao(limt:Long):Long
{
	var j=0
	var res=0L
	var cnt=IntArray(62){0}
	for(i in 0..n-1)
	{
		while(j<n)
		{
			var now=0L
			for(s in 0..60)
			{
				if(((a[j] shr s) and 1)==1L) cnt[s]++
				if(cnt[s]>0 && cnt[s]!=j-i+1) now+=(1L shl s)
			}
			if(now>=limt)
			{
				for(s in 0..60)
				{
					if(((a[j] shr s) and 1)==1L) cnt[s]--
				}
				break
			}
			j++
		}
		res+=j-i
		for(s in 0..60)
		{
			if(((a[i] shr s) and 1)==1L) cnt[s]--
		}
	}
	return res
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	n=tmp_line[0]
	var k1=tmp_line[1]
	var k2=tmp_line[2]
	require(n>=1 && n<=5e5)
	require(k1>=0 && k1<k2)
	require(k2>k1 && k2<=1e9)
	var l=1L shl min(k1,60)
	var r=1L shl min(k2,60)
	a=readline_ll()
	require(a.size==n)
	for(it in a) require(it>=0 && it<=1e18)
	println("${gao(r)-gao(l)}")
}

