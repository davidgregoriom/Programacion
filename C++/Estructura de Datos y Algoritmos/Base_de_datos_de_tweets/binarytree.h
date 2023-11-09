#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <memory>
#include "hashtags.h"
#include "elementoarbolbinario.h"
#include <functional>

class BinaryTree
{
protected:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;



    public:
        BinaryTree();
        BinaryTree( hashtags& datos);

        void add_left(BinaryTree& tree) { root->left = tree.root; }
        void add_right(BinaryTree& tree) { root->right = tree.root; }

        int height() const;
        int size() const;

        const hashtags& min() const;
        const hashtags& max() const;

        void dfs_inorder(std::function<void (const hashtags&)> action) const;

        bool find(const hashtags&) const;
        void push(const hashtags&);

};

#endif // BINARYTREE_H
