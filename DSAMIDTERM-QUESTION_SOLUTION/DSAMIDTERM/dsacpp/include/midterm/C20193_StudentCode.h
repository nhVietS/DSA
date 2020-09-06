/*************************************************************************
 * STUDENT NAME: 
 * STUDENT CODE: 
 *************************************************************************
 Ho Chi Minh City University of Technology
 Faculty of Computer Science and Engineering
 
                            MID-TERM EXAM               
               DATA STRUCTURES AND ALGORITHMS (CO2003)
                        Class: 20193 (Group: DTQ1)
                  (Sept. 04, 2020/8h15AM - 10hAM)
                      (Online at Room 508A4)
 ************************************************************************
                            IMPORTANT NOTE
                        --------------------------
 1/ Students can use laptop and internet or 4G during the examination.
 2/ However, students are REQUIRED to do the exam INDEPENDENTLY.
 3/ Any solution with helps from other people will NOT SCORED, and will GET ZERO!!!
                        --------------------------
 GUIDELINES:
 ##########: Read questions in comments below and solve them by filling code
 in the following function
 *************************************************************************
 SECTION 1: C++ PROGRAMMING       (Q1-Q7)   : 7  questions: [-4:4 points]/each question
 SECTION 2: LIST                  (Q8-Q17)  : 10 questions: [ 0:4 points]/each question
 SECTION 3: STACK and QUEUE       (Q18-Q22) : 5  questions: [ 0:4 points]/each question
 SECTION 4: TREE                  (Q23-Q25) : 3  questions: [ 0:4 points]/each question
 *************************************************************************
 Files Accompanied:
 
 1/ midterm/C20193_StudentCode.h
 2/ list/IList.h + list/XArrayList.h
 3/ stacknqueue/IDeck.h
 4/ main.cpp
 *************************************************************************
 HOW TO SUBMIT:
 1/ Change name of "midterm/C20193_StudentCode.h", replaced with your [Student Code]
 2/ COPY  "midterm/C20193_StudentCode.h" to the SHARED FOLDER, given during the exam
 *************************************************************************/

#ifndef C20193_STUDENTCODE_H
#define C20193_STUDENTCODE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


///////////////////////////////////////////////////////////////////////////
//////////////////////SECTION 1: C++ PROGRAMMING      /////////////////////
///////////////////////////////////////////////////////////////////////////
/* Question 1:
 * 
 * a) Add ONLY ONE constructor to class SNode to:
 *    force the compilation of the two three lines in function "cppDemo1" without any errors, 
 *    and 
 *      > p1 points to an object with: data = 100, next = 0
 *      > p2 points to an object with: data = 200, next = 0
 *      > p3 points to an object with: data = -1, next = 0
 * b) Fill function "cppDemo1", from the line with "YOUR CODE HERE" to:
 *      > delete objects pointed by p1, p2, and p3
 */
class SNode{
public:
    int data;
    SNode* next;
    
    /*YOUR CODE HERE*/
    
};

void cppDemo1(){
    SNode* p1 = new SNode(100, 0);
    SNode* p2 = new SNode(200);
    SNode* p3 = new SNode();
    /*YOUR CODE HERE*/
    
}

/* Question 2:
 * 
 * Fill function "cppDemo2", from the line with "YOUR CODE HERE"
 * to do the tasks specified in the function
 */

int compare(SNode& lhs, SNode& rhs){
    /*
    compare(SNode& lhs, SNode& rhs): compare two SNode objects:
       return -1 if lhs.data less-than rhs.data
       return +1 if lhs.data greater-than rhs.data
       otherwise (ie., equal): return 0
    */
    if((lhs.data - rhs.data) < 0) return -1;
    else if( (lhs.data - rhs.data) > 0) return +1;
    else return 0;
}
void cppDemo2(){
    SNode* p1 = new SNode(100, 0);
    SNode* p2 = new SNode(200, 0);
    /*YOUR CODE HERE, to do:
     a) call function "compare" to compare two object pointed by p1 and p2 and the print the result
     b) delete objects pointed by p1 and p2
     */
    
}


