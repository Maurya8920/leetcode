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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
dummy->next = head;

ListNode* prev = dummy;
ListNode* curr = nullptr;
ListNode* next = nullptr;
for(int i= 1 ; i<left ; i++){
    prev= prev->next;
}
int count =right-left+1;
 curr=prev->next;
 ListNode*tail=curr;
 ListNode*before=prev;
   while(count--){
    next=curr->next;
    curr->next=prev;
   
    prev=curr;
    curr=next;
   }

tail->next=curr;
before->next=prev;
    
      return dummy->next;
        
    }
};