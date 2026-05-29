#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstring>
struct element{
	char *data;
	element *next;
};
class linkedList{
	private:
		element *list;
		static unsigned int numberOfNodes;
	public:
		linkedList();
		//virtual ~linkedList();
		void addToStart(char*&);
		void addToEnd(char*&);
		void addToPosition(char*&,const unsigned int&);
		void removeAtStart();
		void removeAtEnd();
		void removeAtPosition(const unsigned int&);
		void show();

};
#endif
