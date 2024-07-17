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
	var n=readint()
	require(n>=1 && n<=2e5)
	var aa=readstring()
	var a=aa.toCharArray()
	require(a.size==n && (n==1||a[0]!='0'))
	var bb=readstring()
	var b=bb.toCharArray()
	require(b.size==n && (n==1||b[0]!='0'))
	var ra=0L
	var rb=0L
	for(i in 0..n-1)
	{
		require(a[i]>='0' && a[i]<='9')
		require(b[i]>='0' && b[i]<='9')
		if(a[i]>b[i]) a[i]=b[i].also{b[i]=a[i]}
		ra=(ra*10+(a[i]-'0').toInt())%mod
		rb=(rb*10+(b[i]-'0').toInt())%mod
	}
	println("${ra*rb%mod}")
}

