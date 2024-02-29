#include <iostream>
using namespace std;

struct Persona{
    string nombre;
    unsigned char edad;
    string telefono;
    string comida_fav;
    float peso_kg;
    unsigned short estatura_cm;
};
Persona ingresarDatos(Persona persona,string nombre, unsigned char edad, string telefono, string comida_fav, float peso_kg, unsigned short estatura_cm){
        persona.nombre = nombre;
        persona.edad = edad;
        persona.telefono = telefono;
        persona.comida_fav = comida_fav;
        persona.peso_kg = peso_kg;
        persona.estatura_cm = estatura_cm;
        return Persona;
}
void imprimir(Persona){
    cout << "Nombre: " << Persona.nombre << endl;
    cout << "Edad: " << Persona.edad << endl;
    cout << "Telefono: " << Persona.telefono << endl;
        //TERMINAR
    }


class Elemento{
public:
    Persona *dato;
    Elemento* siguiente;
};

class Cola{
public:
    Elemento* ultimo;
    int cont;
    Cola(){
        ultimo = nullptr;
        cont = 0;
    }
    void push(Persona *dato){
        Elemento *elemento_nuevo = new Elemento();
        
        elemento_nuevo->dato = dato;
        elemento_nuevo->siguiente = ultimo;
        
        ultimo = elemento_nuevo;
        cont++;
    }
    Persona *pop(){
        //Validación de si está vacía
        
        Elemento *ele = ultimo;
        while(ele->siguiente != nullptr){
            ele=ele->siguiente;
        }
        //Valida si hay un segundo
        Elemento *segundo = ultimo;
        for(int i = 0; i < cont-2 ; i++){
            segundo = segundo->siguiente;
        }
        segundo->siguiente = nullptr;
        Persona *dato = ele->dato;
        delete ele;
        cont--;
        return dato;
    }
    void imprimir(){
        Elemento *ele = ultimo;
        while(ele->siguiente != nullptr){
            cout << "++++++++++++++++++++++++++" << endl;
            ele->dato->imprimir();
            cout << "**************************" << endl;
            ele=ele->siguiente;
        }
    }
};

int main()
{
    Cola* c = new Cola();
    Persona *david = ingresarDatos("David", 24, "12345678", "Pizza", 60, 165);
    
    Persona *danna = new Persona("Danna", 18, "123123123", "Sushi", 58, 159);
    c->push(danna);
    c->push(david);
    c->imprimir();
    
    Persona *persona_nueva = c->pop();
    persona_nueva->imprimir();
    delete persona_nueva;
    
    return 0;
}
