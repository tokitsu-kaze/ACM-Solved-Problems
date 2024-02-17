import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
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
const val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	var n=tmp_line[0]
	var k=tmp_line[1]
	require(n>=1 && n<=2e5)
	require(k>=1 && k<=n)
	var s=readstring()
	var l=mutableListOf<Char>()
	var r=mutableListOf<Char>()
	var f=0
	for(i in 0..n-1)
	{
		require(s[i]=='I'||s[i]=='('||s[i]==')')
		if(s[i]=='I') f=1
		else
		{
			if(f==0) l.add(s[i])
			else r.add(s[i])
		}
	}
	require(f==1)
	r.reverse()
	while(k-->0)
	{
		var op=readstring()
		require(op=="backspace"||op=="delete"||op=="<-"||op=="->")
		if(op[0]=='b')
		{
			if(l.size>0)
			{
				if(r.size>0&&l.last()=='('&&r.last()==')') r.removeLast()
				l.removeLast()
			}
		}
		else if(op[0]=='d')
		{
			if(r.size>0) r.removeLast()
		}
		else if(op[0]=='<')
		{
			if(l.size>0)
			{
				r.add(l.last())
				l.removeLast()
			}
		}
		else
		{
			if(r.size>0)
			{
				l.add(r.last())
				r.removeLast()
			}
		}
	}
	var ans=l.joinToString("")
	ans+="I"
	r.reverse();
	ans+=r.joinToString("")
	println(ans)
}

