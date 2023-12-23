#include<iostream> 
#include<stack>
using namespace std; 
int main() 
{ 
    std::stack<int> stackData;
    stackData.push(0);
    stackData.push(1);
    stackData.push(2);
    stackData.push(3);
 
    // Get the size of stack
    cout << stackData.size() << endl;
    // Get the top element of stack
    cout << stackData.top() << endl;
    // Pop the top element of stack
    stackData.pop();
    
}