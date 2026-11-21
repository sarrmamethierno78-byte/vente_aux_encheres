
#include <stdio.h>
#include <stdlib.h>

/*
 * Affiche un collier composé de plusieurs maillons.
 *
 * Paramètre :
 * p : nombre de maillons à afficher.
 */
void collier(int p){
    for (int i = 1; i < p; i++){
        printf("--o");
    }
    // Affiche le dernier maillon avec les extrémités du collier.
    printf("--o--");
}

/*
 * Compte le nombre de zéros consécutifs à la fin d'un entier.
 *
 * Paramètre :
 * n : entier dont on veut examiner les derniers chiffres.
 *
 * Retour :
 * Le nombre de zéros à la fin de l'entier.
 */
int nombre_zeros_fin(int n) {
    // Cas particulier : zéro est considéré comme ayant un zéro final.
    if(n == 0){
        return 1;
    }

    int c = 0;

    // Tant que le dernier chiffre est un zéro, on incrémente le compteur.
    while(n % 10 == 0){
        c++;
        n = n / 10;
    }

    return c;
}

/*
 * Demande à un utilisateur de saisir une offre respectant
 * un nombre minimal de zéros à la fin.
 *
 * Paramètre :
 * nb : nombre minimal de zéros exigé.
 *
 * Retour :
 * L'offre saisie par l'utilisateur.
 */
int offre_utilisateur(int nb){
    int x;

    printf(" Donnez un prix avec au moins %d zéros à la fin ", nb);
    scanf("%d", &x);

    // Vérifie si l'offre respecte la condition imposée.
    int y = nombre_zeros_fin(x);

    // Redemande une offre tant que le nombre de zéros est insuffisant.
    while(y < nb){
        printf(" Vous rigolez j'espere ce nombre n'a pas du tout %d zeros à la fin recommencez ", nb);
        scanf("%d", &x);
        y = nombre_zeros_fin(x);
    }

    return x;
}

/*
 * Compare deux offres afin de déterminer si la seconde
 * est supérieure à la première.
 *
 * Paramètres :
 * x : première offre.
 * y : deuxième offre.
 *
 * Retour :
 * 1 si y est supérieur à x, 0 sinon.
 */
int verifie_victoire(int x, int y){
    if (y < x){
        return 1;
    }
    return 0;
}

/*
 * Organise une vente aux enchères pour un collier.
 *
 * Paramètre :
 * p : nombre de maillons du collier et nombre minimal
 * de zéros exigés à la fin des offres.
 *
 * Retour :
 * Le numéro du joueur gagnant (1 ou 2), ou 0 si aucun
 * gagnant n'a été désigné.
 */
int mise_enchere_collier(int p){
    int x;
    int y;
    int z = 0;

    // Présentation de la vente aux enchères et affichage du collier.
    printf(" Bienvenue a cette vente aux enchéres ces deux chanceux vont concourir pour ce collier si precieux que voici :\n");
    collier(p);

    printf("\n Bien commencons , pour des raisons de sécurité les acheteurs seront baptisés 1 et 2.\n");

    // Première offre du joueur 1.
    printf(" Au tour de l'acheteur 1 proposez une offre. ");
    x = offre_utilisateur(p);

    // Première offre du joueur 2.
    printf(" Au tour de l'acheteur 2 proposez une offre. ");
    y = offre_utilisateur(p);

    // Compare les deux premières offres.
    if (verifie_victoire(x, y) == 1){
        z = 1;
        printf(" Le joueur 1 a remporté le collier");
    }

    int i = 0;

    // Organise jusqu'à dix tours supplémentaires.
    while(i < 10){

        // Le joueur 1 propose une nouvelle offre.
        printf(" Au tour de l'acheteur 1 proposez une offre. ");
        x = offre_utilisateur(p);

        // Vérifie si l'offre du joueur 1 permet de remporter l'enchère.
        if (verifie_victoire(y, x) == 1){
            z = 2;
            printf(" Le joueur 1 a remporté le collier");
            break;
        }

        // Le joueur 2 propose ensuite une nouvelle offre.
        printf(" Au tour de l'acheteur 2. ");
        y = offre_utilisateur(p);

        // Vérifie si l'offre du joueur 2 permet de remporter l'enchère.
        if (verifie_victoire(x, y) == 1){
            z = 1;
            printf(" Le joueur 1 a remporté le collier\n");
            break;
        }

        i++;
    }

    return z;
}

/*
 * Point d'entrée du programme.
 * Lance une vente aux enchères pour un collier de 6 maillons.
 */
int main() {
    printf("%d", mise_enchere_collier(6));

    return EXIT_SUCCESS;
}
