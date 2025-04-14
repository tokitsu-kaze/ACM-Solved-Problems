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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var n=readint()
		var s=readstring()
		var a=readline_int()
		var pre=0L
		var prepos=-1
		for(i in 0..n-1)
		{
			if(s[i]=='<')
			{
				pre=pre+max(0,a[i])
				prepos=i
			}
			else break
		}
		var suf=0L
		var sufpos=n
		for(i in n-1 downTo 0)
		{
			if(s[i]=='>')
			{
				suf=suf+max(0,a[i])
				sufpos=i
			}
			else break
		}
		var ans=max(pre,suf)
		var now=0L
		for(i in prepos+1..sufpos-1)
		{
			if(s[i]=='<') ans=max(ans,pre+now+a[i])
			now=now+max(0,a[i])
		}
		now=0L
		for(i in sufpos-1 downTo prepos+1)
		{
			if(s[i]=='>') ans=max(ans,suf+now+a[i])
			now=now+max(0,a[i])
		}
		println("${ans}")
	}
}

