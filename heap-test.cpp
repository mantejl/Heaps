#include "heap.h"
#include <vector>
#include <iostream>

using namespace std;  

int main() {
    Heap <int> heap; 
    //cout << heap.empty() << endl; 
    heap.push(9); 
    heap.push(1); 
    heap.push(6); 
    heap.push(12); 
    heap.push(8); 
    //cout << heap.empty() << endl; 
    heap.push(5); 
    heap.push(19); 
    cout << heap.top() << endl; 
    heap.pop();
    cout << heap.top() << endl; 
    heap.push(1); 
    cout << heap.top() << endl; 
}