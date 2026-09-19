class Node{
    public:
    int val;
    Node* next;

    Node(int value):val(value),next(nullptr){}
};
class LinkedList {
    Node* head;
public:
    LinkedList() {
        head=nullptr;
    }
    ~LinkedList() {  
        Node* temp=head;
        while(temp!=NULL){
            Node* nextnode=temp->next;
            delete temp;
            temp=nextnode;
        }
        head=nullptr;
      }

    int get(int index) {
        Node* temp=head;
        int count=0;

        while(temp!=NULL){
            if(count==index){
                return temp->val;
            }
            temp=temp->next;
            count++;            
        }
      return -1;  
    }

    void insertHead(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
    
    void insertTail(int val) {
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    bool remove(int index) {
        if(head==NULL || index <0)
        return false;

        Node* temp=head;
       
        if(index==0){
            head=head->next;
            delete temp;
            return true;
        }
        int count=0;
        while(temp!=NULL && count<index-1){
            temp=temp->next;
            count++;
        }
        if(temp == nullptr || temp->next == nullptr)
        return false;

        Node* nodetodelte=temp->next;
        temp->next=temp->next->next;
        delete nodetodelte;
        return true;
    }

    vector<int> getValues() {
        vector<int>result;
        Node* temp=head;

        while(temp!=nullptr){
            result.push_back(temp->val);
            temp=temp->next;
        }
        return result;
    }
};
