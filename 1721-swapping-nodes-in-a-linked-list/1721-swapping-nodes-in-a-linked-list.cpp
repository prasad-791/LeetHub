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
    ListNode* swapNodes(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* p = head, * q = NULL;
        int x = 0;
        while(p!=NULL){
            st.push(p);
            x++;
            if(x==k){
                q = p;
            }
            p = p->next;
        }
        
        while(!st.empty() && k){
            p = st.top();
            st.pop();
            k--;
        }
        
        x = p->val;
        p->val = q->val;
        q->val = x;
        return head;
    }
};