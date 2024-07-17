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
const val MAX=1e5.toInt()+10
const val mod=(1e9).toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var hp=tmp_line[1]
	require(n>=1 && n<=1000)
	require(hp>=0 && hp<=4000)
	var mp=mutableListOf<CharArray>()
	for(i in 0..4)
	{
		var s=readstring()
		require(s.length==n)
		if(i==2)
		{
			for(it in s) require(it=='.')
		}
		else
		{
			for(it in s) require(it=='#'||it=='.'||it=='*')
		}
		mp.add(s.toCharArray())
	}
	var ans=0
	for(i in 0..n-1)
	{
		if(mp[1][i]=='*' && hp>0)
		{
			ans++
			hp--
			mp[1][i]='.'
		}
		if(mp[3][i]=='*' && hp>0)
		{
			ans++
			hp--
			mp[3][i]='.'
		}
	}
	for(i in 0..n-1)
	{
		if(mp[1][i]=='.' &&mp[0][i]=='*' && hp>0)
		{
			ans++
			hp--
			mp[0][i]='.'
		}
		if(mp[3][i]=='.' &&mp[4][i]=='*' && hp>0)
		{
			ans++
			hp--
			mp[4][i]='.'
		}
	}
	for(i in 0..n-1)
	{
		if(mp[0][i]=='*' && hp>1)
		{
			ans++
			hp-=2
			mp[0][i]='.'
		}
		if(mp[4][i]=='*' && hp>1)
		{
			ans++
			hp-=2
			mp[4][i]='.'
		}
	}
	println("${ans}")
}

