
//Scramble_Strings:

/*
Scramble a string s to get a string t using the following algorithm:

1)If the length of the string is 1, stop.
2)If the length of the string is > 1, do the following:
       2.1)Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
       2.2)Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
       2.3)Apply step 1 recursively on each of the two substrings x and y.

Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is s2.
As there is one possible scenario that led s1 to be scrambled to s2, we return true.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This recursive fumction is used to return true if string are scrambled or return false.
bool check_scramble(string s1, string s2)
{
    if (s1 == s2)
        return true;
    int cnt[26] = {0};
    int l = s1.length();
    for (int i = 0; i < l; i++)
    {
        cnt[s1[i] - 'a']++;
        cnt[s2[i] - 'a']--;
    }
    // if both strings contain different characters then it is impossoble to make them scrambled
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
            return false;
    }
    for (int i = 1; i < l; i++)
    {
        // check for ith length substring from begining for both strings and from ith string to end of the string for both strings
        if (check_scramble(s1.substr(0, i), s2.substr(0, i)) && check_scramble(s1.substr(i), s2.substr(i)))
            return true;

        // check for ith length substring from begining for one string and from (l-i)th length of another string to end of string and from ith string to end of the string for one string and from begining to (l-i)th length of one string

        if (check_scramble(s1.substr(0, i), s2.substr(l - i)) && check_scramble(s1.substr(i), s2.substr(0, l - i)))
            return true;
    }
    // if in recursion two string are not scramble then return false.
    return false;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (check_scramble(s1, s2))
        cout << "True:Strings are scrambled string";
    else
        cout << "Fasle:Strings are not scrambled strings";
}