// Given a collection of intervals, merge all overlapping intervals.

#include <bits/stdc++.h>
using namespace std;

struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval a, Interval b)
{
  return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &A)
{
  sort(A.begin(), A.end(), comp);
  vector<Interval> ans;
  for (auto x : A)
  {
    if (ans.size() == 0)
    {
      ans.push_back(x);
    }
    else
    {
      Interval p = ans.back();
      if (x.start > p.end)
      {
        ans.push_back(x);
      }
      else
      {
        ans.pop_back();
        Interval t = Interval(p.start, max(p.end, x.end));
        ans.push_back(t);
      }
    }
  }
  return ans;
}

// TIME COMPLEXITY - O(nlogn)