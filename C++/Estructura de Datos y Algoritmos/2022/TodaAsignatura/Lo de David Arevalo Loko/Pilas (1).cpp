#include <iostream>

using namespace std;

struct Nodo{
  int dato;
  Nodo *p_next = nullptr;
};

struct Pila{
  const int capacity = 10;
  Nodo *p_top = nullptr;
  int contador = 0;
  //Funcion para ver si la pila esta vacia
  bool isEmpty(){return (p_top == nullptr);}
  //Funcion para añadir datos
  void push(int new_data){
    //Si esta lleno
    if(contador == capacity){
      cout << "Stack Overflow \n";
    }
    //Resto de casos
    else{
      Nodo *temp = new Nodo{new_data, p_top};
      p_top = temp;
      contador++;
    }
  }
  //Funcion para sacar datos
  int pop(){
    //Si esta vacÃio
    if(isEmpty()){
      cout << "Stack Underflow \n";
      return -1;
    }
    //Si solo hay 1 elemento
    if(p_top -> p_next == nullptr){
      int value = p_top -> dato;
      delete p_top;
      p_top = nullptr;
      return value;
    }
    //Resto de casos (no tengo puntero al valor anterior, tengo que guardar la ref)
      Nodo *p_temp = p_top;
      int value = p_top -> dato;
      p_top = p_top -> p_next;
      delete p_temp;
      p_temp = nullptr;
      contador--;
      return value;
    } 
    int peek(){
      if(isEmpty()){return -1;}
      return p_top -> dato;
    }
    void display(){
      if(isEmpty()){
        cout << "\n Stack Underflow\n" <<endl;
      }
      else{
        Nodo* p_it = p_top;
        while(p_it != nullptr){
          cout << p_it -> dato << " -> ";
          p_it = p_it -> p_next;
        }
        delete p_it;
        p_it = nullptr;
      }
    }
};

void test(){
  Stack exStack;
  exStack.display();

  exStack.push(11);
  exStack.push(22);
  exStack.push(33);
  exStack.push(44);

  exStack.display();

  cout << "\nTop element is "<< exStack.peek() << endl;

  exStack.pop();
  exStack.pop();
  // Display stack elements
  exStack.display();

  cout << "\nTop element is "<< exStack.peek() << endl;
}

void stack_menu(){
  Stack exStack;
  int opc = 0; 
  do{
    cout << "\n Menu \n"
            "1) Display Stack \n"
            "2) Add element \n"
            "3) Remove element \n"
            "4) Show top value \n"
            "5) Exit" << endl;
    cout << "Option: ";
    cin >> opc;
    cout <<endl;
    switch (opc) {
      case 1:
        exStack.display();
        break;
      case 2:
        int value=0;
        cout << "Value to be aded: ";
        cin >> value;
        exStack.push(value);
        break;
      case 3:
        cout << "Value removed: " << exStack.pop();
        break;
      case 4:
        cout << "Value at top: " << exStack.peek() <<endl;
        break;
      default:
        cout << "Value not valid. 1-5 " << endl;
    }
  }
  while(opc!=5);
}

int main(){

}
