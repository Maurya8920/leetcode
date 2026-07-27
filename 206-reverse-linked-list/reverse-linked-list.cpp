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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        stack<ListNode*> st;
    ListNode*temp=head;
    while( temp!=NULL){
        st.push(temp);
        temp=temp->next;
    }
    ListNode*ans= NULL;
    ListNode*tail=NULL;
    while(!st.empty()){
         if(ans==NULL){
            ans=st.top();
            tail=st.top();

         }else{
            tail->next=st.top();
            tail=st.top();
            tail->next=NULL;
         }

        st.pop();
    }


return ans;
        
    }
};