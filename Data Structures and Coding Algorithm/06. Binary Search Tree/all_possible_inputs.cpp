/*
To generate all the possible inputs which leads to the creation of same binary search tree 

Approach : Divide and Conquer
1> Answer starts from the bottom, recieve the child nodes and make its permutation 
2> The permutation is to be passed onto parent node, i have used vector<vector<int>> here to pass on the permutations
3> When the parent node receives the vector<vector<int>> containing permutation nodes, make a permutation of those as well
   with left and right child node's permutation
4> Permutation should be strictly parent first and followed by child, which has been done using L & R containing string which
   which occupies Left child's permutation element and Right child's permutation elements
5> For example, consider a tree
                    5
                /       \
              3           8
            /  \       /    \
           1     2    7      9

        3 receives -> from left : [[1]] ; from right [[2]]
        So, permutation at 3 is : self data(3 here) followed by LR, RL (here only 2 permutations are possible)
        3 passes [[3,1,2],[3,2,1]] to 5
        similarly, 8 passes [[8,7,9],[8,9,7]]

6>  5 receives -> from left :  [[3,1,2],[3,2,1]] ; from right [[8,7,9],[8,9,7]]
    left vector[0] contains 3 elements, so 3 L, simillarly, 3 R for right 
    now we have set of [L,L,L,R,R,R] which will contain elements left and right vector elements;
    We create a permutation of L,L,L,R,R,R using sets(to avoid duplicates) and fit randomly(either left or right)
    But : Order is maintained while fill, for example, FIRST L to be filled will be 3 and then 1 and then 2 for vector [3,1,2];
    (parent then child permutation);

*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct btree {
  int data;
  btree * lc;
  btree * rc;
};typedef struct btree * BSTPTR;

//for creation of bst
void insert(BSTPTR & node, int x) {
  if (!node) {
    node = new(btree);
    node -> data = x;
    return;
  } 
  else {
    if (node -> data > x)
      insert(node -> lc, x);
    else
      insert(node -> rc, x);
    return;
  }
}

// to generate permutations of string containing L and R 
void permutations(string s, int i, int n, set < string > & possible) {
  if (i == n) {
    possible.insert(s);
    return;
  }
  for (int k = i; k <= n; ++k) {
    swap(s[k], s[i]);
    permutations(s, i + 1, n, possible);
    swap(s[k], s[i]);
  }
}

// the core function to pass on child's permutation to parent node
vector <vector<int>> findsubseq(BSTPTR tree) {
  vector <vector<int>> seq;

  //if NULL, return empty vector<vector<int>>
  if (tree == NULL) {
    vector < int > temp;
    seq.pb(temp);
    return seq;
  } 
  //if leaf node, return vector<vector<int>> containing its value only, -> [[leaf->data]]
  else if (tree -> lc == NULL && tree -> rc == NULL) {
    vector < int > temp;
    temp.pb(tree -> data);
    seq.pb(temp);
    return seq;
  }

  vector <vector<int>> leftseq = findsubseq(tree -> lc); //receieves left child permutation
  vector <vector<int>> rightseq = findsubseq(tree -> rc); // receives right child permutation
  string left_right; // string to contain L or R to fit left or right vector's value

  //making of left_right string "LLLRRR" 
  for (int i = 0; i < leftseq[0].size(); ++i)
    left_right.pb('L');
  for (int i = 0; i < rightseq[0].size(); ++i)
    left_right.pb('R');

  //will contain all possible permutation of LLLRRR...
  set <string > possible_left_right;
  permutations(left_right, 0, left_right.size() - 1, possible_left_right);
  
  for (auto vectorleft: leftseq) {
    for (auto vectorright: rightseq) {
      for (auto occupy: possible_left_right) {

        vector < int > possibleseq;
        possibleseq.pb(tree -> data);
        int addleft = 0, addright = 0; // indexes set to 0 for left nd right vector to maintain order while filling
        for (int add = 0; add < occupy.size(); ++add) {
          if (occupy[add] == 'L') {
            possibleseq.pb(vectorleft[addleft]);//if ;L', insert Left vector's value
            ++addleft;
          } 
          else{
            possibleseq.pb(vectorright[addright]);
            ++addright;
          }
        }
        seq.pb(possibleseq);
      }
    }
  }
  return seq;
}

int main() {
  BSTPTR tree = NULL;
  int reader;
  while (cin >> reader && reader != -1)
  insert(tree, reader);//this makes the tree

  vector <vector<int>> finalanswer = findsubseq(tree);
  //printing of all possible inputs
  for (auto sequences: finalanswer) {
    for (auto elements: sequences)
      cout << elements << " ";
    cout << endl;
  }
}
