#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class LinkedList {                   // in LeetCode, submission, this class is not neccessary
                                    // this class allows me to call addNode in main to add node to initial data set. 
     // Definition for singly-linked list.
    public:
    ListNode *headL3;
    ListNode *tailL3;

    LinkedList (){
        headL3 = NULL;
        tailL3 = NULL;
    }
    void addNode(int sum){
        ListNode *newNode = new ListNode(sum, NULL);  // head node is given a value 

        if(headL3 == NULL)           // init case
        {
            headL3 = newNode;        // make both head and tail of linked list from the new node   
            tailL3 = newNode;
        }
        else                          // other cases  
        {
            tailL3->next = newNode;   // add the new node to after tailL3
            tailL3 = tailL3->next;    // move tail to back (same as tailL3 = newNode )
        }
    }
    friend class Solution;
};

class Solution : public LinkedList {
public:  
    LinkedList list;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode *headL3;                // declaring here cause sigfault
        // ListNode *tailL3;
        int sum=0;
        while(l1!=NULL || l2!=NULL )
        {   
            
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l1->val;
                l2=l2->next;
            }
            
            if (sum< 10) {           
                list.addNode(sum);           // add a new node with val = sum
                sum =0;
            }
            else {
                list.addNode(sum%10);        // add a new node with val = remainder of sum/10
                sum = sum/10;           // keep the carrier = sum/10
            }
        }   
        
        if (l1== NULL && l2== NULL && sum>0){
            list.addNode(sum);               // add carrier even if extend beyond the size of l1, l2
        }
        return list.headL3;
    }
};

int main(){
    Solution sol;
    ListNode *l1;
    LinkedList myLinkList;
    myLinkList.addNode(9);
    myLinkList.addNode(9);
    myLinkList.addNode(9);
    l1 = myLinkList.headL3;
    ListNode *l2;
    myLinkList.addNode(9);
    myLinkList.addNode(9);
    l1 = myLinkList.headL3;
    sol.addTwoNumbers(l1, l2);
}