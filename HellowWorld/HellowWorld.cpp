#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;



int main()
{
	char palabra[200] = "calabaza";
	char adivinada[200] = "________";
	char letra;
	bool finish = false;
	bool adivino = false;
	int vidas = 5;

	while (!finish){
		adivino = false;
		cout << "\nAdivina la palabra, tienes " << vidas << " intentos:\n";
		for (int i = 0; i < 10; i++) {
			cout << adivinada[i] << " ";
		}
		cout << "\nAdivina una letra: ";
		try
		{
			letra = _getche(); //Solo toma un caracter
			//cin >> letra;
		}
		catch (const std::exception&)
		{
			cout << "Valor incorrecto\n";
		}

		for (int i = 0; i < 10; i++) {
			if (letra == adivinada[i]) {
				cout << "Ya intentaste esa letra.\n";
				adivino = true;
			}
			else if (letra == palabra[i]) {
				adivinada[i] = palabra[i];
				cout << "\nLetra adivinada!\n\n";
				adivino = true;
			}
		}

		if (!adivino) {
			vidas--;
			cout << "\nLetra no encontrada\n";
			if (vidas <= 0) {
				cout << "La palabra era ";
				cout << palabra;
				cout << "Has gastado todos tus intentos, perdiste.\n\n\n\n";
				finish = true;
			}
		}

		if (string(adivinada) == string(palabra)) {
			cout << "Correcto! La palabra es ";
			cout << palabra;
			cout << "\nHaz ganado!\n\n\n\n";
			finish = true;
		}

		////Limpia el buffer de memoria de cin
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	}
}
