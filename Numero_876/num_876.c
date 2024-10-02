#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Arbre {
        int a;
        int b;
        int c;
};

int puissance(int base, int exposant) {
        int reponse;
        
        if (exposant == 0) {
                reponse = 1;
        }
        else if (exposant == 1) {
                reponse = base;
        }
        else {
                reponse = base;
                for (exposant--; exposant > 0; exposant--) {
                        reponse = reponse * base;
                }
        }

        return reponse;
}


int fonctionABC(int a, int b, int c) {
        FILE *fpt;
        fpt = fopen("Valeur1.csv", "w+");

        unsigned long long int p = 0;
        int n = 0;
        int tailleN = 0;
        int dp;
        int solutionTrouvee = 0;

        struct Arbre* ptr;
        long int size1 = 64570080;
        int size = 10000;
        ptr = malloc(size * sizeof *ptr);

        if (ptr == NULL) {
                printf("Il y a  eu un problème lors de l'allocation de la mémoire");
                solutionTrouvee = -1;

        }
        ptr[0].a = a;
        ptr[0].b = b;
        ptr[0].c = c;


        for (n = 0; solutionTrouvee == 0 && n < 5; n++) {

                dp = puissance(3, n);
                tailleN += dp;

                for (p = p; p < tailleN; p++) {
                        ptr[p + dp].a = (2 * (ptr[p].b + ptr[p].c)) - ptr[p].a;
                        ptr[p + dp].b = ptr[p].b;
                        ptr[p + dp].c = ptr[p].c;
                        fprintf(fpt, "Node %d, a:%d, b:%d, c:%d\n", (p+dp), ptr[p+dp].a, ptr[p+dp].b, ptr[p+dp].c); 
                        dp++;

                        ptr[p + dp].b = (2 * (ptr[p].a + ptr[p].c)) - ptr[p].b;
                        ptr[p + dp].a = ptr[p].a;
                        ptr[p + dp].c = ptr[p].c;
                        fprintf(fpt, "Node %d, a:%d, b:%d, c:%d\n", (p+dp), ptr[p+dp].a, ptr[p+dp].b, ptr[p+dp].c); 
                        dp++;

                        ptr[p + dp].c = (2 * (ptr[p].a + ptr[p].b)) - ptr[p].c;
                        ptr[p + dp].a = ptr[p].a;
                        ptr[p + dp].b = ptr[p].b;
                        fprintf(fpt, "Node %d, a:%d, b:%d, c:%d\n", (p+dp), ptr[p+dp].a, ptr[p+dp].b, ptr[p+dp].c); 


                        if (ptr[p + dp - 2].a == 0 || ptr[p + dp - 1].b == 0 || ptr[p + dp].c == 0) {
                                solutionTrouvee = 1;
                        }
                }
        } 

        if (solutionTrouvee == 0) {
                n = 0;
        }

        fclose(fpt);

        free(ptr);

        return n;

}

int fonctionABFile(int a, int b) {
        FILE *fpt;
        fpt = fopen("Valeurs.csv", "w+");

        int resultat = 0;
        int c;

        for (c = 1; c < 100000; c++) {
                resultat = fonctionABC(a, b, c);
                if (resultat != 0) {
                        fprintf(fpt, "%d\n", c);
                }
        }

        fclose(fpt);

        return c;
}

int fonctionABFromFIle(int a, int b) {
        FILE *fpt;
        fpt = fopen("Valeurs.csv", "r");


}

/*int fonctionABExp(int a, int b) {
        int somme = 0;
        int k;

        for (k = 1; k < 19; k++) {
                somme += fonctionAB(puissance(a, k), puissance(b, k));
        }

        return somme;
}*/

int main() {
        printf("%d", fonctionABC(6, 10, 36));
        return 0;

}
