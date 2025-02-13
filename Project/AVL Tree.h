#include <iostream>
#include "stackQueue.h"

using namespace std;
string trim(string s){
	string temp = "";
	for(int i=0;i<s.length();i++){
		if(s[i]!=' ')
			temp += s[i];
	}
	return temp;
}
bool isDigits(string s){
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i]>='0' && s[i] <='9' || s[i] =='.')
			continue;
		else
			return false;
	}
	return true;
}
float stringToFloat(string s){
	bool decimalPoint = false;
	float number = 0;
	int div = 10;
	for(int i=0;i<s.length();i++){
		if(s[i] == '.'){
			decimalPoint = true;
			continue;
		}
		if(!decimalPoint){
			number = number * 10 + (s[i]-48);
		}
		else{
			number = number + (float)(s[i]-48)/(float)div;
			div *= 10;
		}
	}
	return number;
}
void color(int color)	//to make changing colours easier
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void gotoxy(int x, int y)	//for formatting text
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
string toLowerCase(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]>='A' && s[i]<='Z'){
			s[i] = s[i] + 32;
		}
	}
	return s;
}
template <class x>
class Node{
	public:
	x mobiles;
	Node* left , * right ;
	int height ;
	Node(){}
	Node(x val){
		mobiles = val;
		left = NULL;
		right = NULL;
		height = 1;
	}
};
template <class x>
int getHeight(Node<x>* n){
	if(n == NULL)
		return 0;
	return n->height ;
}
template <class x>
class AVL_Tree{
	Node<x> * root;
	
