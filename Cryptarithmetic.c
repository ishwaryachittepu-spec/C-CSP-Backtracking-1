#include <stdio.h>

int main() {
    int S,E,N,D,M,O,R,Y;

    for(S=1; S<=9; S++)
    for(E=0; E<=9; E++)
    for(N=0; N<=9; N++)
    for(D=0; D<=9; D++)
    for(M=1; M<=9; M++)
    for(O=0; O<=9; O++)
    for(R=0; R<=9; R++)
    for(Y=0; Y<=9; Y++) {

        // All digits must be unique
        if(S==E||S==N||S==D||S==M||S==O||S==R||S==Y||
           E==N||E==D||E==M||E==O||E==R||E==Y||
           N==D||N==M||N==O||N==R||N==Y||
           D==M||D==O||D==R||D==Y||
           M==O||M==R||M==Y||
           O==R||O==Y||
           R==Y)
            continue;

        int send = 1000*S + 100*E + 10*N + D;
        int more = 1000*M + 100*O + 10*R + E;
        int money = 10000*M + 1000*O + 100*N + 10*E + Y;

        if(send + more == money) {
            printf("Solution:\n");
            printf("S=%d E=%d N=%d D=%d M=%d O=%d R=%d Y=%d\n",
                   S,E,N,D,M,O,R,Y);
            break;
        }
    }
}
