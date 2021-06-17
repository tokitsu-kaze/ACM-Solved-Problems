import java.util.Scanner

val scan = Scanner(System.`in`)
fun main(args: Array<String>) {
    var s = Array(scan.nextInt(), {scan.next()}).sortedArrayWith(compareBy({it.length}))
    for (i in 1..s.size-1) {
        if (!s[i].contains(s[i-1])) {
            print("NO")
            return
        }
    }
   print ("YES\n${s.joinToString("\n")}")
}
