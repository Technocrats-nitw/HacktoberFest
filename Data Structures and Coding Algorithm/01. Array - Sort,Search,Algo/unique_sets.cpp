#include <bits/stdc++.h>
using namespace std;

vector<string> getsubs(string str)
{
    vector<string> v;
    for (int i = 0; i < str.length(); i++)
    {
        v.push_back(str.substr(0, i) + str.substr(i + 1, str.length() - 1));
    }
    return v;
}

bool compare(string a, string b){
    return a.length() <= b.length(); 
}

int main()
{
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }
        sort(words.begin(),words.end(),compare);
    cout << words[0];
    map<string, int> mp;
    int maxii = INT_MIN;
    for (int j = 0; j < words.size(); j++)
    {
        vector<string> v = getsubs(words[j]);
        int maxi = 0;
        for (int i = 0; i < v.size(); i++)
        {
            maxi = max(maxi,mp[v[i]]);
        }
        mp[words[j]] = maxi+1;
        maxii = max(maxii,mp[words[j]]);
    }
    cout << maxii;
    return 0;
}
