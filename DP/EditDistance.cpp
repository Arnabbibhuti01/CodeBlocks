/*
We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:
Deletion of a character.
Replacement of a character with another one.
Insertion of a character.
We have to return the minimum number of operations required to convert S1 to S2 as our answer.
*/
#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDist(string str1, string str2, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
    return 1 + min(editDist(str1, str2, m, n - 1), editDist(str1, str2, m - 1, n), editDist(str1, str2, m - 1, n - 1));
}
int main() {
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2, str1.length(), str2.length());

    return 0;
}