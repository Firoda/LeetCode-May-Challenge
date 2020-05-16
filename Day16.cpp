/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL)    return NULL;
        ListNode* oddhead = new ListNode();
        ListNode* oddTra = oddhead;
        
        ListNode* evehead = new ListNode();
        ListNode* eveTra = evehead;
        
        bool flag = true;
        while(head!=NULL)
        {
            if(flag)
            {
                oddTra->next = head;
                flag = !flag;
                oddTra = oddTra->next;
            }
            else
            {
                eveTra->next = head;
                flag = !flag;
                eveTra = eveTra->next;
            }
            
            head = head->next;
        }
        
        eveTra->next = NULL;
        oddTra->next = evehead->next;
        
        
        return oddhead->next;
    }
};
