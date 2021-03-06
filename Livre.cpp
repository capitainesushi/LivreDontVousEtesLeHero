#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <random>

#include "Livre_fonctions.h"

/*
	Critère d'évaluation:

	- Affichage d'au moins 10 blocs: 11 au total.
		-Utilisation du std::cout : Oui
		-Fonctions différentes: Chaque bloc est une fonction (void ou int)
		-Tous les blocs sauf les fins effectuent un branchement if: Oui, sauf blocs "success" et "dead"
	- Bloc départ avec choix: Oui (Présence d'un std::cin) à l'intérieur de Livre_fonctions::départ()
	- Bloc d'échec: Oui (Bloc "dead()")
	- Bloc de succès: Oui (Bloc "success()")
	- Bloc de reconnection: 2 bloc différents: 
		- "coffre()" accédé par "serpent()" ou "troll()"
		- "porte()" accédé par "magicien()" ou "archer()"
	- Bloc à impact différé: Oui (Bloc "cle()" affectera la variable globale "cle" avec true ou false, et influencera un bloc ultérieur "porte()")
	- Bloc de hasard: Oui (Bloc "pieges()" utilise un lancer de dés à 3 faces)
	- Bloc de choix: Oui (Pas mal tous...)
	- Bloc de conséquence: Oui (Bloc "porte()" est influencé par la réponse obtenue au bloc "cle()")
*/


// Variables globales
bool cle = false;


using namespace std;

int Livre_fonctions::dead()
{
	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Vous êtes mort!" << endl;
	cout << "Partie terminée!" << endl << endl;
	exit(0); 
}

int Livre_fonctions::success()
{
	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Vous avez vaincu le monstre du donjon... " << endl;
	cout << "Les villageois vous sont éternellement reconnaissants et vous offre une grande somme d'argent en guise de récompense." << endl;
	cout << "Partie terminée!" << endl << endl;
	
	exit(0);
}

void Livre_fonctions::boss()
{
	string choix;

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Vous pénétrez dans la dernière salle du donjon, et apercevez le monstre qui attaque sauvagement votre village." << endl;
	cout << "En vous préparant à le combattre, vous analysez votre adversaire." << endl;
	cout << "Ses griffes acérées semblent parfaites pour le combat direct, et son armure protège sa tête et son ventre." << endl;
	cout << "Vous remarquez ensuite ses petites jambes, et qu'il semble se déplacer lentement..." << endl;


	do
	{
		cout << "Quelle action entreprendrez-vous contre la bête?" << endl;
		cout << "1: Vous engagez le combat rapproché et tentez de vaincre ses griffes" << endl;
		cout << "2: Vous tentez de percer son armure avec votre lance" << endl;
		cout << "3: Vous courez sur le côté, et tentez de l'attaquer par le dos" << endl;
		cin >> choix;

		if (choix == "1")
		{
			cout << "À peine arrivé à portée du monstre, il vous déchiquete en plusieurs morceaux." << endl;
			dead();
		}

		else if (choix == "2")
		{
			cout << "La lance touche la cible, mais casse en deux sous la défense impénétrable de son armure. Le monstre charge sur vous et vous lance au mur, faisant de vous sa crêpe pour demain matin." << endl;
			success();
		}

		else if (choix == "3")
		{
			cout << "Arrivé à dos de votre adversaire, vous apercevez qu'il est sans défense. Vous plantez votre épée directement dans son dos, et le monstre s'écroule au sol." << endl;
			success();
		}

		else
			cout << "Choix invalide" << endl;


	} while (choix != "1" && choix != "2" && choix != "3");
}

void Livre_fonctions::porte()
{
	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Vous avancez dans la prochaine salle, et constatez qu'elle est complètement vide." << endl;
	cout << "De l'autre côté se trouve un gigantesque porte craquée. Vous poussez sur la porte mais rien ne se passe... " << endl;
	cout << "C'est à ce moment que vous remarquez une serrure sur la porte, et vous vous demandez quelle clé peut bien l'ouvrir..." << endl;

	if (cle == true)
	{
		cout << "Vous vous rappellez de la clé que vous avez obtenu du gardien du coffre." << endl;
		cout << "Vous l'insérez dans la serrure, et poussez sur la porte, qui s'ouvre immédiatement..." << endl;
		boss();
	}
	if (cle == false)
	{
		cout << "Vous vous creusez les méninges et tentez de trouver une solution, sans succès." << endl;
		cout << "Vous vous rappellez ensuite de la salle du coffre, où le gardien protégeait un bien précieux, et réalisez qu'il s'agissait fort probablement de la clé..." << endl;
		cout << "Sans aucun moyen de sortir, vous acceptez lentement votre sort et attendez que la mort vienne vous chercher." << endl;
		dead();
	}
}

