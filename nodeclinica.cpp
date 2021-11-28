#include <iostream>
using namespace std;
class Node{
private:
	int data;
	string g;
	string h;
	int en;
	Node *prev;
	Node *next;
	friend class LinkedList;
};

class LinkedList{
public:	
	
	 LinkedList();
	 ~LinkedList();
	 int getFront() const;
	 int getback()  const;
	 void addFront(int dt,string g,string h,int en);
	 void addBack(int dt,string g,string h,int en);
	 void removefront();
	 void removeback(int f);
	 void getval(int f);
	 void printreverse();
	 void printfoward();	 
private:
Node *header;
Node *trailer;
};
int main(){
	int his;
	string s="s";
	string aca="s";
	int foward;
	int busqueda;
	string nombre;
	string fechau;
	int enfermedad;
	LinkedList historia;
	int acabar=0;
	historia.addBack(1,"Maria Lopez","12/14/2028",5);
	historia.addBack(2,"Juan Lopez","12/14/2028",6);
	historia.addBack(3,"Ricardo Mendez","12/14/2028",7);
		historia.addBack(4,"Maria Lopez","12/14/2028",6);
	
	do{
	int op;
	cout<<"Bienvenido a farmacia ca ingrese  una opcion \n";
	cout<<"1. agregar \n";
	cout<<"2. eliminar \n";
	cout<<"3. listar\n";
	cout<<"4. buscar \n";
	
	cin>>op;
	cout<<op;
	switch(op){
		case 1:
			cout<<"Ingrese el n historial \n";
			cin>>his;
			cout<<"Ingrese el nombre \n";
			cin>>nombre;
			cout<<"Ingrese la ultima visita \n";
			cin>>fechau;
			cout<<"Ingrese la ultima enfermedad \n";
			cin>>enfermedad;
			while (enfermedad < 0 || enfermedad > 9) {
			   cout<<"Ingrese la ultima enfermedad \n";
			   cin>>enfermedad;
			}
			cout<<"Ingrese la 0 si desea ingresar arriba o otra tecla para abajo \n";
			cin>>foward;
			if (foward==0){
				historia.addBack(his,nombre,fechau,enfermedad);
				historia.printreverse();
			}
			else{
			  historia.addFront(his,nombre,fechau,enfermedad);
			  historia.printreverse();
			}
			
		 break;
		case 2:
		cout<<"Ingresa el valor a eliminar \n ";
			cin>>busqueda;
			
			historia.removeback(busqueda);	
			
		
		break;
		case 3:
			historia.printreverse();
		break;
		case 4:
		    cout<<"Ingresa el valor a buscar \n";
			cin>>busqueda;
			historia.getval(busqueda);
				
		break;
		default:
			break;
	} 
	cout<<"ingrese 1 para acabar";
	cin>>acabar;
}while(acabar != 1);
	return 0;
}

 LinkedList::LinkedList(){
 	header=new Node;
 	trailer=new Node;
 	header->next=trailer;
 	trailer->prev=header;
 	header -> prev=NULL;
 	header -> next=NULL;
 	
 }
 
 int LinkedList::getFront() const{
 return header->next->data;
 }
 int LinkedList::getback() const{
 return trailer->prev->data;
 }
 void LinkedList::addFront(int dt,string g,string h,int n){
 	Node *nd=new Node;
 	nd->data=dt;
 	nd->g=g;
 	nd->h=h;
 	nd->en=n;
 	nd->prev=header;
 	nd->next=header->next;
 	header->next->prev=nd;
 	header->next=nd;
 	
 }
  void LinkedList::addBack(int dt,string g,string h,int n){
 	Node *nd=new Node;
 	nd->data=dt;
 	nd->h=h;
 	nd->g=g;
 	nd->en=n;
 	nd->prev=trailer->prev;
 	nd->next=trailer;
 	trailer-> prev -> next =nd;
 	trailer->prev=nd;
 }
 void LinkedList::removefront(){
 	
	Node *nd=header->next->next;
 	delete header -> next;
 	header->next=nd;
 	nd->prev=header;
 }
  void LinkedList::removeback(int f){
 
 Node *nd=trailer->prev;
 
 	while(nd != header){
 	   if (f==nd->data){
 		Node *na=nd->prev->prev;
 		if (na==NULL){	
         	delete header;
		 break;
		 }
		
		delete nd -> prev;
 	    nd->prev=na;
 	    nd->next=nd;
 	    
 		break;
		}
		else{
			
		}
	nd=nd->prev;	
 	}
 	
 
 	
}

 void LinkedList::printreverse(){
 	Node *nd=trailer->prev;
 	while(nd != header){
 		cout << nd->data << " ";
 		cout << nd->g<< "";
 		cout << nd->h<< "";
 		cout << nd->en<< "";
 		cout << "\n";
 		nd=nd->prev;
	 }

 	
 }
 
  void LinkedList::printfoward(){
 Node *nd=trailer->prev;
 	while(nd != header){
 		cout << nd->data << " ";
 		cout << nd->g << " ";
 		cout << nd->h << " ";
 		cout << nd->en << " ";
 		cout << "\n";
 		nd=nd->next;
	 }
 	
 }
  void LinkedList::getval(int f){
 Node *nd=trailer->prev;
 	while(nd != header){
 	   if (f==nd->data){
 	   	cout << nd->data << " ";
 		cout << nd->g << " ";
 		cout << nd->h << " ";
 		cout << nd->en << " ";
 		
 		break;
		}
		else{
			
		}
	nd=nd->prev;	
 	}
	 }
LinkedList::~LinkedList(){
	while(header->next!=trailer)
	  removefront();
	delete header;
	delete trailer;
}
 
 
 
 
