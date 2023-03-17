fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var a=readline_int().sorted()
	println("${a[3]-a[0]} ${a[3]-a[1]} ${a[3]-a[2]}")
}
