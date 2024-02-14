//Facundo Pairazaman M5 - BLACKJACK
#include <iostream>
#include<stdlib.h>
#include <windows.h> // Para Sleep().
#include <sstream> // Para to_string(poder pasar un integer a string)
#include <clocale> // Para setlocale(así poder mostrar carácteres especiales por pantalla)
using namespace std;

//Variable para determinar si el juego ha acabado o no
bool endGame = false;

//Arrays de los nombres y valores de cada carta junto con un array para cada palo que ayudará a que no se repitan las cartas
string arrayNameCards[4] = {
	"Picas",
	"Rombos",
	"Tréboles",
	"Corazones"
};
int arrayValues[13] = { 1,2,3,4,5,6,7,8,9,10,10,10,10 };
bool arrayPicas[13] = { false,false,false,false,false,false,false,false,false,false,false,false,false };
bool arrayRombos[13] = { false,false,false,false,false,false,false,false,false,false,false,false,false };
bool arrayTreboles[13] = { false,false,false,false,false,false,false,false,false,false,false,false,false };
bool arrayCorazones[13] = { false,false,false,false,false,false,false,false,false,false,false,false,false };
//Las variables que podrán devolver números aleatorios para escoger diferentes array de los palos y cartas
int randomCard;
int randomValues;
//Variable que determinará cuando el bucle do while
bool randomArrayCardValue = false;
//Variable para determinar cuál carta es la escogida sin que haya un 0.
int cardValue;

//Variables que guardan la puntuación del jugador y croupier
int playerHand;
int croupierHand;

//Conteo de cuántas cartas de cada palo y totales del jugador que ya han salido en la partida
int countPicasCards = 0;
int countRombosCards = 0;
int countTrebolesCards = 0;
int countCorazonesCards = 0;
int totalPlayerCards = 0;
//Variable que servirá para guardar el nombre de la carta que le toque al jugador
string nameCardValue = "";

/*Función que permitirá que el usuario pueda escoger correctamente el valor de su AS
en el caso de que le toque esa carta*/
 //Variable que se utilizará para guardar la opción del valor para el AS del jugador
int asOption = 0;
void asCard() {
	cout << "Tu carta es un AS de " << arrayNameCards[randomCard] << "\n";
	cout << "¿Cuánto quieres que valga(1 u 11)?";
	cin >> asOption;
	while (asOption != 1 && asOption != 11)
	{
		cout << "Porfavor introduzca 1 u 11: ";
		cin >> asOption;
	}
	playerHand += asOption;
}
/*Función que dependiendo del valor en randomValues o cardValue que le toque al usuario le saldrán J, Q, K, AS,etc. sin que se repitan las cartas*/
void cardCases(){
	if (arrayValues[randomValues] == 1) {
		asCard();
	}
	else if (cardValue == 11) {
		playerHand += arrayValues[randomValues];
		nameCardValue = "J de " + arrayNameCards[randomCard];
		cout << "Tu carta es: " << nameCardValue << "\n";
	}
	else if (cardValue == 12) {
		playerHand += arrayValues[randomValues];
		nameCardValue = "Q de " + arrayNameCards[randomCard];
		cout << "Tu carta es: " << nameCardValue << "\n";
	}
	else if (cardValue == 13) {
		playerHand += arrayValues[randomValues];
		nameCardValue = "K de " + arrayNameCards[randomCard];
		cout << "Tu carta es: " << nameCardValue << "\n";
	}
	else {
		playerHand += arrayValues[randomValues];
		nameCardValue = to_string(cardValue) + " de " + arrayNameCards[randomCard];
		cout << "Tu carta es: " << nameCardValue << "\n";
	}
}

