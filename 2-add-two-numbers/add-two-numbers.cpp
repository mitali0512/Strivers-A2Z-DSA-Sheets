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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head=NULL;
            ListNode* temp1=l1->next;
            ListNode*temp2=l2->next;
            int sum1=l1->val+l2->val;
            head=new ListNode(sum1%10,nullptr);
            ListNode* temp3=head;
            int carry=sum1/10;
            while(temp1!=NULL && temp2!=NULL){
                int sum=carry;
                sum=sum+temp1->val+temp2->val;
                ListNode* newnode=new ListNode(sum%10,nullptr);
                carry=sum/10;
                temp3->next=newnode;
                temp3=newnode;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            while(temp1!=NULL){
                 ListNode* newnode=new ListNode((temp1->val+carry)%10,nullptr);
                 carry=(temp1->val+carry)/10;
                 temp3->next=newnode;
                temp3=newnode;
                temp1=temp1->next;
            }
            while(temp2!=NULL){
                 ListNode* newnode=new ListNode((temp2->val+carry)%10,nullptr);
                carry=(temp2->val+carry)/10;
                 temp3->next=newnode;
                temp3=newnode;
                temp2=temp2->next;
            }
            if(carry!=0){
                ListNode* newnode=new ListNode(carry,nullptr);
                 temp3->next=newnode;
                temp3=newnode;
            }
            return head;
    }
};