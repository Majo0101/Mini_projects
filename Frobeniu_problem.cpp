#include <bits/stdc++.h>

using namespace std;

int main() {

    int arr_coins[] = {4, 3, 1};
    int input_number;
    int arr_toIssue_length = 0;
    int numOf_coins_inInput = 0;
    int best_coin = 0;
    int coin_array_length  = sizeof(arr_coins) / sizeof(*arr_coins);

    cout << "Vstup:";
    cin >> input_number;


    //// Find best coin for array
    for (int i = 0; i < coin_array_length; ++i) {
        if (arr_coins[i] <= input_number){
            best_coin = i;
            break;
        }
    }

    //// arr_toIssue_length counter
    while(numOf_coins_inInput < input_number){
        numOf_coins_inInput += arr_coins[best_coin];
        arr_toIssue_length++;
    }

    //// Create coin array
    int arr_toIssue[arr_toIssue_length];

    for (int i = 0; i < arr_toIssue_length; ++i) {
        arr_toIssue[i] =arr_coins[best_coin];
    }

    /// main algorythm--------------------------------------
    int pos_toIssueArr = arr_toIssue_length - 1;
    int coin_atIndex = 0;
    int stop_loop = 0;
    int sum = 0;

    while(true){
        /// First searching process
        arr_toIssue[pos_toIssueArr] = arr_coins[coin_atIndex];

        for (int i = 0; i < arr_toIssue_length; ++i) {
            sum += arr_toIssue[i];
        }

        if (sum == input_number){
            for (int i = 0; i < arr_toIssue_length; ++i) {
                cout << arr_toIssue[i] << " ";
            }
            break;
        }else{
            sum = 0;
        }

        pos_toIssueArr++;

        if (pos_toIssueArr == (arr_toIssue_length)){ pos_toIssueArr = 0; stop_loop++; coin_atIndex++;}

        if (stop_loop == coin_array_length){
            /// Second searching process IF first proces dont find results
            for (int i = 0; i < arr_toIssue_length; ++i) { arr_toIssue[i] = arr_coins[best_coin];}

            for (int i = 0; i < coin_array_length; ++i) {
                arr_toIssue[arr_toIssue_length - 1] = arr_coins[i];
                for (int j = 0; j < arr_toIssue_length; ++j) {
                    sum += arr_toIssue[j];
                }

                if (sum == input_number) {
                    for (int j = 0; j < arr_toIssue_length; ++j) {
                        cout << arr_toIssue[j] << " ";
                    }
                    break;
                }
                /// important place for future recursion while first and second method don't find anything
                sum = 0;
            }
            break;
        }
    }
    return 0;
}

//        --------input 10
//        method-1:
//        4-4-4
//        4-4-3
//        4-3-3
//        break
//        print 4-3-3
//
//        ---------input 5
//        method-1:
//        4-4
//        4-3
//        3-3
//        3-1
//        1-1
//        method-2:
//        4-4
//        4-3
//        4-1
//        break;
//        print 4-1