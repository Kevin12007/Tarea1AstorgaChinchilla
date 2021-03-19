#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <string>
#include <chrono>
// Kevin Chinchilla, Andrey Astorga Bogantes.
using namespace std;
using namespace std::chrono;
// Se declara el array global, el cual contiene 100000 elementos
long int elementos[100000]={};
//La funcion potencia1, se encargar de calcular la potencia de los elementos ubicados en 
// las posiciones que van desde el 0 hasta 25000, sin tomar en cuenta el limite superior
void *potencia1(void *data)
{
    for(int j = 0; j<25000; j++){
    	elementos[j]=pow(elementos[j],2);
    }
    return 0;
}
//La funcion potencia1, se encargar de calcular la potencia de los elementos ubicados en 
// las posiciones que van desde el 25000 hasta 50000, sin tomar en cuenta el limite superior
void *potencia2(void *data)
{
    for(int j = 25000; j<50000; j++){
  	elementos[j]=pow(elementos[j],2);
    }
    return 0;
}
//La funcion potencia1, se encargar de calcular la potencia de los elementos ubicados en 
// las posiciones que van desde el 50000 hasta 75000, sin tomar en cuenta el limite superior
void *potencia3(void *data)
{
    for(int j = 50000; j<75000; j++){
  	elementos[j]=pow(elementos[j],2);
    }
    return 0;
}
//La funcion potencia1, se encargar de calcular la potencia de los elementos ubicados en 
// las posiciones que van desde el 75000 hasta 100000, sin tomar en cuenta el limite superior
void *potencia4(void *data)
{
    for(int j = 75000; j<100000; j++){
   	elementos[j]=pow(elementos[j],2);
    }
    return 0;
}

// La funcion rellenar se encarga de llenar el array de 1000000 elementos con los numeros del 0 hasta 99999
// Se llega hasta ese numero para respectar la cantidad de elementos. Cada posicion dentro del array representa el valor
// de dicha posicion.
int rellenar(){
    for(int i=0; i<100000; i++){
    	elementos[i]=i;
    }
    return 0;

}

int main(void)
{
    rellenar(); //llamado a la funcion,para llenar el array.
    // se declaran variables que se utilizan en el llamado a las funciones que se encargan de calcular las potencias
    char first[]="first";
    char second[]="second";
    char third[]="third";
    char fourth[]="fourth";
    pthread_t hilo1,hilo2,hilo3,hilo4;
      
    auto start = high_resolution_clock::now(); // variable que se utiliza para medir el tiempo de ejecucion, marca el inicio 
    //se crean los 4 hilos de ejecucion
    pthread_create(&hilo1, NULL, &potencia1, first);
    pthread_create(&hilo2, NULL, &potencia2, second);
    pthread_create(&hilo3, NULL, &potencia3, third);
    pthread_create(&hilo4, NULL, &potencia4, fourth); 
    // se unen los 4 hilos, al hilo principal
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);     
    pthread_join(hilo4, NULL);
    auto stop = high_resolution_clock::now(); // variable que se utiliza para medir el tiempo de ejecucion, marca el final
    auto duration = duration_cast<microseconds>(stop - start); // Se comparan el inicio y final para sacar el tiempo de ejecucion
    cout << "Tiempo de ejecucion en 4 hilos: "<<duration.count() << "us"<< endl; 
    return 0;
}