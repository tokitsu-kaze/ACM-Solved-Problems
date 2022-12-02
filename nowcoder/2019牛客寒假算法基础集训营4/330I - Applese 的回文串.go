package main

import "fmt"
import "os"
import "bufio"
import "strconv"

func min(a,b int)int {
    var res int
    if a<b {
        res=a
    } else {
        res=b;
    }
    return res;
}
var s string
func gao(a,b int)int{
    for ;a<b;a++{
        if s[a]!=s[b]{
            return 0
        }
        b--
    }
    return 1
}

func solve(){
    s=readString()
    var n,i,j,flag int
    n=len(s)
    i=0
    j=n-1
    flag=-1
    for i=0;i<j;i++{
        if s[i]!=s[j]{
            flag=0
            if gao(i,j-1)==1{
                flag=1
                break
            }else if gao(i+1,j)==1{
                flag=1
                break
            }else{
                break
            }
        }
        j--
    }
    if flag==0{
        fmt.Println("No")
    }else{
        fmt.Println("Yes")
    }
    
}


var scanner *bufio.Scanner

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	const MaxTokenLength = 1024 * 1024
	scanner.Buffer(make([]byte, 0, MaxTokenLength), MaxTokenLength)
	scanner.Split(bufio.ScanWords)
	solve()
}
func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	val, _ := strconv.Atoi(readString())
	return val
}

func readInt64() int64 {
	v, _ := strconv.ParseInt(readString(), 10, 64)
	return v
}