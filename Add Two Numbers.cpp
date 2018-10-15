/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *result = NULL;
	ListNode *ptr = NULL;
	ListNode *temp = NULL;
	int carry = 0;
	 if(!l1 && !l2)
	 	return NULL;
	 else
	 {
	 	while(l1 || l2)
	 	{
	 		temp = (ListNode*)malloc(sizeof(ListNode));
	 		if(l1 && l2)
	 		{
		 		temp->val = (l1->val + l2->val + carry) % 10;
		 		temp->next = NULL;
		 		carry = (l1->val + l2->val + carry) / 10;
		 		l1 = l1->next;
		 		l2 = l2->next;
	 		}
	 		else if(!l1)
	 		{
	 			temp->val = (l2->val + carry) % 10;
	 			temp->next = NULL;
	 			carry = (l2->val + carry) / 10;
	 			l2 = l2->next;
	 		}
	 		else if(!l2)
	 		{
	 			temp->val = (l1->val + carry) % 10;
	 			temp->next = NULL;
	 			carry = (l1->val + carry) / 10;
	 			l1 = l1->next;
	 		}
	 		if(!result)
	 		{
	 			result = temp;
	 			ptr = temp;
	 		}
	 		else
	 		{
	 			ptr->next = temp;
	 			ptr = temp;
	 		}
	 	}
	 	if(carry)
	 	{
	 		temp = (ListNode*)malloc(sizeof(ListNode));
	 		temp->val = carry;
	 		temp->next = NULL;
	 		ptr->next = temp;
	 		ptr = temp;
	 	}
	 }
	 return result;
    }
};
