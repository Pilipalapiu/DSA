#ifndef _LIST_H_
#define _LIST_H_

typedef struct ListNode
{
    int data;
    struct ListNode* succ;//successor
    struct ListNode* pred;//predecessor
}*List,ListNode;

#endif // _LIST_H_