#include <iostream>
using namespace std;

void accionLamer();
void accionAdelante();
void accionAtras();
void accionDerecha();
void accionIzquierda();

string nombre;
float estatura;
float estaturaDefinida;
bool altura;
int seccion = 0;
bool medicinaTomada = false;
int sala[4][3] = { {1,2,3}
                    ,{6,5,4}
                    ,{7,8,9}
                    ,{12,11,10} };
//posiciones
int posicionActual = sala[2][1];
int posicionInicial = sala[2][1];
int posicionFalsa = posicionActual;

//Objetos del cuarto
int salida = sala[1][1];
int  charcoRojo = sala[1][0];
int charcoVerde = sala[3][1];
int medicina = sala[2][0];
int codigo = sala[1][2];
int caja = sala[2][2];

int main()
{
    std::cout << "Bienvenido jugador Digite su nombre: ";
    cin >> nombre;
    cout << "Digite su estutura: ";
    cin >> estatura;

    if (estatura == 1.5) {
        altura = true;
    }
    else if (estatura > 1.7) {
        altura = false;
        estatura = 1.8;
    }
    else if (estatura < 1.6) {
        altura = false;
        estatura = 1.3;
    }

    cout << "Usted se encuentra en una cueva." << endl << "No se ve nada." << endl;


    while (seccion == 0) {
        cout << "Sus controles son (adelante), (derecha), (izquierda), (atras) y (lamer)" << endl;
        string respuesta = "";
        cout << "Digite accion: ";
        cin >> respuesta;

        //adelante
        if (respuesta == "adelante") {
            accionAdelante();
        }
        //lamer
        if (respuesta == "lamer") {
            accionLamer();
        }
            
        //giro a la derecha
        if (respuesta == "derecha") {
            accionDerecha();
        }
        //giro a la izquierda
        if (respuesta == "izquierda") {
            accionIzquierda();
        }
        if (respuesta == "atras") {
            accionAtras();
        }

        if (estatura < 1.5 && estatura >1.4) {
            altura = true;
        }
        else if (estatura > 1.5 || estatura < 1.4) {
            altura = false;
        }
        posicionActual = posicionFalsa;



    }
}
    void accionLamer() {
        //posicion salida
        if (posicionActual == salida) {
            cout << "Sabe a roca" << endl;
        }
        //posicion inicial
        if (posicionActual == posicionInicial) {
            cout << "Sabe a aire" << endl;
        }
        //posicion medicina
        if (posicionActual == medicina) {
            medicinaTomada = true;
            cout << "Me tomo la medicina" << endl;
            cout << "Siento mi lengua mas poderosa" << endl;
        }

        //charco rojo para hacerse chiquito
        if (posicionActual == charcoRojo) {
            estatura = estatura - .1;
            cout << "Lames el charco rojo" << endl;
            cout << "Creo que me encogi" << endl;
            cout << "Mides: " << estatura << endl;
            if (estatura <= 0) {
                cout << "Desaparesiste del mundo...FIN";
                seccion = 1;
            }
        }
        //charco verde para hacerse grande
        if (posicionActual == charcoVerde) {
            estatura = estatura + .1;
            cout << "Lames el charco verde" << endl;
            cout << "Creo que creci" << endl;
            cout << "Mides: " << estatura << endl;
            if (estatura >= 2.5) {
                cout << "Destruiste toda la cueva...FIN";
                seccion = 1;
            }
        }
        //caja
        if (posicionActual == caja) {
            cout << "Lames la caja, sabe a madera" << endl;
            if (medicinaTomada == true) {
                cout << "La baba desintegro parte de la caja" << endl << "Se revela un codigo: (numero).5" << endl;
            }
        }
        //codigo
        if (posicionActual == codigo) {
            cout << "Lames la pared que revela un codigo: 1. (numero)" << endl;
        }
    }

    
    void accionAdelante() {
        //posicion enfrente de la salida
        if (posicionActual == salida) {
            if (altura == true) {
                cout << "Felicidades " + nombre + " escapaste y ahora eres un enano" << endl;
                seccion = 1;
            }
            else if (altura == false)
            {
                cout << "No puedo atravesar" << endl;
            }
        }
        //posicion inicial a salida
        if (posicionActual == posicionInicial) {
            cout << "Avanzas y te topas con un pasadizo " << endl;
            posicionFalsa = salida;

        }
        //posiciones inalcanzables
        if (posicionActual == charcoRojo || posicionActual == codigo) {
            cout << "Hay pared, no puedo pasar" << endl;
        }
        // medicina a charco rojo
        if (posicionActual == medicina) {
            cout << "Avanzo y me encuentro con un charco rojo" << endl;
            posicionFalsa = charcoRojo;
        }
        // caja a codigo
        if (posicionActual == caja) {
            cout << "Avanzo y me encuentro con una pared rara" << endl;
            posicionFalsa = codigo;
        }
        // charco verde a posicion inicial
        if (posicionActual == charcoVerde) {
            cout << "Avanzo y me encuentro en el punto de inicio" << endl;
            posicionFalsa = posicionInicial;
        }
    }


    void accionAtras() {
        //posicion enfrente de la salida a inicial
        if (posicionActual == salida) {
            cout << "Retrocedo y me encuentro en el punto incial" << endl;
            posicionFalsa = posicionInicial;
        }
        //posicion inicial a charco verde
        if (posicionActual == posicionInicial) {
            cout << "Retrocedes y te topas con un charco Verde " << endl;
            posicionFalsa = charcoVerde;


        }
        //posiciones inalcanzables
        if (posicionActual == charcoVerde || posicionActual == medicina || posicionActual == caja) {
            cout << "Hay pared, no puedo pasar" << endl;
        }
        // charco rojo a medicina
        if (posicionActual == charcoRojo) {
            cout << "Retrocedo y me encuentro con una medicina" << endl;
            posicionFalsa = medicina;

        }
        // codigo a caja
        if (posicionActual == codigo) {
            cout << "Retrocedo y me encuentro con una caja" << endl;
            posicionFalsa = caja;
        }

    }
    void accionDerecha() {
        //no accesibles
        if (posicionActual == caja || posicionActual == codigo || posicionActual == charcoVerde) {
            cout << "No puedo avanzar, hay pared" << endl;
        }
        //posicion inicial a caja
        if (posicionActual == posicionInicial) {
            cout << "Avanzas a la derecha y me encuentro con una caja" << endl;
            posicionFalsa = caja;
        }
        //posicion final a pared con codigo
        if (posicionActual == salida) {
            cout << "Avanzas a la derecha y me encuentro con una pared misteriosa" << endl;
            posicionFalsa = codigo;
        }
        //medicina a punto inicial
        if (posicionActual == medicina) {
            cout << "Avanzas a la derecha y me encuentro en el punto incial" << endl;
            posicionFalsa = posicionInicial;

        }
        //charco rojo a punto final
        if (posicionActual == charcoRojo) {
            cout << "Avanzas a la derecha y me encuentro en el pazadizo" << endl;
            posicionFalsa = salida;
        }
    }
    void accionIzquierda() {
        //no accesibles
        if (posicionActual == medicina || posicionActual == charcoRojo || posicionActual == charcoVerde) {
            cout << "No puedo avanzar, hay pared" << endl;
        }
        //posicion inicial a medicina
        if (posicionActual == posicionInicial) {
            cout << "Avanzas a la izquierda y me encuentro con una medicina" << endl;
            posicionFalsa = medicina;
        }
        //posicion final a charco rojo
        if (posicionActual == salida) {
            cout << "Avanzas a la izquierda y me encuentro con un charco rojo" << endl;
            posicionFalsa = charcoRojo;
        }
        //caja a punto inicial
        if (posicionActual == caja) {
            cout << "Avanzas a la izquierda y me encuentro en el punto inicial" << endl;
            posicionFalsa = posicionInicial;

        }
        // codigo a punto final
        if (posicionActual == codigo) {
            cout << "Avanzas a la izquierda y me encuentro en el pazadizo" << endl;
            posicionFalsa = salida;
        }
    }




    

