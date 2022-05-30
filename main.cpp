#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <stdlib.h>


using namespace std;

float returnSum( float int1, float int2, char oper){
   float sum;
   if(oper == '+')
       sum = float(int1)+float(int2);
        

   else if(oper == '-')
       sum = float(int1)-float(int2);


   else if(oper =='/')
       sum = float(int1)/float(int2);

   else if(oper=='*')
       sum = float(int1)*float(int2);
      
return sum;
}

int main()
{

    string input;  
    queue<int> digitQueue;
    stack<char> operatorStack;

    cout << "Input: ";
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
    /*
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
    */

   float sum = 0;
   if (operatorStack.size() > 1) {
        for (int i = 0; i < operatorStack.size()-1; i++){
            cout << '(';
        }
        float temp1, temp2;
        char tempOpp;

        cout << digitQueue.front() << " " << operatorStack.top() << " ";
        temp1 = digitQueue.front();
        tempOpp = operatorStack.top();

        digitQueue.pop();
        operatorStack.pop();
        cout << digitQueue.front() << ")"; 

        temp2 = digitQueue.front();
        digitQueue.pop();
        sum = returnSum(temp1, temp2, tempOpp);
        

        while (operatorStack.size() > 1){
            cout << " " << operatorStack.top() << " " << digitQueue.front() << ")";
            sum = returnSum(sum, digitQueue.front(), operatorStack.top());
            operatorStack.pop();
            digitQueue.pop();
        }

        sum = returnSum(sum, digitQueue.front(), operatorStack.top());
        cout << " " << operatorStack.top() << " " << digitQueue.front() << " = " << sum;
        operatorStack.pop();
        digitQueue.pop();
    }
    else if(operatorStack.size() == 1){
        float temp1, temp2;
        char tempOpp;

        cout << digitQueue.front() << " " << operatorStack.top() << " ";
        temp1 = digitQueue.front();
        tempOpp = operatorStack.top();

        digitQueue.pop();
        operatorStack.pop();
        temp2 = digitQueue.front();
        cout << digitQueue.front();
        sum = returnSum(temp1, temp2, tempOpp);
        cout << " = " << sum; 
    }
    else{
        cout << digitQueue.front() << " = " << digitQueue.front();
    }
    return 0;
}