//Función que le dará al jugador una carta sin que está ya haya salido anteriormente
void playerCard() {
	randomCard = rand() % 4;
	switch (randomCard)
	{
	case 0:
		do
		{
			randomValues = rand () % 13;
			cardValue = randomValues + 1;
			if (arrayPicas[randomValues] == false) {
				arrayPicas[randomValues] = true;
				randomArrayCardValue = true;
				cardCases();
				countPicasCards+=1;
				totalPlayerCards+=1;
			}
			else if (countPicasCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en las Picas.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	case 1:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayRombos[randomValues] == false) {
				arrayRombos[randomValues] = true;
				randomArrayCardValue = true;
				cardCases();
				countRombosCards += 1;
				totalPlayerCards += 1;
			}
			else if (countRombosCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en los Rombos.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	case 2:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayTreboles[randomValues] == false) {
				arrayTreboles[randomValues] = true;
				randomArrayCardValue = true;
				cardCases();
				countTrebolesCards += 1;
				totalPlayerCards += 1;
			}
			else if (countTrebolesCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en los Treboles.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	case 3:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayCorazones[randomValues] == false) {
				arrayCorazones[randomValues] = true;
				randomArrayCardValue = true;
				cardCases();
				countCorazonesCards += 1;
				totalPlayerCards += 1;
			}
			else if (countCorazonesCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en los Corazones.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	default:
		break;
	}
}

//Función que determinará la puntuación del croupier cuando le aparezca un AS
void croupierAsCard() {
	cout << "La carta del croupier es un AS de " << arrayNameCards[randomCard] << "\n";
	if (croupierHand + 11 > 21)
	{
		croupierHand += 1;
	}
	else {
		croupierHand += 11;
	}
}
//Función parecida a la cardCases del jugador que funcionará para el croupier
void croupierCardCases() {
	if (arrayValues[randomValues] == 1) {
		croupierAsCard();
	}
	else if (cardValue == 11) {
		croupierHand += arrayValues[randomValues];
		nameCardValue = "J de " + arrayNameCards[randomCard];
		cout << "La carta del croupier es: " << nameCardValue << "\n";
	}
	else if (cardValue == 12) {
		croupierHand += arrayValues[randomValues];
		nameCardValue = "Q de " + arrayNameCards[randomCard];
		cout << "La carta del croupier es: " << nameCardValue << "\n";
	}
	else if (cardValue == 13) {
		croupierHand += arrayValues[randomValues];
		nameCardValue = "K de " + arrayNameCards[randomCard];
		cout << "La carta del croupier es: " << nameCardValue << "\n";
	}
	else {
		croupierHand += arrayValues[randomValues];
		nameCardValue = to_string(cardValue) + " de " + arrayNameCards[randomCard];
		cout << "La carta del croupier es: " << nameCardValue << "\n";
	}
}

//Función que le dará una carta sin ser repetida al croupier
void croupierCard() {
	randomCard = rand() % 4;
	switch (randomCard)
	{
	case 0:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayPicas[randomValues] == false) {
				arrayPicas[randomValues] = true;
				randomArrayCardValue = true;
				croupierCardCases();
				countPicasCards += 1;
			}
			else if (countPicasCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en las Picas.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	case 1:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayRombos[randomValues] == false) {
				arrayRombos[randomValues] = true;
				randomArrayCardValue = true;
				croupierCardCases();
				countRombosCards += 1;
			}
			else if (countRombosCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en los Rombos.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	case 2:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayTreboles[randomValues] == false) {
				arrayTreboles[randomValues] = true;
				randomArrayCardValue = true;
				croupierCardCases();
				countTrebolesCards += 1;
			}
			else if (countTrebolesCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en los Treboles.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	case 3:
		do
		{
			randomValues = rand() % 13;
			cardValue = randomValues + 1;
			if (arrayCorazones[randomValues] == false) {
				arrayCorazones[randomValues] = true;
				randomArrayCardValue = true;
				croupierCardCases();
				countCorazonesCards += 1;
			}
			else if (countCorazonesCards == 13)
			{
				cout << "Ya no quedan más cartas disponibles en los Corazones.\n";
				randomArrayCardValue = true;
			}
			else
			{
				randomArrayCardValue = false;
			}
		} while (randomArrayCardValue != true);
		break;
	default:
		break;
	}
};

//Función que determinará el resultado dependiendo de los puntos que tenga cada jugador en la partida
void gameResult() {
	if (croupierHand > 21)
	{
		cout << "¡Has ganado!. El croupier pierde porque tiene más de 21 puntos.\n";
		cout << "Fin del juego.";
		endGame = true;
	}
	else if (croupierHand > playerHand && croupierHand < 21)
	{
		cout << "El croupier gana, tiene más puntos que tú. Has perdido...\n";
		cout << "Fin del juego.";
		endGame = true;
	}
	else if (croupierHand == playerHand && playerHand == 21) {
		cout << "Dado a que ambos tenéis 21 puntos esta partida se queda en empate.\n";
		cout << "Fin del juego.";
		endGame = true;
	}
	else if (playerHand > 21){
		cout << "El croupier gana porque tienes más de 21 puntos. Has perdido...\n";
		cout << "Fin del juego.";
		endGame = true;
	}
	else if (croupierHand > playerHand && croupierHand == 21) {
		cout << "El croupier gana, tiene más puntos que tú. Has perdido...\n";
		cout << "Fin del juego.";
		endGame = true;
	}
}
int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios
	string anotherCard;;
	cout << "¡Bienvenido al BlackJack!\n";
	cout << "Precione enter para empezar la partida... ";
	cin.get();
	cout << "El croupier va a empezar a repartir las cartas...\n";
	while (totalPlayerCards != 2)
	{
		Sleep(1000);
		playerCard();
	}	
	cout << "Tu puntuación actual es de: " << playerHand << "\n";
	if (playerHand == 21)
	{
		while (croupierHand < playerHand) {
			croupierCard();
			if (croupierHand > playerHand) {
				gameResult();
			}
		}
	}
	else {
		Sleep(1000);
		croupierCard();
		Sleep(1000);
		while(endGame != true) {
			cout << "¿Quieres otra carta, o no quieres más para así poder plantarte con tu puntuación actual(si/no)? ";
			cin >> anotherCard;
			while (anotherCard != "si" && anotherCard != "no")
			{
				cout << "Porfavor introduzca 'si' o 'no': ";
				cin >> anotherCard;
			}
			if (anotherCard == "si")
			{
				playerCard();
				cout << "Tu puntuación actual es de: " << playerHand << "\n";
				if (playerHand == 21) {
					while (croupierHand < playerHand) {
						croupierCard();
						gameResult();
					}
				}
				else {
					gameResult();
				}
			}
			else if (anotherCard == "no")
			{
				while (endGame == false) {
					
						croupierCard();
						if (croupierHand > playerHand)
						{
							gameResult();

						}
					
				}
			}
		} 
	}
}