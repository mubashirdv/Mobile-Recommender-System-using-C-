#include <iostream>
#include "AVL Tree.h"
using namespace std;
template<class x>
class linkedNode{
	public:
	AVL_Tree<x> tree;
	string title;
	linkedNode* next;
	linkedNode(){
		title = "";
		next = NULL;}
	linkedNode(string t,AVL_Tree<x> tree){
		title = t;
		this->tree = tree;
		next = NULL;
	}
};
template <class y>
class linkedList{
	linkedNode<y>* head , *tail;
	public:
		linkedList(){
			head = NULL;
			tail = NULL;
		}
		void pushBack(string title,AVL_Tree<y> t){
			linkedNode<y>* temp = new linkedNode<y>(title,t);
			if(head == NULL){
				head = tail = temp;
				return;
			}
			tail->next = temp;
			tail = tail->next;
		}
		linkedNode<y>* currentTitleNode(string title){
			linkedNode<y>* temp = head;
			while(temp->title != title)
				temp = temp->next;
			cout << temp->title << endl;
			return temp;
		}
		void print(){
			linkedNode<y>* temp = head;
			while(temp!=NULL){
				cout <<  temp->tree.getTreeRoot()->right->mobiles->name <<endl;
				temp = temp->next;
			}
			cout << endl;
//			cout << head->tree.getTreeRoot()->mobiles->name <<endl;
		}
};
