#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

//Exercice 2

void exercice2() {
    double precision = 1e-5;
	double limit = calculLimit(precision);

	cout << fixed << setprecision(5);
	cout << "La limite approche: " << limit << endl;
}

double calculLimit(double precision) {
	double U0 = 1.0;
	double Unext = U0;

	for (int i = 0; ; i++) {
		Unext = sqrt(2 + U0);
		if (fabs(Unext - U0) < precision) {
			break;
		}
		U0 = Unext;
	}
	return Unext;
}


//exercice 4

struct Multiplication {
	int n1;
	int n2;
	int resultat;
};

int russianTable(int n1, int n2) {
	int somme = 0;
	while (n1 > 0) {
		if (n1 % 2 != 0) {
			somme += n2;
		}
		n1 /= 2;
		n2 *= 2;
	}
	return somme;
}

void exercice4() {
    Multiplication tests[3] =
	{
		{29, 37, 1073},
		{10, 10, 100},
		{40, 2, 20}
	};
	int passed = 0;
	for (int i = 0; i < 3; i++) {
		int multiplication = russianTable(tests[i].n1, tests[i].n2);
		if (multiplication == tests[i].resultat) {
			passed ++;
		}
	}
	cout << passed << "/3 tests passent." << endl;
}

// exercice 6
bool gagne(const char grille[3][3], char joueur) {
    for (int i = 0; i < 3; i++) {
        if (grille[i][0] == joueur && grille[i][1] == joueur && grille[i][2] == joueur) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (grille[0][j] == joueur && grille[1][j] == joueur && grille[2][j] == joueur) {
            return true;
        }
    }

    if (grille[0][0] == joueur && grille[1][1] == joueur && grille[2][2] == joueur) {
        return true;
    }

    if (grille[0][2] == joueur && grille[1][1] == joueur && grille[2][0] == joueur) {
        return true;
    }
    return false;
}


void exercice6() {

    string nomFichier;
	cout << "entrer le nom du fichier: ";
	cin >> nomFichier;

	ifstream fichier(string("src/")+nomFichier);
	if (!fichier) {
		cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
	}

	char grille[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fichier >> grille[i][j];

		}
	}
	fichier.close();

	if (gagne(grille, 'x')) {
		cout << "Le joueur 1 gagne." << endl;
	}

	else if (gagne(grille, 'o')) {
		cout << "Le joueur 2 gagne." << endl;
	}

	else {
		cout << "Egalite" << endl;
	}

}




int main() {
    exercice2();
    exercice4();
    exercice6();

}