struct dq{
    dq *prev;
    int val;
    dq *next;
};
class MyCircularDeque {
private:
int count;
int n;
dq *front;
dq* rear;
public:
    MyCircularDeque(int k) {
        // we can imimplement this using the doubly linked list so the time 
        //complexity will be O(1) for every call
        count=0;
        n=k;
        front=NULL;
        rear=NULL;
    }
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        dq *new_node = new dq;
        new_node->val=value;
        if(front==NULL&&rear==NULL){
            front=new_node;
            rear=new_node;
        }
        else{
            new_node->next=front;
            front->prev=new_node;
            front=new_node;
        }
        count+=1;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        dq *new_node = new dq;
        new_node->val=value;
        if(front==NULL&&rear==NULL){
            front=new_node;
            rear=new_node;
        }
        else{
            rear->next=new_node;
            new_node->prev=rear;
            rear=new_node;
        }
        count+=1;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=NULL;
            rear=NULL;
            count=0;
            return true;
        }
        dq * node = front;
        front=front->next;
        node=NULL;
        delete node;
        count-=1;
        return true;
    }
    
    bool deleteLast() {
         if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=NULL;
            rear=NULL;
            count=0;
            return true;
        }
        dq * node = rear;
        rear=rear->prev;
        node=NULL;
        delete node;
        count-=1;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return front->val;
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return rear->val;
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */