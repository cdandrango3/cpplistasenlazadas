#include <iostream>
using namespace std;
class Node{
private:
	string data;
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
	 string getFront() const;
	 string getback()  const;
	 void addFront(string dt,string g,string h,int en);
	 void addBack(string dt,string g,string h,int en);
	 void removefront();
	 void removeback(string f);
	 void getval(string f);
	 void printreverse();
	 void printfoward();
	 void head();	 
private:
Node *header;
Node *trailer;
};
int main(){
	string his;
	string s="s";
	string aca="s";
	string foward;
	string busqueda;
	
	string nombre;
	string fechau;
	int enfermedad;
	LinkedList historia;
	int acabar=0;
	historia.addBack("Ah1","Maria Lopez","12/14/2028",5);
	historia.addBack("Ah2","Juan Lopez","12/14/2028",6);
	historia.addBack("Ah4","Ricardo Mendez","12/14/2028",7);
		historia.addBack("Ah5","Maria Lopez","12/14/2028",6);
	
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
			try{
				cin>>enfermedad;
			}
			catch(const std::exception& e){
				cout<<"solos e permiten numeros";
			}
			
			while (enfermedad < 0 || enfermedad > 9) {
			   cout<<"Ingrese la ultima enfermedad \n";
			   cin>>enfermedad;
			   
			}
			cout<<"Ingrese la 0 si desea ingresar arriba o otra tecla para abajo \n";
			cin>>foward;
			if (foward=="0"){
				historia.addBack(his,nombre,fechau,enfermedad);
				historia.printfoward();
			}
			else{
			  historia.addFront(his,nombre,fechau,enfermedad);
			  historia.printfoward();
			}
			
		 break;
		case 2:
		cout<<"Ingresa el valor a eliminar \n ";
			cin>>busqueda;
			
			historia.removeback(busqueda);	
			
		
		break;
		case 3:
			historia.head();
			cout<<"\n";
			historia.printfoward();
		break;
		case 4:
		    cout<<"Ingresa el valor a buscar \n";
			cin>>busqueda;
				historia.head();
			historia.getval(busqueda);
				
		break;
		default:
			break;
	} 
	cout<<"\n";
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
 
 string LinkedList::getFront() const{
 return header->next->data;
 }
 string LinkedList::getback() const{
 return trailer->prev->data;
 }
 void LinkedList::addFront(string dt,string g,string h,int n){
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
  void LinkedList::addBack(string dt,string g,string h,int n){
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
 void LinkedList::head(){
 		cout <<"Historial ";
 		cout <<" Nombre ";
 		cout <<" Ultima visita ";
 		cout <<" enfermedad ";
 		cout << "\n";
 		cout << "-------------------------";
 }
  void LinkedList::removeback(string f){
   Node *aux1, *aux2;
    int count = 0;
   
    if( header == NULL ) {
        cout << "Lista vacia" << endl;
    } else {
        aux1 = header;
       
        while( aux1 != NULL ) {
            if( f == aux1 -> data ) {
                count++;
 
                if(aux1 == header){
 
                      header = aux1->next;
                      delete aux1;
                }
                 else if(aux1  == trailer){
 
                      trailer = aux2;
                      delete aux1;
                 }
                 else{
                 
                      aux2->next = aux1->next;
                      delete aux1;
                 }
             break;
            } 
			
			else {
                aux2 = aux1;
                aux1 = aux1 -> next;
            }
            
        }
    }
     if( count == 0 ) {
        cout << "\nNumero no encontrado" << endl;
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
 Node *nd=header->next;
 	while(nd != trailer){
 		cout << nd->data<<"    ";
 		cout << nd->g << "    ";
 		cout << nd->h << "    ";
 		cout << nd->en <<"   ";
 		cout << "\n";		
		nd=nd->next;
	   
	 }
 	
 }
  void LinkedList::getval(string f){
 Node *nd=header->next;
 int count=0;
 	while(nd != trailer){
 	   if (f==nd->data){
 	   	cout << nd->data << " ";
 		cout << nd->g << " ";
 		cout << nd->h << " ";
 		cout << nd->en << " ";
 		count++;
 		break;
		}
		else{
			
		}
	nd=nd->next;	
 	}
 	if (count==0){
	 cout<<"No encontrado";
	 }
	 }
LinkedList::~LinkedList(){
	while(header->next!=trailer)
	  removefront();
	delete header;
	delete trailer;
}
 
 
 
 
