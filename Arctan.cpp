#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include <thread>
#include <time.h>

#include <gmpxx.h>

using namespace std;

vector<mpq_class> arctan(int a, int kai) {
    bool debug = false;

    cout << endl << "Start Arctan 1/" << a << endl;

    mpz_class x = a * a;
    long n = pow(2, kai - 1);
    n = kai;
    long N = n;
    vector<mpq_class> suretu;

    for (long i = 0; i < n; i++) {
        mpq_class temp(x * (4 * i + 3) - 4 * i - 1,
                       x * (4 * i + 1) * (4 * i + 3));
        suretu.push_back(temp);
    }

    // mpq_class saigo=gmp_pow(x,2*n);
    // saigo*=a*(4*n+1);
    // cout<<saigo<<endl;
    // saigo=1/saigo;

    mpq_class saigo = a;
    saigo *= 4 * n + 1;
    mpz_class y = x * x;
    for (long i = 0; i < N; i++) {
        if (n == 0) {
            break;
        }
        if (n % 2 == 1) {
            saigo *= y;
        }
        n /= 2;
        if (n != 0) {
            y = y * y;
        }
    }
    saigo = 1 / saigo;

    cout << "from n = 0  to n = " << N * 2 << endl;

    for (int k = 0; k < kai - 1; k++) {
        cout << k << "times. There are " << suretu.size() << " items." << endl;
        x = x * x;
        vector<mpq_class> suretu_new;
        long nagasa = suretu.size();
        for (long i = 0; i < nagasa / 2; i++) {
            suretu_new.push_back(suretu[2 * i] + suretu[2 * i + 1] / x);
        }
        if (nagasa % 2 == 1) {
            suretu_new.push_back(suretu[nagasa - 1]);
        }
        suretu = suretu_new;
        if (suretu.size() == 1) {
            break;
        }
    }

    cout << "Finished " << N * 2 << " times." << endl;

    // mpq_class saigo = x * x * (N * 4 + 1);
    // saigo = 1 / saigo;
    // mpq_class saigo=0;

    suretu[0] /= a;
    mpq_class ue = suretu[0] + saigo;
    cout << "Finished Arctan 1/" << a << endl;
    return {suretu[0], ue};
}

int main() {

    long kaisu;
    // kaisu = 23;
    // kaisu = 25;
    // kaisu = 15;
    // kaisu=200;
    // kaisu=pow(2,16);
    long goal;
    long jogen=pow(10,8);
    long kagen=100;
    cout << "How many decimal places do you calculate to?:";
    cin >> goal;
    goal=max(kagen,min(jogen,goal));


    cout << "Start! This program will calculate pi to " << goal << " digits."
         << endl;

    vector<int> bunbo = {268, 682, 1568, 4662, 12943, 32807};
    vector<int> keisu = {183, 32, 95, 44, -166, -51};

    // bunbo={5,239};
    // keisu={4,-1};

    for (int i = 0; i < bunbo.size(); i++) {
        keisu[i] *= 4;
    }

    vector<vector<mpq_class>> result;

    for (int i = 0; i < bunbo.size(); i++) {
        kaisu = goal / log10(bunbo[i]) / 4 + 1;
        // cout << kaisu << endl;
        result.push_back(arctan(bunbo[i], kaisu));
    }

    cout << endl << "Obtain total" << endl;

    mpq_class sita = 0;
    mpq_class ue = 0;
    for (int i = 0; i < bunbo.size(); i++) {
        // cout<<result[i][0]<<endl;
        // cout<<result[i][1]<<endl;
        cout << "Add Arctan 1/" << bunbo[i] << endl;
        if (keisu[i] > 0) {
            sita += keisu[i] * result[i][0];
            ue += keisu[i] * result[i][1];
        } else {
            sita += keisu[i] * result[i][1];
            ue += keisu[i] * result[i][0];
        }
    }

    // time_t jikan = clock();
    // vector<mpq_class> a= arctan(5, kaisu);
    // cout << "Jikan:" << clock() - jikan << endl;
    // vector<mpq_class> b = arctan(239, kaisu-1);

    // cout << endl << "Arctan Finished" << endl;
    // mpq_class sita = 16 * a[0] - 4 * b[1];
    // mpq_class ue = 16 * a[1] - 4 * b[0];
    // cout <<endl<< "Finished" << endl;

    // mpq_class temp = 10;
    // temp /= 3;
    // sita = temp;
    // ue = temp;
    mpf_set_default_prec(67138550);
    // mpf_set_default_prec(400000000);

    // mpf_set_default_prec(10000);
    // mpf_set_default_prec(10000000);
    long keisan_ketasu = (goal + 100) / log10(2);
    cout <<endl<<"significant digits:"<< (int)(keisan_ketasu * log10(2)) << endl;
    mpf_set_default_prec(keisan_ketasu);

    cout << "change a rational number to a decimal." << endl;

    mpf_class pi = sita;
    mpf_class Pi = ue;
    cout << pi << endl;
    cout << "change a decimal to string." << endl;

    mp_exp_t exp;
    string moji, Moji;
    moji = pi.get_str(exp);
    Moji = Pi.get_str(exp);
    moji.insert(1, ".");
    Moji.insert(1, ".");
    long naga = min(moji.size(), Moji.size());
    int lim = 0;
    for (int i = 0; i < naga; i++) {
        if (moji[i] == Moji[i]) {
            lim++;
            cout << moji[i];
            if (i % 12 == 1) {
                cout << " ";
            }
        } else {
            break;
        }
    }
    cout << endl;
    cout << lim - 1 << "桁" << endl;

    return 0;
}
