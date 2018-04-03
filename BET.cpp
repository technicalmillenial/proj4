#include "bet.h"
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

bool BET::buildFromPostfix(const string postfix)
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
const BET::BET& operator=(const BET &b)
{
  root = clone(b.root);
  return *this;
}  //assignment operator

size_t BET::size()
{      return size(root);    }  //call private size func to return the number of nodes in the tree
    
size_t BET::leaf_nodes()
{ return leaf_nodes(root); }  //call private leaf_nodes func to return number of leaf nodes in tree

bool BET::empty()
{return size() == 0;} //return true if tree empty, else return false
    
void BET::printInfixExpression()
{   printInfixExpression(root);
    cout<<endl;
} //call private version of printInfixExpression to print out the infix expression

void BET::printPostfixExpression()
{   printPostfixExpression(root);
    cout<<endl;
}  //call private version to print postfix expression

void BET::printInfixExpression(BinaryNode *n)
{ if(n->left == nullptr )
    {cout<<n->token;}
  else
  {
    if(n!= this->root)
      {cout<<"(";}
    printInfixExpression(n->left);
    cout<<' '<<n->token<<' ';
    printInfixExpression(n->right);
    if(n!= this->root)
      {cout<<")";}
  }
} 
    //print std output corresponding infix expression
    //may need to add parens depending on precedence of operators
    //NO UNNECESSARY PARENS
    
void BET::makeEmpty(BinaryNode* &t)
{     if(t != nullptr)
        {   makeEmpty(t->left);
          makeEmpty(t->right);
          delete t;
        }
      t=nullptr;
    } //delete all nodes in subtree pointed to by t
    //called by destructor
    
BinaryNode* BET::clone(BinaryNode *t)const
    {   if(t==nullptr)
          {return nullptr;}
         else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
    }  //clone all nodes in subtree pointed to by t
    //called by assignment operator=
    
void BET::printPostfixExpression(BinaryNode *n)
    {   if(n!=nullptr)
        {          printPostfixExpression(n->left);
                   printPostfixExpression(n->right);
                   cout<< n->token <<' ';
        }
     
    } //print to the std output, corresponding postfix expression
size_t size(BinaryNode *t)
    { if(t==nullptr){return 0;}
      else{return 1 + size(t->left) + size(t->right);}
    } //return num of nodes in subtree pointed to by t
size_t leaf_nodes(BinaryNode *t)
    {   if( (t != nullptr) && ((t->left == nullptr) && (t->right == nullptr)) )
          {return 1;}
        else return leaf_nodes(t->left + leaf_nodes(t->right));
    }
