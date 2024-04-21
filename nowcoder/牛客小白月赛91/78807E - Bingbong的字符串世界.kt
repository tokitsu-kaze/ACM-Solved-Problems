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
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
    	mid=(l+r) shr 1
    	if(a[mid].toLong()>=target.toLong()) r=mid
    	else l=mid+1
    }
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=(1e9).toInt()+7;
/*------------------------------------------------------------*/
var nex=Array(1){IntArray(1)}
fun work(s:String,len:Int)
{
	nex=Array(len+2){IntArray(26)}
	for(i in len downTo 1)
	{
		for(j in 0..25) nex[i-1][j]=nex[i][j];
		nex[i-1][s[i]-'A']=i;
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var k=tmp_line[1]
	require(n>=1 && n<=2e5)
	require(k>=6 && k<=n)
	var s=readstring()
	require(s.length==n)
	s=" "+s
	work(s,n)
	var ans=0L
	val ac="ACCEPT"
	val wa="WA"
	for(i in 1..n)
	{
		require(s[i]>='A' && s[i]<='Z')
		var acr=i-1
		for(it in ac)
		{
			acr=nex[acr][it-'A']
			if(acr==0) break
		}
		if(acr==0) continue
		var war=i-1
		for(it in wa)
		{
			war=nex[war][it-'A']
			if(war==0) break
		}
		if(war==0) war=n+1
		if(war<=acr) continue
		ans+=max(0,war-max(acr,i+k-1))
	}
	println("${ans}")
}

