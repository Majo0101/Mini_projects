#include <bits/stdc++.h>

using namespace std;

void fun( istream& m ){
    int n, o = 0; m >> n;
    while(n != 1 && ++o && (n & 1) ? n = 3 * n + 1 : n = n >> 1){}
    cout << "Loops to 1: " << o << endl;
}

int main() {
    cout << "Enter number:";
    fun(cin);
    return 0;
}
