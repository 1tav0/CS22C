#include <iostream>
using namespace std;

int main(){
int ticket = 0;
int age[5];
std::cout << "enter the five ages\n" <<endl;
int totalPrice;
std::cin>>age;
for(int i=0; i<5; i++){
    if(age[i]>3){
        totalPrice = ticket + 100;
    }
}
std::cout << "the total is " << totalPrice <<endl;
}

class MyLinkedList {
public:
    MyLinkedList* head;
    MyLinkedList* prev;
    MyLinkedList* next;    
    int val;
    int i;
    MyLinkedList();
    MyLinkedList(int _val){
        head = NULL;
        prev = NULL;
        next = NULL;
        i = -1;
        val = _val;
    }
        
    
    int get(int index) {
        MyLinkedList* it = new MyLinkedList();
        it = head;
        int value = head->val;
        int ind = head->i;
        if(head==NULL){
            return -1;
        }
        while(it->next){
            if(ind == index)
                return val;
        }
    }
    
    void addAtHead(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        
        if(head==NULL){
            head = node;
            node->prev = NULL;
            node->next = NULL;
        }else{
            head = node;
            head->prev = node->next;
            node->next = head->prev;
            node->prev = NULL;
            node->i++;

        }   
    }
    
    void addAtTail(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        MyLinkedList* it;
        it = head;
        while(it->next){
            it->i++;
            it->next = node->prev;
            node->prev = it;
            it = node;       
            }
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList* node = new MyLinkedList(val);
        MyLinkedList* it = new MyLinkedList(val);
        if(head == NULL){
            cout<< "LL size is less than index"<< endl;
        }
        it = head;
        while(it->next){
            if(it->i == index){
                it->i++;
                it->next->prev = node->next;
                node->next = it->next->prev;
                it->next = node->prev;
                node->prev = it;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        MyLinkedList* it = new MyLinkedList();
        MyLinkedList* temp = new MyLinkedList();
        if(head == NULL){
            cout<< "LL size is less than index"<< endl;
        }
        it = head;
        while(it->next){
            if(it->i == index){
                it->next->prev = it->prev;
                it->prev = it=>next->prev;
                delete(it);
                it->i--;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