/* Question 3:
 * 
 * Fill function "snode2str" and "cppDemo3", from the line with "YOUR CODE HERE"
 * to do the tasks specified in the function
 */
#include <sstream> //for using stringstream
string snode2str(SNode& node){
    /*YOUR CODE HERE, to do:
     > convert "node" to string as example below:
     > Example: 
            + node with "data"=100, "next" ==0: will return (data:100, next:0)
            + node with "data"=100, "next" != 0: will return (data:100, next:->)
     */
    
}
void cppDemo3(){
    SNode node(100);
    SNode* ptr = new SNode(200, &node);
    
    /*YOUR CODE HERE, to do:
     > print SNode objects in "node" and pointed by "ptr", using "node2str"
     > delete objects allocated
     */
    
}

/* Question 4:
 * 
 * Fill function "cppDemo4", from the line with "YOUR CODE HERE"
 * to do the tasks specified in the function
 */

void cppDemo4(){
    /*YOUR CODE HERE, to do: the following tasks: (a) to (d)
     */
    SNode ** nodes;
    /*
    (a) initialize objects with a dynamic array of 10 pointers to SNode (i.e., SNODE* )
    (b) initialize items in "nodes" with dynamic SNode objects having data from 0 to 9, and next =0
     That means:
        > nodes[0] point to a dynamic object with data and next are: (data:0, next:0)
        > nodes[1] point to a dynamic object with data and next are: (data:1, next:0)
        ...
        > nodes[9] point to a dynamic object with data and next are: (data:9, next:0)
     (c) print all SNode objects stored in "nodes"
     (d) delete all SNode objects stored in "nodes", and then delete "nodes"
     */
    
}


/* Question 5:
 * 
 * Fill function "cppDemo5", from the line with "YOUR CODE HERE"
 * to do the tasks specified in the function
 */

#include <random>
void cppDemo5(){
    int array[] = {1,2,3,4,5,6};
    /*YOUR CODE HERE, to do:
     a) initialize items in "array" with random number from a uniform distribution in range [-5, 5]
     b) print the array in the format as the example following:
     EXAMPLE-BEGIN:
     
        3
        0
        2
        5
       -1
       -2
     SUM: 7
     
     EXAMPLE-END
     c) compute the sum of all items in the array and print it out screen as the above example.
     */
    
    
}

/* Question 6:
 * 
 * Fill function "cppDemo6", from the line with "YOUR CODE HERE"
 * to do the tasks specified in the function
 */
void cppDemo6(){
    /*YOUR CODE HERE, to do: the tasks specified below: (a), (b), (c) and (d) */
    int size = 10;
    int *array = new int[size]; 
    /*
     (a) initialize array with a dynamic array of integers with length=size (i.e, 10) (variable above)
     (b) initialize items in "array" with random number from uniform distribution in range [10, 100]
     (c) determine the minimum value stored in "array and its index"
     (d) delete "array"
     */
    
    
}

/* Question 7:
 * 
 * Fill function "printREV" and "cppDemo7"
 * to do the tasks specified in those functions
 */

void printREV(int* array, int size){
    /*USE RECURSIVE TECHNIQUE to:
     print array of length ="size" in reversed ordered
     */
    
    
}

void cppDemo7(){
    int array[] = {1,2,3,4,5,6};
    /*Call printREV to print array, expected: 6,5,4,3,2,1, */
    
}
///////////////////////////////////////////////////////////////////////////
//////////////////////SECTION 2: LIST                 /////////////////////
///////////////////////////////////////////////////////////////////////////
//File attached: XArrayList.h (full code)
///////////////////////////////////////////////////////////////////////////

#include "list/XArrayList.h"

/* Question 8:
 * 
 * Fill function "listDemo1"
 * to do the tasks specified in those functions
 */
void listDemo1(){
    int array[] = {1,2,3,4,5,6};
    /*YOUR CODE HERE, to do:
     a) declare a list of type XArrayList, element type is integer
     b) add all items given in "array" to the list above.
     */
    
}


