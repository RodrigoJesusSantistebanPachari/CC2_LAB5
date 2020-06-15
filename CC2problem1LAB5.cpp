#include<iostream>
using namespace std;

class Node{
	private:
		int elem;
		Node *next;
	public:
		Node(){
			this->elem = 0;
			next = NULL;
		}
		Node(int elem){
			this->elem = elem;
			next = NULL;
		}
		Node(Node &next1){
			this->elem=next1.elem;
			this->next=next1.next;
		}
		int getElement(){
			return elem;
		}
		void setElement(int element){
			this->elem = element;
		}
		Node *getNext(){
			return this->next;
		}
		void setNext(Node *next1){
			this->next = next1;
		}
		~Node(){
		}
};

class LinkedList{
	private:
		int size;
		Node *head;
	public:
		
		LinkedList(){
			this->size = 0;
			head = NULL;
		}
		
		LinkedList(int size){
			this->size = 1;
			head = new Node(size);
		}
		void insert(int number){
			Node *new_node = new Node();
			new_node->setElement(number);
			
			Node *aux1 = head;
			Node *aux2;
			
			while((aux1!=NULL)&&(aux1->getElement() < number)){
				aux2 = aux1;
				aux1 = aux1->getNext();
			}
			
			if(head==aux1){
				head = new_node;
			}
			
			else{
				aux2->setNext(new_node);
			}
			
			new_node->setNext(aux1);
			
			size++;
		}
		
		void print(){
			
			Node *current_node = new Node();
			current_node = head;
			
			while(current_node != NULL){
				cout<<current_node->getElement()<<" -> ";
				current_node = current_node->getNext();
			}
			
		}
		
		void remove(int number1){
			
			if(head !=NULL){
				Node *aux_delete = head;
				Node *previous = NULL;
				
				while((aux_delete != NULL)&&(aux_delete->getElement() != number1)){
					previous = aux_delete;
					aux_delete = aux_delete->getNext();
				}
				
				if(aux_delete = NULL){
					cout<<"The element hasn't been found";
				}
				
				else if(previous == NULL){
					head = head->getNext();
					delete aux_delete;
				}
				
				else{
					previous->setNext(aux_delete->getNext());
					delete aux_delete;
				}
				
			}
			
		}
		
		~LinkedList(){
		}
};

int main(){
	
	
	//Nodes
	cout<<"We will create three Nodes\n\n";
	int n1,n2,n3;
	cout<<"\nEnter a number ";cin>>n1;
	cout<<"\nEnter a number ";cin>>n2;
	cout<<"\nEnter a number ";cin>>n3;
	Node node1(n1);
	Node node2(node1);   
	node2.setElement(n2);
	Node node3(n3);
	node3.setNext(&node2);
	cout<<"\n\nPrinting current nodes: \n";
	cout<<node1.getElement()<<" -> "<<node2.getElement()<<" -> "<<node3.getElement()<<" -> \n\n";



	//LinkedList
    cout<<"\n\nWe will create a LinkedList now\n\n";
    LinkedList list(5);
    //We will insert many numbers now
    list.insert(8);
    list.insert(3);
    list.insert(3);
    list.insert(25);
    list.insert(1);
    list.insert(2);
    list.insert(9);
    list.print();

    
	return 0;
}
