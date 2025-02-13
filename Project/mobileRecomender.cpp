#include <iostream>
#include <conio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <iomanip>
class mobile; //further declaration
//prototypes of the functions below the main
void merger(mobile**m,int low,int mid,int high,int size,string title);
void mergeSort(mobile **m , int low , int high,int size,string title);


using namespace std;
class mobile;
class mobile{
	public:
		int id;
		string name , brand;
		float batteryCapacity ;
		float screenSize;
		string touchScreen;
		float resX,resY,processor,ram ,storage,rearCamera,frontCamera;
		string operatingSystem;
		float numberOfSims , price;
			mobile(){}
		mobile(int id,string name,string brand,float battery,float screenSize,string touch,float resX,float resY,float processor,float ram,float storage,float rear,float front,string os,float sims,float price){
			this->id = id;
			this->name = name;
			this->brand = brand;
			this->batteryCapacity = battery;
			this->screenSize = screenSize;
			this->touchScreen= touch;
			this->resX=resX;
			this->resY=resY;
			this->processor=processor;
			this->ram=ram;
			this->storage = storage;
			this->rearCamera=rear;
			this->frontCamera=front;
			this->operatingSystem=os;
			this->numberOfSims=sims;
			this->price=price;
		}
			getche();
			string getName(){return name;}
			string getBrand(){return brand;}
			string getTouchScreen(){return touchScreen;}
			string getOs(){return operatingSystem;}
			float getBattery(){return batteryCapacity;}
			float getScreenSize(){return screenSize;}
			float getResX(){return resX;}
			float getResY(){return resY;}
			float getProcessor(){return processor;}
			float getRam(){return ram;}
			float getStorage(){return storage;}
			float getRearCamera(){return rearCamera;}
			float getFrontCamera(){return frontCamera;}
			float getSims(){return numberOfSims;}
			float getPrice(){return price;}
};
void Filing(mobile *array[]){
	int id;
	string name , brand;
	float battery , screenSize;
	string touchScreen;
	float resX,resY,processor,ram ,storage,rearCamera,frontCamera;
	string os;
	float sims , price;
	fstream file;
	file.open("data.txt");
	char buff;
	for(int i=0;i<1358;i++){
		file>>id>>name>>brand>>battery>>screenSize>>touchScreen>>resX>>resY>>processor>>ram>>storage>>rearCamera>>frontCamera>>os>>sims>>price;
		array[i]  = new mobile(id,name,brand,battery,screenSize,touchScreen,resX,resY,processor,ram,storage,rearCamera,frontCamera,os,sims,price);
	}
}
//id,Name,Brand,Battery capacity (mAh),Screen size (inches),Touchscreen,Resolution x,Resolution y,Processor,Ram ,Internal storage (GB),Rear camera,Front camera,Operating system,Number of SIMs,Price
string choice(int c){
	switch(c){
		case 1:
			return "name";
		case 2:
			return "brand";
		case 3:
			return "batteryCapacity";
		case 4:
			return "screenSize";
		case 5:
			return "touchScreen";
		case 6:
			return "processor";
		case 7:
			return "ram";
		case 8:
			return "storage";
		case 9:
			return "rearCamera";
		case 10:
			return "frontCamera";
		case 11:
			return "operatingSystem";
		case 12:
			return "numberOfSims";
		case 13:
			return "price";
	}
	
}
linkedList<mobile*> creatingList(string allFilters[13],mobile *m[1358]){
	linkedList<mobile*> l;

	AVL_Tree<mobile*> treeName , treeBrand , treeBatteryCapacity , treeScreenSize,treeTouchScreen,treeProcessor;
	AVL_Tree<mobile*> treeRam , treeStorage , treeFrontCamera , treeRearCamera , treeOperatingSystem , treeNumberOfSims , treePrice;
	for(int i=0;i<1358;i++) {
		mobile* currentMobile = m[i];
		string currentFilter = allFilters[0];
		treeName.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[1];
		treeBrand.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[2];
		treeBatteryCapacity.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[3];
		treeScreenSize.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[4];
		treeTouchScreen.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[5];
		treeProcessor.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[6];
		treeRam.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[7];
		treeStorage.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[8];
		treeFrontCamera.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[9];
		treeRearCamera.insert(currentMobile,currentFilter);
		
		
		currentFilter = allFilters[10];
		treeOperatingSystem.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[11];
		treeNumberOfSims.insert(currentMobile,currentFilter);
		
		currentFilter = allFilters[12];
		treePrice.insert(currentMobile,currentFilter);
	}
	//making array of tree objects
	AVL_Tree<mobile*> tree[13] = {treeName , treeBrand , treeBatteryCapacity , treeScreenSize,treeTouchScreen,treeProcessor ,treeRam , treeStorage , treeFrontCamera , treeRearCamera , treeOperatingSystem , treeNumberOfSims , treePrice};
	for(int i=0;i<13;i++){
		l.pushBack(allFilters[i],tree[i]);
	}
	return l;
}
string* introduction(int &numberOfFilters){
		gotoxy(30,0);
		color(11);
		cout << "====================";
		color(7);
		cout << "Welcome to";
		color(11);
		cout << "====================\n";
		gotoxy(30,1);
		cout << "==========";
		color(7);
		cout << "Mobile Recommendation System";
		color(11);
		cout << "============\n\n";
		string noOfFilters = "";
	while(1){
		gotoxy(60,6);
		cout << "                                                                                                     ";
		gotoxy(30,6);
		cout << "Enter the number of filters you want to apply(1-13) : ";
		color(7);
		getline(cin,noOfFilters);

		if(!(noOfFilters == "1" || noOfFilters == "2" || noOfFilters == "3" || noOfFilters == "4" || noOfFilters == "5" || noOfFilters == "6" || noOfFilters == "7" || noOfFilters == "8" || noOfFilters == "9" || noOfFilters == "10" || noOfFilters == "11" || noOfFilters == "12" || noOfFilters == "13")){
			PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
			color(4);
			gotoxy(68,7);
			cout << "Invalid Input";
			color(11);
			continue;
		}
		numberOfFilters = noOfFilters.length() == 1 ? noOfFilters[0]-48 : (noOfFilters[0]-48)*10 + (noOfFilters[1] - 48) ;
		PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	}
	system("cls");
	gotoxy(30,0);
		color(11);
		cout << "====================";
		color(7);
		cout << "Filters";
		color(11);
		cout << "====================\n";
	color(11);
	gotoxy(50,5);
	cout <<"1.Name" << endl;
	gotoxy(50,6);
	cout<<"2.Brand" << endl;
	gotoxy(50,7);
	cout<<"3.batteryCapacity" << endl;
	gotoxy(50,8);
	cout<<"4.screenSize" << endl;
	gotoxy(50,9);
	cout<<"5.touchScreen" << endl;
	gotoxy(50,10);
	cout<<"6.processor" << endl;
	gotoxy(50,11);
	cout<<"7.Ram" << endl;
	gotoxy(50,12);
	cout<<"8.storage" << endl;
	gotoxy(50,13);
	cout<<"9.frontCamera" << endl;
	gotoxy(50,14);
	cout<<"10.backCamera" << endl;
	gotoxy(50,15);
	cout<<"11.OperatingSystem" << endl;
	gotoxy(50,16);
	cout<<"12.NumberOfSims" << endl;
	gotoxy(50,17);
	cout<<"13.Price" << endl;
	string * filters = new string[numberOfFilters];
	string c;
	for(int i=0;i<numberOfFilters;i++){
		gotoxy(55,19);
			cout << "                            ";
		gotoxy(45,19);
		cout << "Enter filter number "<<i+1<<" :";
		color(7);
		cin >> c;
		PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		color(11);
		if(!(c == "1" || c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == "7" || c == "8" || c == "9" || c == "10" || c == "11" || c == "12" || c == "13")){
			gotoxy(45,18);
			color(4);
			cout << "Enter a valid input(1-13) "<<endl;
			color(11);
			PlaySound("./Sounds/error.wav", NULL, SND_FILENAME | SND_ASYNC);
			i--;
			continue;
		}
		gotoxy(45,18);
		cout << "                                ";
		int ch = (c.length() == 1)?c[0] - 48 : (c[0]-48)*10 + (c[1]-48);
		filters[i] = choice(ch);
	}
	return filters;
	getchar();
}
void applyFilters(linkedList<mobile*> list , string *userFilters,int numberOfFilters){
	stackQueue<mobile*> mobileStack[numberOfFilters];
	for(int i=0;i<numberOfFilters;i++){
		gotoxy(55,18);
		cout << "                               ";
		gotoxy(55,18);
		color(9);
		linkedNode<mobile*> *curListNode = list.currentTitleNode(userFilters[i]);
		color(11);
		gotoxy(45,19);
		cout << "                                                            ";
		gotoxy(45,19);
		AVL_Tree<mobile*> currentTree = curListNode->tree;
		currentTree.search(userFilters[i], mobileStack[i]);
	}
	if(numberOfFilters > 1){
		for(int i = 1;i<numberOfFilters;i++){
			cout << mobileStack[1].getSize() << endl;
			mobileStack[0].intersection(mobileStack[i]);
		}
	}
	int size = mobileStack[0].getSize() , count = 0;
	if(size == 0){
		system("cls");
		gotoxy(45,5);
		cout << "Sorry, no such mobiles Found"<<endl;
		return;
	}
	mobile* arr[size] ;
	char input = 'n';
	for(int i = size-1;i>=0;i--){
		arr[i] = mobileStack[0].top();
		mobileStack[0].pop();
	}
	system("cls");
	gotoxy(30,0);
		color(11);
		cout << "====================";
		color(7);
		cout << "Results";
		color(11);
		cout << "====================\n";
		int totalPages = ceil((float)size/10.0) , pages = 1;
		cout << "\t\t\t\t\t    You are on page " <<pages << " of "<<totalPages<<endl;
		
	for(int i = 0 ; i < size  ; i++){
		if(count == 10 ){
			cout << "\n\t\t\t\t<--(p) \t ($)SortByPrice(s)SortByName(e)Exit \t (n)-->";
			count = 0;
			input = getche();
			PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			if(input == 'n')
				pages++;
			if(i == size -1 && input == 'n')
				break;
			if(input == 'p' && i-10 > 0)
				pages--;
			cout << "\t\t\t\t\t\tyou are on page " <<pages << " of "<<totalPages<<endl;
		}
		if(input == 'n'){
			if(count == 0){
				color(9);
				cout <<setw(30)<<"Name"<<setw(11)<<"Brand"<<setw(6)<<"Bat"<<setw(5)<<"Ram";
				cout <<setw(7)<< "strg"<<setw(6)<<"rCam"<<setw(6)<<"FCam"<<setw(3)<<"OS";
				cout <<setw(4)<< "NOS"<<setw(9)<<"price"<<setw(4)<<"Ts"<<setw(6)<<"size"<<setw(6)<<"proc"<<endl;
			}
			color(11);
			cout <<setw(30)<<arr[i]->getName()<<setw(11)<<arr[i]->getBrand()<<setw(6)<<arr[i]->getBattery();
			cout <<setw(5)<<arr[i]->getRam()<<setw(7)<<arr[i]->getStorage()<<setw(6)<<arr[i]->getRearCamera()<<setw(6)<<arr[i]->getFrontCamera();
			string os = (arr[i]->getOs() == "Android")?"A":(arr[i]->getOs() == "Tizen") ? "T" : "I";
			cout << setw(3)<<os<<setw(4)<<arr[i]->getSims()<<setw(9)<<arr[i]->getPrice();
			os = arr[i]->getTouchScreen() == "Yes"?"Y":"N";
			cout<<setw(4)<<os<<setw(6)<<arr[i]->getScreenSize()<<setw(6)<<arr[i]->getProcessor()<<endl;
			
		}
		else if(input == 's' || input == '$'){
			int end = 0;
			if(i == size - 1)
			{
				i = i - size%10;
				end = size-1;
			}
			else{
				i -= 11;
				end = i + 10;
			}
			if(input == '$')
				mergeSort(arr,i+1,end,size,"price");
			else
				mergeSort(arr,i+1,end,size,"name");
			input = 'n';
			count = 0;
			continue;
		}
		else if(input == 'e'){
			system("cls");
			break;
		}
		else if(input == 'p'){
			if(i>=20 && pages > 1)
			{
				i-=21;
				count = 0;
				input = 'n';
				continue;
			}
			else
			{
				i = -1;
				input = 'n';
				count = 0;
				continue;
			}
		}
		else{
			color(4);
			cout << "\t\t\t\t\t\tEnter valid input "<<endl;
			i-=11;
			count = 0;
			input = 'n';
			continue;
		}
		count ++;
		if(i == size -1){
			cout << "\n\t\t\t\t<--(p) \t ($)SortByPrice(s)SortByName(e)Exit \t (n)-->";
			count = 0;
			input = getche();
			PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			if(input == 'n')
				break;
			if(input == 'p' && i-10 > 0)
				pages--;
				i--;
			cout << "\t\t\t\t\t\tYou are on page " <<pages << " of "<<totalPages<<endl;
		}
	}
}
int main(){
	PlaySound("./Sounds/open.wav", NULL, SND_FILENAME | SND_ASYNC);
	mobile *m[1358];
	Filing(m);
	string allFilters[13] = {"name","brand","batteryCapacity","screenSize","touchScreen","processor","ram","storage","rearCamera","frontCamera","operatingSystem","numberOfSims","price"};
	//here creating the complex data sturcture of list containing trees
	linkedList<mobile*> list = creatingList(allFilters,m);
	char choice;
	while(true){
		int numberOfFilters = 0;
		string *filters = introduction(numberOfFilters);
		applyFilters(list,filters,numberOfFilters);
		cout << endl << "					    Do you want to search again [y/n]";
		color(7);
		choice = getche();
		color(11);
		PlaySound("./Sounds/click.wav", NULL, SND_FILENAME | SND_SYNC);
		if(choice == 'y' || choice == 'Y')
		{
			system("cls");
			delete []filters;
			continue;
		}
		break;
	}
	system("cls");
    color(11);
    gotoxy(40,5);
	cout << "Thank you for using Mobile Recommendation System!";
	gotoxy(57,7);
	cout << "Made By:\n";
	color(7);
	gotoxy(47,9);
	cout << "Fahd Aleem          21k-3314" << endl;
	gotoxy(47,10);
	cout << "Muhammad Hamza      21k-3253";
	gotoxy(47,11);
	cout << "Muhammad Mubashir   21k-3353";
	color(7);
	PlaySound("./Sounds/quit.wav", NULL, SND_FILENAME | SND_SYNC);
	color(11);
	return 0;
}
void merger(mobile**m,int low,int mid,int high,int size,string title){
	mobile* C[size] ;
	int i = low , j = mid + 1 , k = low;
	while(i<= mid && j <= high){
		if(title == "name"){
			if(m[i]->getName() < m[j]->getName())
				C[k++] = m[i++];
			else
				C[k++] = m[j++];
		}
		else if(title == "price"){
			if(m[i]->getPrice() < m[j]->getPrice())
			{
				C[k++] = m[i++];
			}
			else
				{
					C[k++] = m[j++];
				}
		}
	}
	
	while(i<=mid)
		C[k++] = m[i++];
	while(j<=high)
		C[k++] = m[j++];
	
	for(int z = low ; z < k ; z++)
		m[z] = C[z];
	
}
void mergeSort(mobile **m , int low , int high,int size,string title){
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(m,low,mid,size,title);
		mergeSort(m,mid+1,high,size,title);
		merger(m,low,mid,high,size,title);
	}
	
}