	int Max(int a,int b){
		return a > b ? a : b;
	}
	Node<x>* minNode(Node<x>* root){
		if(root == NULL)
			return root;
		if(root->left == NULL)
			return root;
	}
	int balanceFactor(Node<x>* root){
		if(root == NULL)
			return -1;
		return getHeight(root->left) - getHeight(root->right);
	}
	Node<x>* leftRotation(Node<x>* n){
		Node<x>* X = n->right;
		Node<x>* T2 = X->left;
		
		X->left = n;
		n->right = T2;
		//updating height
		n->height = Max(getHeight(n->left),getHeight(n->right)) + 1;
		X->height = Max(getHeight(X->left),getHeight(X->right)) + 1;
		return X;
	}
	Node<x>* rightRotation(Node<x>* n){
		Node<x>* y = n->left;
		Node<x>* T2 = y->right;
		
		y->right = n;
		n->left = T2;
		//updating height
		n->height = Max(getHeight(n->left),getHeight(n->right)) + 1;
		y->height = Max(getHeight(y->left),getHeight(y->right)) + 1;
		return y;
	}
	Node<x>* addNode(Node<x>* root,x key,string title){

		if(root == NULL)
		{
			return new Node<x>(key);
		}
		if(title == "name"){//1
			if(toLowerCase(key->name) > toLowerCase(root->mobiles->name))
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "brand"){//2
			if(toLowerCase(key->brand) > toLowerCase(root->mobiles->brand))
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "batteryCapacity"){//3
			if(key->brand > root->mobiles->brand)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "screenSize"){//4
			if(key->screenSize > root->mobiles->screenSize)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "touchScreen"){//5
			if(key->touchScreen == "Yes")
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "processor"){//6
			if(key->processor > root->mobiles->processor)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "ram"){//7
			if(key->ram > root->mobiles->ram)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "storage"){//8
			if(key->storage > root->mobiles->storage)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "rearCamera"){//9
			if(key->rearCamera > root->mobiles->rearCamera)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "frontCamera"){//10
			if(key->frontCamera > root->mobiles->frontCamera)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "operatingSystem"){//11
			if(toLowerCase(key->operatingSystem) > toLowerCase(root->mobiles->operatingSystem))
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "numberOfSims"){//12
			if(key->numberOfSims > root->mobiles->numberOfSims)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else if(title == "price"){//13
			if(key->price > root->mobiles->price)
				root->right = addNode(root->right,key,title);
			else
				root->left = addNode(root->left,key,title);
		}
		else{
			cout << "invalid Filter " << endl;
			exit(1);
		}
		root->height = Max(getHeight(root->left),getHeight(root->right)) + 1;
		int balance = balanceFactor(root);
		if(root == NULL)
			return root;
		if (balance > 1 && 
        balanceFactor(root->left) >= 0) 
        return rightRotation(root); 
  
    // Left Right Case 
    if (balance > 1 && 
        balanceFactor(root->left) < 0) 
    { 
        root->left = leftRotation(root->left); 
        return rightRotation(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && 
        balanceFactor(root->right) <= 0) 
        return leftRotation(root); 
  
    // Right Left Case 
    if (balance < -1 && 
        balanceFactor(root->right) > 0) 
    { 
        root->right = rightRotation(root->right); 
        return leftRotation(root); 
    } 
		return root;
	}
	Node<x>* deleteNode(x key);
	void printInorderNames(Node<x>* root){
		if(root == NULL)
			return;
		printInorderNames(root->left);
		cout << root->mobiles->name << endl;
		printInorderNames(root->right);
	}
	void searchByName(Node<x>* root,stackQueue<x> &s , char character){
		if(root == NULL)
			return;
			if(character <= toLowerCase(root->mobiles->name)[0])
				searchByName(root->left,s,character);
			if(toLowerCase(root->mobiles->name)[0] == character)
				s.push(root->mobiles);
			searchByName(root->right,s,character);	
	}
	void searchByBrand(Node<x>* root,stackQueue<x> &s , string brand){
		if(root == NULL)
			return;
			if(brand <= toLowerCase(root->mobiles->brand))
				searchByBrand(root->left,s,brand);
			if(toLowerCase(root->mobiles->brand) == brand)
				s.push(root->mobiles);
			searchByBrand(root->right,s,brand);	
	}
	void searchByBatteryCapacity(Node<x>* root,stackQueue<x> &s , float ub,float lb){
		if(root == NULL)
				return;
			if(lb < root->mobiles->batteryCapacity)
				searchByBatteryCapacity(root->left,s,ub,lb);
			if(root->mobiles->batteryCapacity >= lb && root->mobiles->batteryCapacity<=ub){
				s.push(root->mobiles);
			}
			searchByBatteryCapacity(root->right,s,ub,lb);
	}
	void searchByTouchScreen(Node<x>* root,stackQueue<x> &s ,string choice){
		if(root == NULL)
				return;
			if(toLowerCase(root->mobiles->touchScreen) == choice){
				s.push(root->mobiles);
			}
			searchByTouchScreen(root->left,s,choice);
			searchByTouchScreen(root->right,s,choice);
	}
	void searchByScreenSize(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->screenSize)
				searchByScreenSize(root->left,s,ub,lb);
			if(root->mobiles->screenSize >= lb && root->mobiles->screenSize<=ub){
				s.push(root->mobiles);
			}
			searchByScreenSize(root->right,s,ub,lb);
	}
	void searchByProcessor(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->processor)
				searchByProcessor(root->left,s,ub,lb);
			if(root->mobiles->processor >= lb && root->mobiles->processor<=ub){
				s.push(root->mobiles);
			}
			searchByProcessor(root->right,s,ub,lb);
	}
	void searchByRam(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->ram)
				searchByRam(root->left,s,ub,lb);
			if(root->mobiles->ram >= lb && root->mobiles->ram<=ub){
				s.push(root->mobiles);
			}
			searchByRam(root->right,s,ub,lb);
	}
	void searchByStorage(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->storage)
				searchByStorage(root->left,s,ub,lb);
			if(root->mobiles->storage >= lb && root->mobiles->storage<=ub){
				s.push(root->mobiles);
			}
			searchByStorage(root->right,s,ub,lb);
	}
	void searchByRearCamera(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->rearCamera)
				searchByRearCamera(root->left,s,ub,lb);
			if(root->mobiles->rearCamera >= lb && root->mobiles->rearCamera<=ub){
				s.push(root->mobiles);
			}
			searchByRearCamera(root->right,s,ub,lb);
	}
	void searchByFrontCamera(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->frontCamera)
				searchByFrontCamera(root->left,s,ub,lb);
			if(root->mobiles->frontCamera >= lb && root->mobiles->frontCamera<=ub){
				s.push(root->mobiles);
			}
			searchByFrontCamera(root->right,s,ub,lb);
	}
	void searchByOperatingSystem(Node<x>* root,stackQueue<x> &s , string os){
			if(root == NULL)
				return;
			if(os <= toLowerCase(root->mobiles->operatingSystem))
				searchByOperatingSystem(root->left,s,os);
			if(toLowerCase(root->mobiles->operatingSystem) == os){
				s.push(root->mobiles);
			}
			searchByOperatingSystem(root->right,s,os);
	}
	void searchByNumberOfSims(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->numberOfSims)
				searchByNumberOfSims(root->left,s,ub,lb);
			if(root->mobiles->numberOfSims >= lb && root->mobiles->numberOfSims<=ub){
				s.push(root->mobiles);
			}
			searchByNumberOfSims(root->right,s,ub,lb);
	}
	void searchByPrice(Node<x>* root,stackQueue<x> &s , float ub,float lb){
			if(root == NULL)
				return;
			if(lb < root->mobiles->price)
				searchByPrice(root->left,s,ub,lb);
			if(root->mobiles->price >= lb && root->mobiles->price<=ub){
				s.push(root->mobiles);
			}
			searchByPrice(root->right,s,ub,lb);
	}
	public:
		AVL_Tree(){
			root = NULL;
		}
		void insert(x mob,string title){
			root = addNode(root,mob,title);
		}
		void remove(x value){
	
			root = deleteNode(root,value);
		}
		void inorderNames(){
			printInorderNames(root);
		}
		Node<x>* getTreeRoot(){return root;}
		void search(string searchType,stackQueue<x> &mobStack){
			if(searchType== "name"){
				fflush(stdin);
				string input = "";
				char character;
				while(true){
				
				cout << "Enter first character of name: ";
				color(7);
				fflush(stdin);
				getline(cin,input);
//				cin >> character;
				if(input.length()>1 && (trim(toLowerCase(input)) >="a" && trim(toLowerCase(input)) <= "z")){
						
						gotoxy(45,20);
						color(4);
						cout << "Enter valid input ";
						color(7);
						gotoxy(45,19);
						cout << "                                                        ";
						gotoxy(45,19);
						continue;
					}
					break;
				}
				character = input[0];
				color(11);
				PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
				if(character<97)
					character+=32;
				if(searchType == "name")
				searchByName(root,mobStack,character);
			return;
			}
			else if(searchType == "brand"){
				string brand;
				cout << "Enter the brand : ";
				color(7);
				fflush(stdin);
				getline(cin , brand);
				color(11);
				PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
				brand = trim(toLowerCase(brand));
				searchByBrand(root,mobStack,brand);
				return;
			}
			else if(searchType == "operatingSystem"){
				string os;
				fflush(stdin);
				cout << "Enter the operating system(ios/android) : ";
				getline(cin , os);
				PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
				os = trim(toLowerCase(os));
				searchByOperatingSystem(root,mobStack,os);
				return;
			}
			if(searchType == "touchScreen"){
				string choice ;
				while(1){
				choice = "";
				cout << "       [Yes/No]: ";
					fflush(stdin);
					getline(cin,choice);
					PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
					choice = trim(toLowerCase(choice));
					
					if(choice == "yes" || choice == "no")
						break;
					else{
						gotoxy(45,20);
						color(4);
						cout << "Enter valid input ";
						color(7);
						gotoxy(45,19);
						cout << "                                                        ";
						gotoxy(45,19);
					}
				}
				searchByTouchScreen(root,mobStack,choice);
				return;
			}
			float ub, lb;
			string lowerBound = "" , upperBound = "";
			while(true){
				color(11);
				fflush(stdin);
			cout << "Enter the lower Bound: ";
			color(7);
			getline(cin,lowerBound);
			if(!(isDigits(lowerBound))){
					gotoxy(45,20);
						color(4);
						cout << "Enter valid input ";
						color(7);
						gotoxy(45,19);
						cout << "                                                        ";
						gotoxy(45,19);
						continue;
				}
				
//			cin >> lb;
			color(11);
			PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
			gotoxy(45,19);
			cout << "                                                    ";
			gotoxy(45,19);
			cout << "enter the Upper Bound: ";
			color(7);
			fflush(stdin);
			getline(cin , upperBound);
//			cin >> ub;
				if(!(isDigits(upperBound))){
					gotoxy(45,20);
						color(4);
						cout << "Enter valid input ";
						color(7);
						gotoxy(45,19);
						cout << "                                                        ";
						gotoxy(45,19);
						continue;
				}
				break;
			}
			lb = stringToFloat(lowerBound);
			ub = stringToFloat(upperBound);

			color(11);
			PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
			if(searchType == "batteryCapacity")
				searchByBatteryCapacity(root,mobStack,ub,lb);
			else if(searchType == "screenSize")
				searchByScreenSize(root,mobStack,ub,lb);
			else if(searchType == "processor")
				searchByProcessor(root,mobStack,ub,lb);
			else if(searchType == "ram")
				searchByRam(root,mobStack,ub,lb);
			else if(searchType == "storage")
				searchByStorage(root,mobStack,ub,lb);
			else if(searchType == "rearCamera")
				searchByRearCamera(root,mobStack,ub,lb);
			else if(searchType == "frontCamera")
				searchByFrontCamera(root,mobStack,ub,lb);
			else if(searchType == "numberOfSims")
				searchByNumberOfSims(root,mobStack,ub,lb);
			else if(searchType == "price")
			 	searchByPrice(root,mobStack,ub,lb);
			else
				cout << "Error!"<<endl;
		}
};

