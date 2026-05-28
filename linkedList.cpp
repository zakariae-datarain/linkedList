#include  "linkedList.h"
#include <cstddef>

int linkedList::numberOfNodes=0;

linkedList::linkedList(){
	this->list=NULL;
}


void linkedList::addToStart(char *&data){
	element *newElement = new element;
	if(this->list==NULL){
		this->list=newElement;
		newElement->next=NULL;
		newElement->data=new char[strlen(data)+1];
		strcpy(newElement->data,data);
		newElement->data[strlen(data)]='\0';
	}
	else{
		element *temp=this->list;
		this->list=newElement;
		newElement->next=temp;
		newElement->data=new char[strlen(data)+1];
		strcpy(newElement->data,data);
		newElement->data[strlen(data)]='\0';
		
	}
	linkedList::numberOfNodes++;

}

void linkedList::addToEnd(char *&data){
	if(this->list==NULL){
		this->addToStart(data);
	}
	else{
		element *current=this->list;
		element *newElement= new element;
		while(current != NULL){
			if(current->next==NULL){
				current->next = newElement;
				newElement->next = NULL;
				newElement->data=new char[strlen(data)+1];
				strcpy(newElement->data,data);
				newElement->data[strlen(data)]='\0';

			}
			current=current->next;
		}
	}
	linkedList::numberOfNodes++;
}


void linkedList::addToPosition(char *&data,const int &position){
	if(position>linkedList::numberOfNodes){
		std::cout<<"you are out of bounds\n";
		return;
	}
	else if (position==0){
		this->addToStart(data);
	}
	else if(position==linkedList::numberOfNodes){
		this->addToEnd(data);
	}
	else{
		element *current= this->list;
		for(int i=0;i<position-1;i++){
			current=current->next;
		}
		element *temp= current->next;
		element *newElement=new element;
		current->next=newElement;
		newElement->next=temp;
		newElement->data=new char[strlen(data)+1];
		strcpy(newElement->data,data);
		newElement->data[strlen(data)]='\0';
	}
	


	linkedList::numberOfNodes++;
}


void linkedList::show(){
	element *current=this->list;
	while(current != NULL){
		if(current->next != NULL){
			std::cout<<"|"<<current->data<<"|-->";
		}
		else{
			std::cout<<"|"<<current->data<<"|\n";
		}
		current=current->next;

	}
}



int main(){
	

	linkedList l;
	char *name = new char[20];
	std::cout<<"enter something : ";
	std::cin.getline(name,20);
	l.addToStart(name);
	l.show();
	std::cout<<"\nenter something : ";
	std::cin.getline(name,20);
	l.addToStart(name);
	l.show();
	std::cout<<"\nenter something : ";
	std::cin.getline(name,20);
	l.addToEnd(name);
	l.show();
	std::cout<<"\nenter something : ";
	std::cin.getline(name,20);
	l.addToPosition(name,1);
	l.show();


	return 0;
}
