#include<iostream>
#include<vector>
#include<fstream>
#define MAX 256
using namespace std;




void intromensaje(vector<int> &mensaje){//Introducir tamano del mensaje y mensaje
int tamano =0;
	cout <<"introduzca tamano mensaje"<<endl;
	cin >> tamano;
	mensaje.resize(tamano);
	for(int i = 0; i<mensaje.size();i++){
		cout <<"introduzca mensaje "<<i+1<<endl;
		cin >> mensaje[i];
	}
		
}

void introsemilla(vector<int> &semilla){//introducir tamaño de clave y clave
int tamano =0;
	cout <<"introduzca tamano clave"<<endl;
	cin >> tamano;
	semilla.resize(tamano);
	for(int i = 0; i<semilla.size();i++){
		cout <<"introduzca clave "<<i+1<<endl;
		cin >> semilla[i];
	}
		
}

void KSA(vector<int>&K, vector<int>&S, vector<int>semilla){
	S.resize(MAX);//definimos tamaño de S y K a 256
	K.resize(MAX);
	for (int i = 0; i<S.size();i++){
		S[i]=i; //Rellenar S desde 0 a 255
		K[i]=semilla[i % semilla.size()];//rellenar K con la clave de 0 a 255
	}
	int j = 0;
	for (int i = 0; i<S.size(); i++){//desordenar el vector S
		j =(j + S[i] + K[i]) % MAX;
		swap(S[i],S[j]);
	}
}	
string binario(int n){//pasar el numero entero a binario
 string s;
int i = 0;
    string cad = "";
    if(n > 0){  
        while(n>0){  
           if(n%2 == 0)  
                cad = "0" + cad;  
            else  
                cad = "1" + cad;  
                n = n/2;  
        }  
        cout <<"Numero en binario: " <<cad;  
	//if (n !=0){
		
		//binario(n/2);
		//cout<< n % 2;
	//}
}
return cad;
}
void PRGA(vector<int>S,vector<int>mensaje,vector<int>&mensajecifrado){
	int i = 0;
	int j = 0;
	int t = 0;
	string cadena;
	string cadena1;
	string cadena2;
	for (int k = 0; k < mensaje.size(); k++){
		i =(i + 1) % MAX;
		j = (j + S[i]) % MAX;
		swap(S[i],S[j]);
		t = (S[i] + S[j]) % MAX;
		cadena = binario(S[t]);
		cadena1 = binario(mensaje[k]);
		cadena2 = cadena ^ cadena1;
		cout <<"hola soy la cadena"<<cadena;
		mensajecifrado.push_back(S[t] + mensaje[k]);//introducir en mensaje cifrado el mensaje con la clave
	}
}
		

void convertir (vector <int> mensajecifrado){
	cout <<"MENSAJE CIFRADO"<<endl;
	for (int i = 0 ;i <mensajecifrado.size(); i++){
		binario(mensajecifrado[i]);//llama a binario con el valor de mensaje cifrado
		cout <<endl;
		

	}
}				
int main(){

vector<int>mensaj;
vector <int>sem;
vector<int>mensajecifrado;
vector<int>K;
vector<int>S;

	intromensaje(mensaj);
	introsemilla(sem);
	KSA(K,S,sem);
	PRGA(S,mensaj,mensajecifrado);
	convertir(mensajecifrado);

	return 0;
}
