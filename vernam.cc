#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <random>
#include <bitset>
#include <sstream>

// PRÁCTICA 1 - CIFRADO DE VERNAM

// Método clave aleatoria
std::vector<std::bitset<8>> clave_aleatoria(int tam, std::vector<std::bitset<8>> &vector_clave, std::vector<std::bitset<8>> &vector_final){
    srand(time(NULL)); // Se inicializa a un valor de tiempo de ejecución distintivo

    for(int i = 0; i<tam*8; ++i){
        vector_clave.push_back(std::bitset<8>(rand() % 127));
    }

    std::cout<<"Clave aleatoria: ";
    for(unsigned int i = 0; i<vector_final.size();i++)
        std::cout<<vector_clave[i];
    std::cout<<std::endl;

    return vector_clave;
}

// Método cifrado
void cifrado(std::string &mensaje_cif){

    std::vector<std::bitset<8>> vector_final, vector_clave;
    std::vector<int> vector_aux;
    int tam = strlen(mensaje_cif.c_str());
    std::random_device random;
    int opcion=1;

    // Conversión del mensaje introducido a binario 
    for(int i=0; i<tam; i++) {
        vector_final.push_back(std::bitset<8>(mensaje_cif.c_str()[i]));
    }

    std::cout<<"Mensaje original en binario: ";
    for(unsigned int i=0; i<vector_final.size();i++){
        std::cout<<vector_final[i];
    }
    std::cout<<std::endl;
    std::cout<<"Longitud del mensaje en binario: " <<tam*8<<std::endl;
    
    // Introducción de claves
    std::cout<<"\n¿Introducir clave aleatoria o por teclado?"<<std::endl;
    std::cout<<"1- Aleatoria."<<std::endl;
    std::cout<<"2- Por teclado."<<std::endl;
    std::cin >> opcion;
    if(opcion==1)
        clave_aleatoria(tam,vector_clave,vector_final);
    
    else{
        std::bitset<8> clave;
        std::string clave_des;
        std::cout<<"Clave: ";
        std::cin >> clave_des;
        
        std::istringstream cl(clave_des);
        for (unsigned int i = 0; i < clave_des.size()/8; i++){
            cl >> clave;
            vector_clave.push_back(clave);
        } 
    }
    


    // XOR
    for (unsigned int k = 0; k < vector_final.size(); ++k)
        vector_final[k] ^= vector_clave[k];

    std::cout<<"Mensaje cifrado en binario: ";
        for (unsigned int k = 0; k < vector_final.size(); ++k)
            std::cout<<vector_final[k];
    std::cout<<std::endl;

    // Mensaje final binario se convierte a  ASCII
    std::string m_cifrado;
    std::cout<< "Mensaje cifrado: ";
    for (unsigned int i=0; i < vector_final.size(); ++i){
        vector_aux.push_back(vector_final[i].to_ulong()); //to_ulong -> Convierte el resultado de la XOR a numero decimal ASCII
        if(vector_aux[i] >127 ){
            vector_aux[i] = vector_aux[i] % 126;
            m_cifrado = static_cast<char>(vector_aux[i]); //static_cast -> cada elemento del vector lo transforma en un char
            std::cout<< m_cifrado;

        }
        if (vector_aux[i]<33){
            vector_aux[i] += vector_aux[i] % 32;
            m_cifrado = static_cast<char>(vector_aux[i]);
            std::cout<< m_cifrado;
        }
        else{
            m_cifrado = static_cast<char>(vector_aux[i]);
            std::cout<< m_cifrado;
        }
        
    }
    std::cout<<std::endl;
}

void descifrado(std::string &mensaje_des){

    std::vector<std::bitset<8>> vector_final, vector_clave;
    std::vector<int> vector_aux;
    int tam = strlen(mensaje_des.c_str());
    std::random_device random;
    std::bitset<8> clave;
    std::string clave_des;
    int opcion=2;

    // -- Conversión del mensaje introducido a binario --
    for(int i=0; i<tam; i++) {
        vector_final.push_back(std::bitset<8>(mensaje_des.c_str()[i]));
    }

    std::cout<<"Mensaje cifrado en binario: ";
    for(unsigned int i=0; i<vector_final.size();i++){
        std::cout<<vector_final[i];
    }
    std::cout<<std::endl;
    std::cout<<"Longitud del mensaje en binario: " <<vector_final.size()*8<<std::endl;

    // -- Introducción de claves --
    std::cout<<"\n¿Introducir clave aleatoria o por teclado?"<<std::endl;
    std::cout<<"1- Aleatoria."<<std::endl;
    std::cout<<"2- Por teclado."<<std::endl;
    std::cin >> opcion;
    std::cout<<std::endl;
    if(opcion==1)
        clave_aleatoria(tam,vector_clave,vector_final);
    
    else{
        std::bitset<8> clave;
        std::string clave_des;
        std::cout<<"Clave: ";
        std::cin >> clave_des;
        
        std::istringstream cl(clave_des);
        for (unsigned int i = 0; i < clave_des.size()/8; i++){
            cl >> clave;
            vector_clave.push_back(clave);
        }
    } 

    // XOR
    for (unsigned int k = 0; k < vector_final.size(); ++k)
        vector_final[k] ^= vector_clave[k];

    std::cout<<"Mensaje original en binario: ";
        for (unsigned int k = 0; k < vector_final.size(); ++k)
            std::cout<<vector_final[k];
    std::cout<<std::endl;

    //Traducir el resultado de la XOR a caracteres ASCII
    std::string m_original;
    std::cout<< "Mensaje original: ";
    for (unsigned int i=0; i < vector_final.size(); ++i){
        vector_aux.push_back(vector_final[i].to_ulong()); //to_ulong -> Convierte el resultado de la XOR a numero decimal ASCII
        if(vector_aux[i] >127 ){
            vector_aux[i] = vector_aux[i] % 126;
            m_original = static_cast<char>(vector_aux[i]); //static_cast -> cada elemento del vector lo transforma en un char
            std::cout<< m_original;

        }
        if (vector_aux[i]<33){
            vector_aux[i] += vector_aux[i] % 32;
            m_original = static_cast<char>(vector_aux[i]);
            std::cout<< m_original;
        }
        else{
            m_original = static_cast<char>(vector_aux[i]); //static_cast -> cada elemento del vector lo transforma en un char
            std::cout<< m_original;
        }
        
    }
    std::cout<<std::endl;
}


int main (void){
  int x;
  std::string mensaje_cif;
  std::string mensaje_des;

  do {
    std::cout << "\n\nIntroduzca la opción que desee realizar: " << std::endl;
    std::cout << "[1] - Cifrar" << std::endl;
    std::cout << "[2] - Descifrar" << std::endl;
    std::cout << "En caso de querer salir, pulse cualquier otro número" << std::endl;
    std::cin >> x;

    
    switch(x){
        case 1: std::cout << "\nIntroduzca el mensaje que desea cifrar:" << std::endl;
                std::cin.ignore(); 
                std::cout << "Mensaje a cifrar: ";
                std::getline(std::cin,mensaje_cif);
                cifrado(mensaje_cif);
                break;
                  
        case 2: std::cout << "\nIntroduzca el mensaje que desea descifrar:"<< std::endl;
                std::cin.ignore();
                std::cout << "Mensaje a descifrar: ";
                std::getline(std::cin, mensaje_des);
                descifrado(mensaje_des);
                break;
        
        case 0: std::cout << "\nPrograma finalizado." << std::endl;
                break;

        default: break; 
    }
  } while (x != 0);         

  return 0;
}

