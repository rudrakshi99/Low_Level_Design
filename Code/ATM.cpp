/*
There is an ATM machine that stores banknotes of 5 denominations: 20, 50, 100, 200, and 500 dollars.
Initially the ATM is empty. The user can use the machine to deposit or withdraw any amount of money.
*/

#include <bits/stdc++.h>
using namespace std;


class ATM {
public:
    unordered_map<long long int, long long int> m; // note, count
    int note[5] = {20, 50, 100, 200, 500};
    ATM() {

    }

    void deposit(vector<int> banknotesCount) {
        for (long long int i = 0; i < banknotesCount.size(); i++) {
            m[note[i]] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans;
        for (int i = 4; i >= 0; i--) {
            long long int c = m[note[i]];
            if (c > 0) {
                long long int k = min(c, ( long long)(amount / note[i]));
                ans.push_back(k);
                m[note[i]] -= k;
                long long int l = (k * note[i]);
                amount -= (k * note[i]);
            }
            else {
                ans.push_back(0);
            }
        }
        reverse(ans.begin(), ans.end());
        if (amount != 0) {
            for ( long long int i = 0; i < ans.size(); i++) {
                m[note[i]] += ans[i];
            }
            return { -1};
        }


        return ans;

    }
};


int main() {
    ATM* obj = new ATM();
    vector<int> banknotesCount = {0, 0, 1, 2, 1};
    obj->deposit(banknotesCount);
    int amount = 100;
    vector<int> param_2 = obj->withdraw(amount);
    return 0;
}

/*

ATM atm = new ATM();
atm.deposit([0,0,1,2,1]); // Deposits 1 $100 banknote, 2 $200 banknotes,
                          // and 1 $500 banknote.
atm.withdraw(600);        // Returns [0,0,1,0,1]. The machine uses 1 $100 banknote
                          // and 1 $500 banknote. The banknotes left over in the
                          // machine are [0,0,0,2,0].
atm.deposit([0,1,0,1,1]); // Deposits 1 $50, $200, and $500 banknote.
                          // The banknotes in the machine are now [0,1,0,3,1].
atm.withdraw(600);        // Returns [-1]. The machine will try to use a $500 banknote
                          // and then be unable to complete the remaining $100,
                          // so the withdraw request will be rejected.
                          // Since the request is rejected, the number of banknotes
                          // in the machine is not modified.
atm.withdraw(550);        // Returns [0,1,0,0,1]. The machine uses 1 $50 banknote
                          // and 1 $500 banknote.
*/