void Livre_fonctions::archer()
{
	string choix;

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Des archers guettent une porte derrière eux. Ils n'ont pas l'air de vouloir vous laisser passer..." << endl;

	do
	{
		cout << "Que voulez-vous faire?" << endl;
		cout << "1: Vous sortez votre épée et tentez de les attaquer au corps à corps." << endl;
		cout << "2: Vous sortez votre lance et tentez de les attaquer à distance." << endl;
		cin >> choix;

		if (choix == "1")
		{
			cout << "En restant en mouvement, vous bloquez plusieurs flèches et arrivez au corps à corps. Vous ne faites qu'une bouchée de leurs arcs et avancez à la prochaine salle" << endl;
			porte();
		}

		else if (choix == "2")
		{
			cout << "Vous tentez de lancer votre lance, mais ratez votre cible. Les archers se font un grand plaisir de vous faire de nombreux trous partout sur votre corps." << endl;
			dead();
		}

		else
		{
			cout << "Choix invalide" << endl;
		}

	} while (choix != "1" && choix != "2");

}

void Livre_fonctions::magicien()
{
	string choix;

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Arrivé à la prochaine salle, un magicien vous attend. Sans plus tarder, il se met à vous lancer des projectiles magiques" << endl;

	do
	{
		cout << "Que voulez-vous faire?" << endl;
		cout << "1: Vous sortez votre lance et tentez de l'attaquer à distance." << endl;
		cout << "2: Vous sortez votre épée et tentez de l'attaquer au corps à corps." << endl;
		cin >> choix;

		if (choix == "1")
		{
			cout << "Après avoir esquivé son projectile, vous lancez le vôtre, qui le touche de plein fouet. Le magicien s'écroule au sol. Vous avancez vers la prochaine salle" << endl;
			porte();
		}

		else if (choix == "2")
		{
			cout << "Vous avez à peine le temps de vous avancer que le magicien vous frappe droit au coeur avec une boule de feu. Vous prenez en feu et devenez un paquet de cendres." << endl;
			dead();
		}
		else
		{
			cout << "Choix invalide" << endl;
		}

	} while (choix != "1" && choix != "2");


}

void Livre_fonctions::pieges()
{

	int diceresult = 0;
	

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "Vous arrivez ensuite dans une salle ayant une plateforme au centre. En vous approchant, vous apercevez un bouton sur celle-ci." << endl;
	cout << "Ce bouton active un système qui donnera un chiffre entre 1 et 3 aléatoirement. " << endl;
	cout << "Vous décidez d'appuyer sur le bouton... " << endl;

	std::random_device départ;
	std::mt19937 hasard(départ());
	std::uniform_int_distribution<> d3(1, 3);
	std::cout << "Un chiffre au hasard apparaît: " << std::endl;

	diceresult = d3(hasard);

	cout << diceresult << endl;

	if (diceresult == 1)
	{
		cout << "Malheureusement, des pics de métal sortent du sol, et vous transperce violement, et devenez une belle brochette." << endl;
		dead();
	}

	else if (diceresult == 2)
	{
		cout << "Une porte à votre gauche ouvre, menant à une prochaine salle. Vous poursuivez donc votre périple." << endl;
		magicien();

	}
	else // (diceresult == 3)
	{
		cout << "Une porte à votre droite ouvre, menant à une prochaine salle. Vous poursuivez donc votre périple." << endl;
		archer();
	}

}

void Livre_fonctions::coffre()
{

	string choix;

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "À la prochaine salle, vous apercevez un coffre, ainsi qu'un gardien protégeant son trésor." << endl;
	cout << "Il vous accueille et vous dit que vous pouvez obtenir son trésor si vous répondez correctement à sa question." << endl;
	cout << "La question: Qui est le meilleur professeur en programmation et intégration de jeux vidéo au Collège Bart?" << endl;


	do
	{
		cout << "Quelle est votre réponse? " << endl;
		cout << "1: Gabriel Lefebvre" << endl;
		cout << "2: Philippe Gourdeau-Bédard" << endl;
		cout << "3: François Guimond" << endl;

		cin >> choix;

		if (choix == "1" || choix == "2")
		{
			cout << "C'est une mauvaise réponse. Vous pouvez continuer, mais vous n'obtenez pas ce qui se cache dans ce coffre." << endl;
			cle = false;
		}

		else if (choix == "3")
		{
			cout << "C'est une bonne réponse! Vous obtenez cette clé du donjon, en espérant qu'elle vous servira dans le futur." << endl;
			cle = true;
		}

		else
		{
			cout << "Choix invalide" << endl;
		}

	} while (choix != "1" && choix != "2" && choix != "3");

	Livre_fonctions::pieges();

}

