#ifndef TWEETS_H
#define TWEETS_H
#include <iostream>
#include <memory>
#include "binarytree.h"


using namespace std;
class Filter
{
public:
 Filter();
 void filter_db(const BinaryTree& all,BinaryTree& hastags,BinaryTree& tweets);

private:
    const BinaryTree& all;
    BinaryTree& hastags;
    BinaryTree& tweets;
};

#endif // TWEETS_H
