#include "BET.h"
#include <iostream>
#include <stream>

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
 
}
