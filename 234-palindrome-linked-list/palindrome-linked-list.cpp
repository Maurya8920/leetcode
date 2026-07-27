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
ListNode*middle(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


    bool isPalindrome(ListNode* head) {
        ListNode*middlenode=middle(head);
        ListNode*curr=middlenode->next;
         ListNode*next=NULL; 
         ListNode*prev=NULL; 
         while(curr!=NULL){
         next=curr->next;
          curr->next=prev;
           prev=curr;
            curr=next;
         }
         while(prev!=NULL && head!=NULL){
        if(prev->val!=head->val){
            return false;
        }
        prev=prev->next;
        head=head->next;
         }
        return true;
    }
};