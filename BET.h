
#ifndef BET_H
#define BET_H
#include <iostream>
#include <string>

struct BinaryNode{
  std::string token;
  BinaryNode *left;
  BinaryNode *right;
  
  BinaryNode(const string& theToken = string{}, BinaryNode *lt = nullptr, BinaryNode* rt = nullptr)
    : token{theToken}, left{lt}, right{rt} {}
  
  BinaryNode(string && theToken, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
    : token{move(theToken)}, left{lt}, right{rt} {}
};


class BET{
  public:
    BET();  //default zero-parameter constructor
    BET(const string postfix); 
    //"postfix" is string containing a postfix expression
    //tree is built based off of postfix
    BET(const BET&);  //copy constructor
    ~BET(); //destructor
    
    bool buildFromPostfix(const string postfix);  
    //if tree contains nodes before the function is called, then delete existing nodes first
    //return true if the new tree is successful
    //false if error
    
    const BET& operator=(const BET &);  //assignment operator
    size_t size();  //call private size func to return the number of nodes in the tree
    size_t leaf_nodes();  //call private leaf_nodes func to return number of leaf nodes in tree
    bool empty(); //return true if tree empty, else return false
    
    void printInfixExpression(); //call private version of printInfixExpression to print out the infix expression
    void printPostfixExpression();  //call private version to print postfix expression
    
   private:
    //must be implemented recursively
    void printInfixExpression(BinaryNode *n); 
    //print std output corresponding infix expression
    //may need to add parens depending on precedence of operators
    //NO UNNECESSARY PARENS
    
    void makeEmpty(BinaryNode* &t); //delete all nodes in subtree pointed to by t
    //called by destructor
    
    BinaryNode * clone(BinaryNode *t)const;  //clone all nodes in subtree pointed to by t
    //called by assignment operator=
    
    void printPostfixExpression(BinaryNode *n); //print to the std output, corresponding postfix expression
    size_t size(BinaryNode *t); //return num of nodes in subtree pointed to by t
    size_t leaf_nodes(BinaryNode *t); //return num of leaf nodes in subtree pointed to by t
};
