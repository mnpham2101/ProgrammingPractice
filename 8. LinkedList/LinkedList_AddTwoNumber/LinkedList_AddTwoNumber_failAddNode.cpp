#include <cmath>
using namespace std;


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode;
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
                l3 -> val = sum;       
                sum =0;
                ListNode *tmp = new ListNode(0, NULL);
                tmp-> next = l3;       //tmp is the new head
                l3 = tmp;              //add node to head ==> fail => the result will be in reverse order.
                
            }
            else {
                l3 -> val = sum % 10;
                sum = sum/10;
                ListNode *tmp = new ListNode(0, NULL);
                tmp-> next = l3;
                l3 = tmp;                   // add node to head ==> fail => the result will be in reverse order.
            }
        }        
        return l3;
    }
};

int main() {
    Solution sol;
    ListNode *l1, *l2, *l3;
    l3 = sol.addTwoNumbers(l1, l2);

}