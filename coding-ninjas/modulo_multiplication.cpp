#include <bits/stdc++.h>
using namespace std;


long long moduloMultiplication(long long a, long long b ,long long p){
    // find result (a*b)%p
    //goal is to avoid integer overflow 
    //this technique has some resemblance to bionimal exponentiation
    a%=p;
    long long res =0;

    while (b){
        if(b&1){
            res= (res+a)%p;
        }
        a =(2*a)%p;
        b>>=1;
    }
    return res;
}

int main(){

}