import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
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
const val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
fun go()
{
	var a=0
	var b=0
	var res=""
	var tmp=readstring()
	require(tmp=="   *****  ")
	
	tmp=readstring()
	require(tmp=="0***   *  "||
			tmp=="1***   *  "||
			tmp=="   *   *  ")
	if(tmp=="   *   *  ") res="not"
	else a=(tmp[0]-'0').toInt()
	
	tmp=readstring()
	require(tmp=="   * & ***"||
			tmp=="   *>=1***"||
			tmp=="0*** 1 *O*"||
			tmp=="1*** 1 *O*")
	if(res=="not") a=(tmp[0]-'0').toInt()
	else if(tmp=="   * & ***") res="and"
	else res="or"
	
	tmp=readstring()
	require(tmp=="0***   *  "||
			tmp=="1***   *  "||
			tmp=="   *   *  ")
	if(tmp=="   *   *  ") res="not"
	else b=(tmp[0]-'0').toInt()
	
	tmp=readstring()
	require(tmp=="   *****  ")
	
	if(res=="or") println(a or b)
	else if(res=="and") println(a and b)
	else println(a xor 1)
}

