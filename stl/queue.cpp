#include<queue>
using namespace std; 

int main() 
{ 
    std::queue <int> q_data;
    q_data.push(1);
    q_data.push(2);
    q_data.push(3);
    q_data.push(4);

    // Get the size of queue
    cout << q_data.size() << endl;
    // Get the first element of queue
    cout << q_data.front() << endl;
    // Get the last element of queue
    cout << q_data.back() << endl;
    // Pop the first element of queue
    q_data.pop();
    
 
    return 0;
}