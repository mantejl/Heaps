#include "heap.h"
#include <vector>
#include <iostream>

using namespace std;  

int main() {
    Heap <int> heap (4); 
    heap.push(9); 
    heap.push(1); 
    heap.push(2); 
    heap.push(6); 
    heap.push(83); 
    heap.push(12); 
    heap.push(11); 
    heap.push(5); 
    heap.push(13); 
    heap.push(19); 
    heap.push(0); 
    cout << heap.top() << endl; 
    heap.pop();
    cout << heap.top() << endl; 
    heap.pop();
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.push(65); 
    heap.push(25); 
    heap.push(37); 
    heap.push(19); 
    heap.push(3);
    heap.push(34); 
    for (int i = 0; i < 5; i++) {
        cout << heap.top() << endl; 
        heap.pop(); 
    }
    
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl; 
    heap.pop(); 
    cout << heap.top() << endl;
}

