#ifndef TEST_FUNC_DEMO_H
#define TEST_FUNC_DEMO_H
///home/vietskr/Desktop/DSA/BTL/phase1/
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "list/XArrayList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"

#include <sstream>
#include <iostream>
#include <type_traits>
#include <iomanip>
#include <string>

using namespace std;

void listDemo(){
    cout << "somethings from here" << endl;
    int item[]={19, 34, 22, 4, 8, 32, 78, 89};
    XArrayList<int> list;
    for(int i=0; i < sizeof(item)/sizeof(int);i++){
        list.add(item[i]);
    }
    cout << list.toString() << endl;

    for (int i = 0; i < list.size(); i++)
    {
        cout << list.get(i) << ", ";
    }
    cout << endl;
    
    
    for (XArrayList<int>::Iterator it = list.begin(); it != list.end(); it++)
    {
        //int v = *it;
        cout << *it << ", ";
    }
    cout << endl;

    XArrayList<int>::Iterator it;
    it = list.begin();
    while (it != list.end())
    {
        cout << *it << ", ";
        it++;
    }
    cout << endl;
    
}

void stackInOut(){
    string input = "EAS*Y*QUE***ST***IO*N***ABCD";
    stringstream os;
    Stack<char> stack;
    for(int i=0; i < input.length(); i++){
        char cur = input[i];
        if(cur == '*'){
            char top = stack.pop();
            os << top;
        }
        else stack.push(cur);
    }
    string output = os.str();
    cout << "Sequence from stack: " << output << endl;
    cout << "Current stack (from top): [";
    while (!stack.empty())
    {
        cout << stack.pop();
    }
    cout << "]" << endl;
    
}
void queueInOut(){
    string input = "EAS*Y*QUE***ST***IO*N***ABCD";
    stringstream os;
    Queue<char> queue;
    for(int i=0; i < input.length(); i++){
        char cur = input[i];
        if(cur == '*'){
            char top = queue.pop();
            os << top;
        }
        else queue.push(cur);
    }
    string output = os.str();
    cout << "Sequence from stack: " << output << endl;
    cout << "Current stack (from top): [";
    while (!queue.empty()) cout << queue.pop();
    cout << "]" << endl;
}
void stackReading(){
    string input = "LA*STI*N*FIR*ST**OU*T******";
    int begin=0,end=4;
    stringstream os;
    Stack<char> stack;
    for(int i=0; i < input.length(); i++){
        char cur = input[i];
        if(cur == '*'){
            char top = stack.pop();
            os << top;
        }
        else stack.push(cur);
    }
    string output = os.str();
    cout << "Current stack (from top): [";
    for(Stack<char>::Iterator it = stack.top(); it != stack.bottom();it++)
        cout<< *it;
    cout << "]";
    cout << endl << "Stack: from " << begin << " to " << end << " (from top): ";
    int count=0;
    while (!stack.empty() && count < end)
    {
        cout << stack.pop();
        count++;
    }
    cout << endl;
}
void checkBalanced(){
    string input = "[(3 + 4) * 6] - [(4-2) - (22*2)]]";
    string open_list = "[{(";
    string close_list = ")}]";
    Stack<char> stack;

    bool matched = true;
    for(int i=0; i < input.length();i++){
        char c = input[i];
        if(open_list.find(c) != -1) stack.push(c);
        else
        {
            int close_idx = close_list.find(c);
            if(close_idx != -1){
                char expected_char = open_list[close_idx];

                char open_char;
                if(stack.empty()){
                    cout << "Delimited are imbalanced";
                    return;
                }
                else open_char = stack.pop();
            }
        }
    }
    if(!stack.empty()) matched = false;
        if(matched) cout << "Delimiters are balacened";
        else cout << "Delimiters are imbalacened";
}
void toBinary(int dec){
    Stack<char> stack;
    int count =0;
    while (dec > 0)
    {
        char bit = (char)('0'+(dec % 2));//num2char
        if(count >= 4){stack.push('.'); count =0;}
        stack.push(bit);
        dec = dec/2;
        count++;
    }
    while (!stack.empty())
    {
        char bit = stack.pop();
        cout << bit;
    }
    cout << endl;
}
void printReverseStr(){
    string input = "EAS*Y*QUE***ST***IO*N***ABCD";
    Stack<char> stack;
    stringstream os;
    for(int i=0; i < input.length(); i++) stack.push(input[i]);
    int i=0;
    cout << stack.peek() << endl;
    cout << stack.pop() << endl;
    while (!stack.empty())
    {
        input[i] = stack.peek();
        i++;
        char top = stack.pop();
        os << top;
    }
    string output = os.str();
    cout << "Compare in n out: " << input.compare(output) << endl;
    cout << "Sequence from stack: " << output << endl;
    cout << "Reverse Sequence input: " << input << endl;
}
#endif