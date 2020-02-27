fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun main(args: Array<String>)
{
	var t=readint()
	while(t-->0)
	{
		var a=readline()
		if(a[0]<a[1]) a[0]=a[1].also{a[1]=a[0]}
		println("1 ${a[1]-1} ${a[0]-a[1]+1}")
	}
}