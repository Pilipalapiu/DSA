#if !defined _BINTREE_H_
#define _BINTREE_H_

/*二叉树结构声明*/
typedef struct BinNode
{
    
    int data;
    struct BinNode *lc;
    struct BinNode *rc;

}BinNode,*BinTree;

#endif // _BINTREE_H_
