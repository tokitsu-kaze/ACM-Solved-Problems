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
data class pair(var first:Int,var second:Int)
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
class Disjoint_Set_Union()
{
	lateinit var pre:IntArray
	lateinit var sz:IntArray
	fun init(n:Int)
	{
		pre=IntArray(n+1){it}
		sz=IntArray(n+1){1}
	}
	fun find(x:Int):Int
	{
		if(pre[x]!=x) pre[x]=find(pre[x])
		return pre[x]
	}
	fun merge(a:Int,b:Int):Boolean
	{
		var ra=find(a)
		var rb=find(b)
		if(ra!=rb)
		{
			pre[ra]=rb
			sz[rb]+=sz[ra]
			return true
		}
		return false
	}
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m1=tmp_line[1]
		var m2=tmp_line[2]
		var af=IntArray(m1+1)
		var bf=IntArray(m1+1)
		for(i in 1..m1)
		{
			tmp_line=readline_int()
			af[i]=tmp_line[0]
			bf[i]=tmp_line[1]
		}
		var ag=IntArray(m2+1)
		var bg=IntArray(m2+1)
		for(i in 1..m2)
		{
			tmp_line=readline_int()
			ag[i]=tmp_line[0]
			bg[i]=tmp_line[1]
		}
		var dsug=Disjoint_Set_Union()
		dsug.init(n)
		for(i in 1..m2) dsug.merge(ag[i],bg[i])
		var cntg=0
		for(i in 1..n)
		{
			if(dsug.find(i)==i) cntg++
		}
		var dsuf=Disjoint_Set_Union()
		dsuf.init(n)
		var ans=0
		for(i in 1..m1)
		{
			if(dsug.find(af[i])==dsug.find(bf[i])) dsuf.merge(af[i],bf[i])
			else ans++
		}
		var cntf=0
		for(i in 1..n)
		{
			if(dsuf.find(i)==i) cntf++
		}
		println("${ans+cntf-cntg}")
	}
}
