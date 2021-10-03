/* 
       HeapSort

       Time Complexity: Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and the overall time complexity of Heap Sort is O(nLogn).
*/
#include<bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node ind which is
// an index in array A[]. n is size of heap
void heapify(vector<int>&A,int n,int ind){
    int x=ind;         // Initialize x as root
    int left=2*ind+1;  // left = 2*i + 1
    int right=2*ind+2; // right = 2*i + 2
     // If left child is larger than root
    if(left<n && A[left]>A[x]) x=left;
    // If right child is larger than largest(x) so far
    if(right<n && A[right]>A[x]) x=right;
    
    // If largest is not root
    if(x!=ind){
        swap(A[ind],A[x]);
        // Recursively heapify the affected sub-tree
        heapify(A,n,x);
    }
}
void heap_sort(vector<int>&A){
    int n=(int)A.size(),i;
    
    // Build heap (rearrange array)
    for(i=n/2-1;i>-1;i--)
    heapify(A,n,i);
    
    // One by one extract an element from heap
    for(i=n-1;i>-1;i--){
        swap(A[0],A[i]);  // Move current root to end
        heapify(A,i,0); // call max heapify on the reduced heap
    }
}
int main()
{
    int n,i,j; 
    cin>>n; // length of array
    vector<int>v(n); // Initialize
    for(i=0;i<n;i++) cin>>v[i]; // input
      heap_sort(v); 
      // print the sorted array
    for(i=0;i<n;i++) cout<<v[i]<<" ";

    return 0;
}
