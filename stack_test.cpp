#include "stack.h"
#include <iostream>

using namespace std; 

int main() {
    Stack<int> s; 
    cout << s.empty() << endl;
    cout << s.size() << endl;  
    //s.top(); commented this line out to prevent my program from aborting 
    //s.pop(); commented this line out to prevent my program from aborting 
    s.push(3); 
    s.push(9); 
    s.push(11); 
    s.push(6); 
    s.push(2); 
    cout << s.top() << endl; 
    cout << s.size() << endl; 
    s.pop(); 
    s.pop(); 
    s.pop(); 
    s.pop(); 
    cout << s.top() << endl; 
    cout << s.top() << endl; 
    cout << s.top() << endl; 
    cout << s.empty() << endl; 
    return 0; 
}