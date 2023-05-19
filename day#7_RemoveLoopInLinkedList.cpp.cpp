/*
structure of linked list node:
struct Node
{
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    
    void removeLoop(Node* head)
    {
        // Just remove the loop without losing any nodes
        
        if (head == NULL || head->next == NULL)
            return;
            
        if (head->next == head){
            head->next = NULL;
            return;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        map<Node*, bool> visited;
        
        while (curr!=NULL){
            if (visited[curr] == true){
                prev->next = NULL;
                return;
            }
            
            visited[curr] = true;
            prev = curr;
            curr = curr->next;
        }
        
        return;
    }
};
