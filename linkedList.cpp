#include  "linkedList.h"
#include <cstddef>

unsigned int linkedList::numberOfNodes=0;

linkedList::linkedList(){
	this->list=NULL;
}

linkedList::~linkedList(){
	while(this->list !=NULL){
		this->removeAtStart();
	}
	delete this->list;
	std::cout<<"object destoyed\n";
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


void linkedList::addToPosition(char *&data,const unsigned int &position){
	if(position>linkedList::numberOfNodes){
		std::cout<<"you are out of bounds\n";
		return;
	}
	else if (position==1){
		this->addToStart(data);
	}
	else if(position==linkedList::numberOfNodes){
		this->addToEnd(data);
	}
	else{
		element *current= this->list;
		for(int i=1;i<position-1;i++){
			current=current->next;
		}
		element *temp= current->next;
		element *newElement=new element;
		current->next=newElement;
		newElement->next=temp;
		newElement->data=new char[strlen(data)+1];
		strcpy(newElement->data,data);
		newElement->data[strlen(data)]='\0';
		linkedList::numberOfNodes++;
	}
	


}


void linkedList::removeAtStart(){
	if(this->list==NULL){
		std::cout<<"empty list \n";
		return;
	}
	element *tmp=this->list;
	this->list=this->list->next;
	tmp->next=NULL;
	delete [] tmp->data;
	delete tmp;

	linkedList::numberOfNodes--;
}


void linkedList::removeAtEnd(){
	if(this->list==NULL){
		std::cout<<"empty list !\n";
		return;
	}
	else if(this->list->next==NULL){
		this->removeAtStart();
		return;
	}
	element *current=this->list;
	while(current->next->next !=NULL){
		
		current=current->next;
	}

	element *tmp=current->next;
	current->next = NULL;
	delete [] tmp->data;
	delete tmp;
	linkedList::numberOfNodes--;
}

void linkedList::removeAtPosition(const unsigned int &position){
	if(position>linkedList::numberOfNodes){
		std::cout<<"you are out of bounds brother!\n";
	}
	else if(position==1){
		this->removeAtStart();
	}
	else if(position==linkedList::numberOfNodes){
		this->removeAtEnd();
	}
	else{
		element *current=this->list;
		for(int i=1;i<position-1;i++){
			current=current->next;
		}
		element *tmp=current->next;
		current->next=current->next->next;
		tmp->next=NULL;
		delete [] tmp->data;
		delete tmp;
		linkedList::numberOfNodes--;

	}
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
	

	linkedList *l=new linkedList();
	char *name = new char[20];
	std::cout<<"enter something : ";
	std::cin.getline(name,20);
	l->addToStart(name);
	l->show();
	std::cout<<"\nenter something : ";
	std::cin.getline(name,20);
	l->addToStart(name);
	l->show();
	std::cout<<"\nenter something : ";
	std::cin.getline(name,20);
	l->addToEnd(name);
	l->show();
	std::cout<<"\nenter something : ";
	std::cin.getline(name,20);
	l->addToPosition(name,1);
	l->show();
	l->removeAtPosition(5);
	l->show();
	delete l;


	return 0;
}
