class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dhead = new ListNode(0); 
        dhead->next = l1; 
        ListNode* pprev = dhead; 
        ListNode *p1 = l1, *p2 = l2; 
        int newval =0; 
        int carry =0; 
        while(p1!=nullptr && p2!=nullptr)
        {            
            newval = (p1->val + p2->val + carry)%10; 
            carry = (p1->val + p2->val + carry)/10; 
            p1->val = newval; 
            p1 = p1->next; 
            p2 = p2->next;
            pprev = pprev->next; 
        }
        if (p1!=nullptr) // and p2 ==nullptr 
        {            
            while(p1!=nullptr)
            {
                newval = (p1->val + carry)%10; 
                carry = (p1->val + carry)/10; 
                p1->val = newval; 
                p1 = p1->next; 
                pprev = pprev->next; 
            }
        }
        if (p2!=nullptr)
        {    
            pprev->next = p2; 
            p1 = p2; 
            while(p1!=nullptr)
            {
                newval = (p1->val + carry)%10; 
                carry = (p1->val + carry)/10; 
                p1->val = newval; 
                p1 = p1->next; 
                pprev = pprev->next; 
            }
        }
        if (carry ==1)
        {
            ListNode* p = new ListNode(1);
            pprev->next = p; 
        }
        
        return dhead->next; 
            
    }
};
Nguyen is typing
Nguyen
