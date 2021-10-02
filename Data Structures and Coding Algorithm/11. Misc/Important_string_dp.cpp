#include <bits/stdc++.h>
using namespace std;

// LCS (Longest Common Subsequence)
// Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.
// You need to return the length of such longest common subsequence.

int LCS(string A, string B)
{
  int m = A.length();
  int n = B.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (A[i - 1] == B[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }
  return dp[m][n];
}

// TIME COMPLEXITY - O(M*N)
// SPACE COMPLEXITY - O(M*N)

// #####################################################
// Edit Distance
// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

int EditDistance(string A, string B)
{
  int m = A.length();
  int n = B.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1));
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0)
      {
        dp[i][j] = j;
      }
      else if (j == 0)
      {
        dp[i][j] = i;
      }
      else if (A[i - 1] == B[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        int min = (dp[i - 1][j] < dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        min = (min < dp[i - 1][j - 1]) ? min : dp[i - 1][j - 1];
        dp[i][j] = 1 + min;
      }
    }
  }
  return dp[m][n];
}

// TIME COMPLEXITY - O(M*N)
// SPACE COMPLEXITY - O(M*N)

// #######################################################
// LPS (Longest Palindromic subsequence)
// Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.
// You need to return the length of longest palindromic subsequence in A.

int LPS(string str)
{
  int n = str.length();
  int i, j, cl;
  int L[n][n];
  for (i = 0; i < n; i++)
    L[i][i] = 1;
  for (cl = 2; cl <= n; cl++)
  {
    for (i = 0; i < n - cl + 1; i++)
    {
      j = i + cl - 1;
      if (str[i] == str[j] && cl == 2)
        L[i][j] = 2;
      else if (str[i] == str[j])
        L[i][j] = L[i + 1][j - 1] + 2;
      else
        L[i][j] = max(L[i][j - 1], L[i + 1][j]);
    }
  }
  return L[0][n - 1];
}

// TIME COMPLEXITY - O(N*N)
// SPACE COMPLEXITY - O(N*N)