void Livre_fonctions::serpent()
{
	string choix;

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "En ouvrant la porte, vous vous arrêtez brusquement, car un précipice rempli de serpents se trouve devant vous, " << endl;
	cout << "Comment allez-vous traverser?" << endl;

	do
	{
		cout << "Entrez votre choix: " << endl; 
		cout << "1: Vous vous laissez tomber dans le précipice et affrontez les serpents" << endl;
		cout << "2: Vous tentez de sauter par dessus" << endl;
		cin >> choix;

		if (choix == "1")
		{
			cout << "En tombant, vous sortez votre épée de son étui, et affrontez les serpents... pendant une dizaine de secondes avant de vous faire dévorer cru, puisqu'ils sont une bonne centaine." << endl;
			dead();
		}
		else if (choix == "2")
		{
			cout << "En prenant un élan, vous tentez de sauter. Vous y arrivez de peu, ayant dû vous accrocher à la paroi de l'autre côté du précipice. Vous continuez votre route" << endl;
			coffre();
		}
		else
		{
			cout << "Choix invalide" << endl;
		}

	} while (choix != "1" && choix != "2");
	

}

void Livre_fonctions::troll()
{
	string choix;

	cout << endl << endl;  // fait de l'espace entre les paragraphes à l'affichage
	cout << "En ouvrant la porte, un énorme troll charge sur vous." << endl;
	cout << "Comment allez-vous combattre le troll?" << endl;

	do
	{
		cout << "Entrez votre choix: " << endl;
		cout << "1: Vous sortez votre épée et tentez de bloquer son attaque." << endl;
		cout << "2: Vous esquivez son attaque" << endl;
		cout << "3: Vous tentez de sauter par dessus le troll" << endl;
		cin >> choix;

		if (choix == "1" || choix == "3")
		{
			cout << "Étant beaucoup plus puissant que vous, le troll vous attrape et vous écrase d'un seul coup." << endl;
			dead();
		}

		else if (choix == "2")
		{
			cout << "En courant sur le côté, le troll ne peut s'arrêter, frappe le mur derrière vous et tombe inconscient. Vous poursuivez votre chemin. " << endl;
			coffre();
		}

		else
		{
			cout << "Choix invalide" << endl;
		}

	} while (choix != "1" && choix != "2" && choix != "3");


}

void Livre_fonctions::depart()
{
	string choix;

	cout << "Vous vous réveillez en pleine nuit par des cris et vacarmes dehors. Vous apercevez par la fenêtre qu'un énorme monstre attaque votre village, et le réduit en cendres." << endl;
	cout << "Courageux, vous voudriez bien l'affronter, mais vous n'irez pas bien loin avec un pyjama. Vous décidez donc de vous cacher..." << endl;
	cout << "Le lendemain, les villageois survivants sont en pleurs, et vous prenez la décision d'aller vaincre la créature, avant qu'elle ne fasse d'autres victimes." << endl;
	cout << "Les villageois admirent votre courage, et vous offre une épée et une lance. Avec les directives d'un témoin, vous vous dirigez vers le donjon du monstre." << endl;
	cout << "En arrivant à l'entrée, vous apercevez deux portes identiques, toutes deux menant au donjon. Vous devez décider laquelle prendre." << endl << endl;


	do
	{
		cout << "Entrez votre choix: " << endl;
		cout << "1: Porte de gauche" << endl;
		cout << "2: Porte de droite" << endl;
		cin >> choix;

		if (choix == "1")
			troll();

		else if (choix == "2")
			serpent();

		else
			cout << "Choix invalide" << endl;

	} while (choix != "1" && choix != "2");


} 



int main()
{
	
	SetConsoleOutputCP(CP_UTF8);
	
	HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
	ShowWindow(consoleWindow, SW_MAXIMIZE);  // This mimics clicking on its' maximize button
	
	Livre_fonctions::depart();

	return 0;
}
 