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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int res=cnt-n;
        if(cnt==n){
            ListNode* temp1=head;
            head=head->next;
            delete temp1;
            return head;
        }
        ListNode* temp2=head;
        while(temp2!=NULL){
            res--;
            if(res==0){
                ListNode* temp3=temp2->next;
                temp2->next=temp3->next;
                delete temp3;
                return head;
            }
            temp2=temp2->next;
        }
        return head;
    }
};