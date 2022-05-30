#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <stdlib.h>


using namespace std;


int main()
{

    string input;  
    queue<int> digitQueue;
    stack<char> operatorStack;

    while (cin >> input){
        if (isdigit(input[0])){
            int intInput = atoi(&(input[0]));
            digitQueue.push(intInput);

        }
        else if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/'){
            operatorStack.push(input[0]);
        }

        if (cin.get() == '\n'){
            break;
        }
        
    }


    if (digitQueue.size() - operatorStack.size() != 1){
        cout << "Error";
    }
    else {
    while (!digitQueue.empty()) {
        cout << ' ' << digitQueue.front();
        digitQueue.pop();
        }
    
    cout << endl;

        while (!operatorStack.empty()) {
        cout << ' ' << operatorStack.top();
        operatorStack.pop();
        }
    
    }
    return 0;
}
