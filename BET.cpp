#include "BET.h"
#include <iostream>
#include <stack>

using namespace std;

BET::BET():root{nullptr}{}

BET::BET(const string postfix)
{
  buildFromPostfix(postfix);
}

BET::BET(const BET& b) : root{nullptr}
{
 root = clone(b.root);
}

BET::~BET()
{
 makeEmpty();
}

bool buildFromPostfix(const string postfix)
{
 stack<BinaryNode*> theStack;
  
 if(!theStack.empty()){
  makeEmpty();
 }
  else
  {
    for(int i=0; i<postfix.length(); i++)
    { //if isoperand then create a one-node tree and push a pointer to it onto a stack
      if(isalnum(postfix[i]))
      {
        theStack.push(postfix[i]).
      }
      //if isoperator then pop pointers to the left and right nodes from the stack and then a pointer is then pushed onto the stack
      else if((postfix[i] == '+')||(postfix[i] == '-')||(postfix[i] == '*')||(postfix[i] == '/'))
      {
        BinaryNode* Rnode = theStack.top();
        theStack.pop()
        BinaryNode* Lnode = theStack.top();
        theStack.pop();
        BinaryNode* ptr = new BinaryNode(postfix[i], Lnode, Rnode);
        theStack.push(ptr);
      }
    }
    if(theStack.empty()){
      cout<<"Error. New tree unsuccessful.\n";
      return false;
    }
    else
      cout<<"Success! New tree built!\n";
      return true;
  }
}
