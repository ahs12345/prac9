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
    bool seenInt = false;
    bool seenOpp = false;

    cout << "Input: ";
    while (cin >> input){
        if (isdigit(input[0])){
            if (!seenOpp){
                cout << "Error";
                return 1;
            }
            int intInput = atoi(&(input[0]));
            digitQueue.push(intInput);
            seenInt = true;

        }
        else if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/'){
            if (seenInt){
                cout << "Error";
                return 2;
            }
            operatorStack.push(input[0]);
            seenOpp = true;
        }

        if (cin.get() == '\n'){
            break;
        }
        
    }



    if (digitQueue.size() - operatorStack.size() != 1 || digitQueue.size() == 0){
        cout << "Error";
        return 0;
    }
    

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

