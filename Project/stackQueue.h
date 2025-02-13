#include <iostream>
using namespace std;
template <class x>
class stackQueueNode{
	public:
	
	x data; //data here is mobile
	stackQueueNode* next,*prev;
	stackQueueNode(x data){
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};
template <class x>
class stackQueue{
	stackQueueNode<x> * head ,*tail;
	int size;
	public:
		stackQueue(){
			size = 0;
			head = NULL;
			tail = NULL;
		}
		bool isEmpty(){
			if(head == NULL)
				return true;
			return false;
		}
		void push(x val){
			stackQueueNode<x> * newNode = new stackQueueNode<x>(val);
			size++;
			if(head == NULL){
				head = newNode;
				tail = head;
				return ;
			}
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
			
		}
		void intersection(stackQueue<x> s1){
			x arr[(this->size > s1.size)?this->size : size];
			int k = 0;
			stackQueueNode<x>* temp1 = this->head;
			stackQueueNode<x>* temp2 = s1.head;
			while(temp1 != NULL){
				while(temp2 != NULL){
//					cout << temp1->data->name << " : "<<temp2->data->name << endl;
					if(temp1->data->id == temp2->data->id)
					{
						arr[k++] = temp1->data;
					}
					temp2 = temp2->next;
				}
				temp2 = s1.head;
				temp1 = temp1->next;
			}
			while(!isEmpty()){
				pop();
			}
			while(!s1.isEmpty())
				s1.pop();
			for(int i = 0 ; i<k ; i++){
				this->push(arr[i]);
			}
		}
		x top(){
			if(isEmpty()){
				return 0;
			}
			return tail->data;
		}
		void pop(){
			if(isEmpty()){
//				cout << "The list is empty !"<<endl;
				return;
			}
			size--;
			if(head == tail){
				stackQueueNode<x> *del = head;
				head = NULL;
				tail = NULL;
				delete del;
				return;
			}
			stackQueueNode<x>* del = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete del;
		}
		x dequeue(){
			if(isEmpty()){
				return NULL;
			}
			stackQueueNode<x> *temp = head;
			head = head->next;
			return temp->data;
		}
		int getSize(){return size;}
};

