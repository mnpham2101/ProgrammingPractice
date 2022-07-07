 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:  
    ListNode *headL3;
    ListNode *tailL3;
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
                sum+=l2->val;
                l2=l2->next;
            }
            
            if (sum< 10) {           
                addNode(sum);           // add a new node with val = sum
                sum =0;
            }
            else {
                addNode(sum%10);        // add a new node with val = remainder of sum/10
                sum = sum/10;           // keep the carrier = sum/10
            }
        }   
        
        if (l1== NULL && l2== NULL && sum>0){
            addNode(sum);               // add carrier even if extend beyond the size of l1, l2
        }
        return headL3;
    }
};