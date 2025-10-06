/*
* Building Max Heap From Array.
! Important Points:
*   1. Root is at index 0 in array.
*   2. Left child of i-th node is at (2*i + 1)th index.
*   3. Right child of i-th node is at (2*i + 2)th index.
*   4. Parent of i-th node is at (i-1)/2 index.

    input array: {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
                 1
               /    \
             3        5
           /  \     /  \
         4      6  13  10
        / \    / \
       9   8  15 17
    
    final array: {17 15 13 9 6 5 10 4 8 3 1}
                  17
                /    \
              15      13
             /  \     / \
            9     6  5   10
           / \   / \
          4   8 3   1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> input = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    printHeap(input);
}


void printHeap(vector<int> input){
    cout << "The Heap in to array:\n";
    for(int i : input){
        cout << i << ", ";
    }
    cout << "\n";
}
