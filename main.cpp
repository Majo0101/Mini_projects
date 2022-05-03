#include <bits/stdc++.h>

using namespace std;

int main() {

    int sumCoins[8];
    string name[] ={"2e","1e","50c","20c","10c","5c","2c","1c"};
    float coins[] = {2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01 };
    float toIssue;
    char loop = '0';

    cout << "Inventory" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Coin " << name[i] << endl;
        cin >> sumCoins[i];
    }

    while(loop != 'n') {
        cout << endl << endl;
        cout << "Enter issue:";
        cin >> toIssue;
        cout << endl;

        int integer = int(toIssue * 100);

        for (int i = 0, j = 0; i < 8; i++) {
            while (integer >= int(coins[i] * 100)) {
                if (sumCoins[i] != 0) {
                    integer = integer - int(coins[i] * 100);
                    sumCoins[i]--;
                    j++;
                } else { break; }
            }
            if (j == 0) { continue; }
            cout << "Coin: " << name[i] << " " << "count: " << j << endl;
            j = 0;
        }

        if (integer != 0) {
            cout << "To issue: " << float(integer) / 100 << "e  ";
            cout << "Call Service..." << endl;
            cout << "Stacks" << endl;
            for (auto & i : name) {cout << setfill(' ') << setw(5) << i << "  ";}
            cout <<endl;
            for (int sumCoin : sumCoins) {cout << setfill(' ')<< setw(5) << sumCoin << "  ";}
            cout << endl;
        }

        while(true){
            cout << "Again? (y/n)" << endl;
            cin >> loop;
            if (loop == 'y' || loop == 'n'){break;}
            cout << "Bad choice" << endl;
        }
    }
return 0;
}