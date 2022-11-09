#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

char res[20];

char qr[] = {'R', 'P', 'R', 'R', 'R', 'R', 'P', 'P', 'S', 'S'};
//                      S              S    R

char seq[] = {'R', 'P', 'S'};

int main(){
    char verdict[20];
    for(int i=0; i<10; i++){
        printf("%c\n", qr[i]);
        fflush(stdout);
        scanf("%s", verdict);
        if(verdict[0] == 'p') res[i] = 1;
    }
    // check always rock
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(qr[i] == 'P' && res[i] != 1) ok = false;
            if(qr[i] != 'P' && res[i] == 1) ok = false;
        }
        if(ok){
            for(int i=0; i<10; i++){
                printf("P\n");
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check always paper
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(qr[i] == 'S' && res[i] != 1) ok = false;
            if(qr[i] != 'S' && res[i] == 1) ok = false;
        }
        if(ok){
            for(int i=0; i<10; i++){
                printf("S\n");
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check always scissors
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(qr[i] == 'R' && res[i] != 1) ok = false;
            if(qr[i] != 'R' && res[i] == 1) ok = false;
        }
        if(ok){
            for(int i=0; i<10; i++){
                printf("R\n");
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check alternating RPS
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(qr[i] == seq[(i+1)%3] && res[i] != 1) ok = false;
            if(qr[i] != seq[(i+1)%3] && res[i] == 1) ok = false;
        }
        if(ok){
            for(int i=0; i<10; i++){
                printf("%c\n", seq[(2+i)%3]);
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check alternating PSR
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(qr[i] == seq[(i+2)%3] && res[i] != 1) ok = false;
            if(qr[i] != seq[(i+2)%3] && res[i] == 1) ok = false;
        }
        if(ok){
            for(int i=0; i<10; i++){
                printf("%c\n", seq[i%3]);
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check alternating SRP
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(qr[i] == seq[i%3] && res[i] != 1) ok = false;
            if(qr[i] != seq[i%3] && res[i] == 1) ok = false;
        }
        if(ok){
            for(int i=0; i<10; i++){
                printf("%c\n", seq[(1+i)%3]);
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check alternating SR
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(i%2 == 0){
                if(qr[i] == 'R' && res[i] != 1) ok = false;
                if(qr[i] != 'R' && res[i] == 1) ok = false;
            } else{
                if(qr[i] == 'P' && res[i] != 1) ok = false;
                if(qr[i] != 'P' && res[i] == 1) ok = false;
            }
        }
        if(ok){
            for(int i=0; i<10; i++){
                if(i%2 == 0) printf("R\n");
                else printf("P\n");
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check alternating PR
    if(true){
        int ok = true;
        for(int i=0; i<10; i++){
            if(i%2 == 0){
                if(qr[i] == 'S' && res[i] != 1) ok = false;
                if(qr[i] != 'S' && res[i] == 1) ok = false;
            } else{
                if(qr[i] == 'P' && res[i] != 1) ok = false;
                if(qr[i] != 'P' && res[i] == 1) ok = false;
            }
        }
        if(ok){
            for(int i=0; i<10; i++){
                if(i%2 == 0) printf("S\n");
                else printf("P\n");
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    if(res[2] && res[5] && res[6]) return 0;
    // check imitate previous
    if(true){
        if(res[1]){
            for(int i=0; i<10; i++){
                printf("%c\n", seq[i%3]);
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    // check try to win against previous
    if(true){
        int ok = true;
        for(int i=3; i<10; i++) if(res[i]) ok = false;
        if(ok && res[2]){
            int cur = 1;
            for(int i=0; i<10; i++){
                printf("%c\n", seq[cur%3]);
                fflush(stdout);
                scanf("%s", verdict);
                cur += 2;
            }
            return 0;
        }
    }
    // check try to lose against previous
    if(true){
        if(res[3]){
            for(int i=0; i<10; i++){
                printf("S\n");
                fflush(stdout);
                scanf("%s", verdict);
            }
            return 0;
        }
    }
    while(1);
    return 1;
}