/* Question 9:
 * 
 * Fill function "listDemo2"
 * to do the tasks specified in those functions
 */

#include <sstream>
void listDemo2(){
    XArrayList<int> list;
    list.add(100); list.add(200); list.add(300);
   
    /*Use Iterator:
         > to traverse "list" (in combination with for-loop) and 
         > to print items of "list" to screen with format given in below example
     
     Example: output of the above list: [100, 200, 300]
     */
    
}


/* Question 10:
 * 
 * Fill function "listDemo3"
 * to do the tasks specified in those functions
 */
#include <sstream>
void listDemo3(){
    XArrayList<int> list;
    list.add(100); list.add(200); list.add(300);
    /*Use Iterator:
         > to traverse "list" (in combination with while-loop) and 
         > to print items of "list" to screen with format given in below example
     
     Example: output of the above list: [100, 200, 300]
     */
    
}


/* Question 11: fill function "listDemo4" for the following contents
 * contents:
 *  1/ Generate "count" integers using uniform distribution, in range ["left", "right"]
 *  2/ Determine the histogram of generated numbers
 *  3/ Print the histogram (normalized) with format in the following example:
 
    [EXAMPLE: BEGIN]
    -5: [9%] *********
    -4: [9%] *********
    -3: [9%] *********
    -2: [9%] *********
    -1: [9%] *********
     0: [8%] ********
     1: [9%] *********
     2: [9%] *********
     3: [9%] *********
     4: [9%] *********
     5: [8%] ********
    [EXAMPLE: END]
 

 */
void listDemo4(){
    int left = -5, right = 5;  //11 different integers inside of: [-5 to 5]
    int count = 100000; //100000 integers being generated
    
    int num_bins = right - left + 1; //num of bins, =11 this case
    int *histogram = new int[num_bins];  //histogram is an array
    for(int bin=0; bin < num_bins; bin++) histogram[bin] =0; //reset to 0 for all bins
    
    //1. Generate integers
    
    //2. Determine the histogram of generated numbers
    
    //3. Print the histogram (normalized) with format given above
    
    
}


/* Question 12:
 * 
 * Fill "sampleSChain" below to create a single linked list as follows:
 
 return head: 
 head->(data:10; next:->)(data:20; next:->)(data:30; next:->)(data:40; next:NULL)
 */

SNode* sampleSChain(){
    /*create: head->(data:10; next:->)(data:20; next:->)(data:30; next:->)(data:40; next:NULL)
     * and return head.
     * NOTE: last node has next =0 (NULL)
     */
    
    return 0; //replace this line when complete
}

/* Question 13:
 * 
 * Fill "deleteSChain" below to delete a single-linked list pointed by head
 */
void deleteSChain(SNode* head){
    
}

/* Question 14:
 * 
 * Fill "printSChain" below to print the single-linked list in the format as example below:
 
 [EXAMPLE:BEGIN]
 head->(data:10; next:->)(data:20; next:->)(data:30; next:->)(data:40; next:NULL)
 [EXAMPLE:END]
 */
void printSChain(SNode* head){
    
}

/* Question 15:
 * 
 * Fill "printSChain" below to print the single-linked list in the format as exmaple below:
 
 [EXAMPLE:BEGIN]
 head->(data:10; next:->)(data:20; next:->)(data:30; next:->)(data:40; next:NULL)
 will return: 10+20+30+40 = 100
 [EXAMPLE:END]
 */
int sumSChain(SNode* head){
    return 0; //replace this line when complete
}


/* Question 16:
 * 
 * Fill "insertHead" below to insert "data" as the head of the single-linked list pointed by "head"
 * return pointer to new node 
 */
SNode* insertHead(SNode* head, int data){
    return 0; //replace this line when complete
}

/* Question 17:
 * 
 * Fill "listDemo5" below to:
 * a/ use insertHead to create a single-linked list described as follows:
 head->(data:4; next:->)(data:6; next:->)(data:9; next:->)(data:10; next:NULL)
 * b/ print the list by printSChain
 * c/ delete the list by deleteSChain
 */
