#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ifstream fin; ofstream fout;
    for(int i = 1; i <= 10; ++i)
    {
        fin.open("./inputs/empat_" + to_string(i) + ".in");
        ll n;
        fin >> n;
        fin.close();
        fout.open("./outputs/empat_" + to_string(i) + ".out");
        fout << 1 << " ";
        for(int i = 0; i < 3; ++i)
            fout << 0 << " ";
        fout.close();
    }
    return 0;
}