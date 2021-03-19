#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <string>
#include <chrono>
// Andrey Astorga, Kevin Chinchilla 
using namespace std;
using namespace std::chrono;
// Variable global que contiene 100000 elementos 
long int elementos[100000]={};
//La funcion potencia se encarga de calcular la potencia de los elementos que se encuentran dentro del array, desde la poscion 0 
// hasta la posicion 99999, es decir de 100000 de elementos, se pueden imprimir los valores para verificar el comportamiento
void *potencia(void *data)
{
    for(int j = 0; j<100000; j++){
    	elementos[j]=pow(elementos[j],2);
    	//cout <<  elementos[j] << endl;
    }
    return 0;
}

// La funcion rellenar se encarga de llenar el array de 100000 elementos con los numeros del 0 hasta 99999
// Se llega hasta ese numero para respectar la cantidad de elementos. Cada posicion dentro del array tiene el mismo valor
// que dicha posicion.
int rellenar(){
    for(int i=0; i<100000; i++){
    	elementos[i]=i;
    }
    return 0;

}

int main(void)
{
    //llamado a la funcion,para llenar el array.
    rellenar(); 
    // variable que se utiliza en el llamado de la funcion potencia
    char zero[]="zero";
    
    auto start = high_resolution_clock::now();// variable que se utiliza para medir el tiempo de ejecucion, marca el inicio de este tiempo
    pthread_t hilo0;
    // se crea un unico hilo de ejecucion
    pthread_create(&hilo0, NULL, &potencia, zero);
    pthread_join(hilo0, NULL);
    // se une el hilo al hilo principal
    auto stop = high_resolution_clock::now(); // variable que se utiliza para medir el tiempo de ejecucion, marca el inicio de este tiempo
    
    auto duration = duration_cast<microseconds>(stop - start); // Se hace la diferencia del inicio y final para sacar el tiempo de ejecucion
    cout << "Tiempo de ejecucion en 1 hilo: "<<duration.count() << " us"<< endl; 
    
    return 0;
}