void listDemo5(){
    
}


///////////////////////////////////////////////////////////////////////////
//////////////////////SECTION 3: STACK & QUEUE        /////////////////////
///////////////////////////////////////////////////////////////////////////
//File attached: stacknqueue/IDeck.h (full code)
///////////////////////////////////////////////////////////////////////////
#include "stacknqueue/IDeck.h"



/* Question 18:
 * IntStack is a stack of type integer.
 * It uses XArrayList to implement its operations.
 * 
 * a/ Write code to implement stack's operations
 * b/ Determine the computation complexity for for each operation and write it to O(?)
 */


class IntStack: public IDeck<int>{
protected:
    XArrayList<int> list;
    
public:
    /*Complexity: O(?)
     */
    void push(int item){
        //YOUR CODE HERE
    }
    /*Complexity: O(?)
     */
    int pop(){
        return -1; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    int peek(){
        return -1; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    bool empty(){
        return true; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    int size(){
        return 0; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    void clear(){
        //YOUR CODE HERE
    }
    /*Complexity: O(?)
     */
    bool remove(int item){
        return false; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    bool contains(int item){
        return false; //replace this line with your code
    }
};





/* Question 19:
 * IntQueue is a queue of type integer.
 * It uses XArrayList to implement its operations.
 * 
 * a/ Write code to implement stack's operations
 * b/ Determine the computation complexity for for each operation and write it to O(?)
 */


class IntQueue: public IDeck<int>{
protected:
    XArrayList<int> list;
    
public:
    /*Complexity: O(?)
     */
    void push(int item){
        //YOUR CODE HERE
    }
    /*Complexity: O(?)
     */
    int pop(){
        return -1; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    int peek(){
        return -1; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    bool empty(){
        return true; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    int size(){
        return 0; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    void clear(){
        //YOUR CODE HERE
    }
    /*Complexity: O(?)
     */
    bool remove(int item){
        return false; //replace this line with your code
    }
    /*Complexity: O(?)
     */
    bool contains(int item){
        return false; //replace this line with your code
    }
};




/* Question 20:
 * fill printSChainBWD to print single-linked list (pointed by head) in backward order
 * MUST use IntStack or IntQueue
 */

void printSChainBWD(SNode* head){
    
}

/* Question 21:
 * fill printSChainFWD to print single-linked list (pointed by head) in forward order
 * MUST use IntStack or IntQueue
 */

void printSChainFWD(SNode* head){
   
}



/* Question 22:
 * fill listDemo6 to:
 * a/ use insertHead to create a single-linked list described as follows:
 head->(data:4; next:->)(data:6; next:->)(data:9; next:->)(data:10; next:NULL)
 * b/ print the list by printSChainFWD
 * c/ print the list by printSChainBWD
 * d/ delete the list by deleteSChain
 */
void listDemo6(){
   
}


///////////////////////////////////////////////////////////////////////////
//////////////////////SECTION 4: TREE                 /////////////////////
///////////////////////////////////////////////////////////////////////////

struct TNode{
    int key;
    int* value;
    TNode *left, *right;
    
    TNode(int key=0, int* value=0, TNode* left=0, TNode* right=0){
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};


/*
 * Question 22:
 * Fill code in sampleTree to create a tree below and return its root
 *
                            40
                        -----------
                       /           \
                      30            60
                   -------         ----- 
                  /       \       /     \
                20        35     55      80
                                /
                               50
  
*/
TNode* sampleTree(){
    return 0; //replace this line when complete
}

/*
 * Question 23: delete the tree given it's root
 */
void deleteTree(TNode* root){
    
}

/*
 * Question 24:
 * Fill code in sampleTree to create a tree below and return its root
 */
void getLeaves(TNode* root, XArrayList<int>& list){
    
}

/* Question 25:
 * fill treeDemo1 to:
 * a/ create a sample tree, using sampleTree
 * b/ get a list of leaves and print them, using getLeaves
 * c/ delete the tree created in a/
 */
void treeDemo1(){
    
}
#endif /* C20193_STUDENTCODE_H */

