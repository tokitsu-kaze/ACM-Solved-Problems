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
    var T=readint()
    require(T>=1 && T<=1000)
    while(T-->0){
        var n=readint()
        require(n>=1 && n<=1000)
        var s=readstring()
        var mp:MutableMap<Char,Int> = mutableMapOf()
        for(ch in s){
            require(ch>='A' && ch<='Z')
            mp[ch]=(mp[ch]?:0)+1
        }
        var ans=INF
        ans=min(ans,mp['A']?:0)
        ans=min(ans,(mp['C']?:0)/2)
        ans=min(ans,mp['E']?:0)
        ans=min(ans,mp['P']?:0)
        ans=min(ans,mp['T']?:0)
        println("${ans}")
    }
}

