#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Arbre {
        int a;
        int b;
        int c;
        char node;
        char nodeParent;
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
int trouverTailleNiveau(int n) {
        int tailleNiveau;
        if (n == 0) {
                tailleNiveau = 1;
        }
        else if (n == 1) {
                tailleNiveau = 3;
        }
        else {
                tailleNiveau = 3 * puissance(2, n - 1);
        }

        return tailleNiveau;
}

char rotationType(char nodeEnfant) {
        if (nodeEnfant == 'a') {
                nodeEnfant = 'b';
        }
        else if (nodeEnfant == 'b') {
                nodeEnfant = 'c';
        }
        else if (nodeEnfant == 'c') {
                nodeEnfant = 'a';
        }

        return nodeEnfant;
}
/*char assignerType(char type) {
        if (type =
}*/


int fonctionABC(int a, int b, int c) {
        FILE *fpt;
        fpt = fopen("Valeur1.csv", "w+");

        int aModif = 1;
        int bModif = 1;
        int cModif = 1; unsigned int p = 0;
        int n = 0;
        int tailleN = 0;
        int dp;
        int solutionTrouvee = 0;
        char nodeEnfant;

        struct Arbre* ptr;
        int size = 10000;
        ptr = malloc(size * sizeof *ptr);

        if (ptr == NULL) {
                printf("Il y a  eu un problème lors de l'allocation de la mémoire");
                solutionTrouvee = -1;

        }
        ptr[0].a = a;
        ptr[0].b = b;
        ptr[0].c = c;
        ptr[0].node = 'i';
        ptr[0].nodeParent = 'i';


        for (n = 0; solutionTrouvee == 0 && n < 8; n++) {
                nodeEnfant = 'a';
                dp = trouverTailleNiveau(n);
                tailleN += dp;

                for (p = p; p < tailleN; p++) {
                        if (!(nodeEnfant == ptr[p].node && ptr[p].node != ptr[p].nodeParent)) {

                                aModif = (2 * (ptr[p].b + ptr[p].c)) - ptr[p].a;
                                ptr[p + dp].a = aModif;
                                ptr[p + dp].b = ptr[p].b;
                                ptr[p + dp].c = ptr[p].c;
                                ptr[p + dp].node = 'a';
                                ptr[p + dp].nodeParent = ptr[p].node;
                                fprintf(fpt, "Node %d %c,a:%d b:%d c:%d\n", (p+dp), ptr[p+dp].node, ptr[p+dp].a, ptr[p+dp].b, ptr[p+dp].c);
                                dp++;
                        }
                        nodeEnfant = rotationType(nodeEnfant);


                        if (!(nodeEnfant == ptr[p].node && ptr[p].node != ptr[p].nodeParent)) {
                                bModif = (2 * (ptr[p].a + ptr[p].c)) - ptr[p].b;
                                ptr[p + dp].b = bModif;
                                ptr[p + dp].a = ptr[p].a;
                                ptr[p + dp].c = ptr[p].c;
                                ptr[p + dp].node = 'b';
                                ptr[p + dp].nodeParent = ptr[p].node;
                                fprintf(fpt, "Node %d %c,a:%d b:%d c:%d\n", (p+dp), ptr[p+dp].node, ptr[p+dp].a, ptr[p+dp].b, ptr[p+dp].c); 
                                dp++;
                        }
                        nodeEnfant = rotationType(nodeEnfant);

                        if (!(nodeEnfant == ptr[p].node && ptr[p].node != ptr[p].nodeParent)) {
                                cModif = (2 * (ptr[p].a + ptr[p].b)) - ptr[p].c;
                                ptr[p + dp].c = cModif;
                                ptr[p + dp].a = ptr[p].a;
                                ptr[p + dp].b = ptr[p].b;
                                ptr[p + dp].node = 'c';
                                ptr[p + dp].nodeParent = ptr[p].node;
                                fprintf(fpt, "Node %d %c,a:%d b:%d c:%d\n", (p+dp), ptr[p+dp].node, ptr[p+dp].a, ptr[p+dp].b, ptr[p+dp].c);
                        }
                        else {
                                dp--;
                        }
                        nodeEnfant = rotationType(nodeEnfant);

                        if (aModif == 0 || bModif == 0 || cModif == 0) {
                                solutionTrouvee = 1;
                        }
                }
                fprintf(fpt, "\n");
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

        for (k = 1; k < 19
        ; k++) {
                somme += fonctionAB(puissance(a, k), puissance(b, k));
        }

        return somme;
}*/

int main() {
        int i;

        printf("%d", fonctionABC(6, 423, 42));
        FILE *Test;
        Test = fopen("TestFonctionsTailleNiveau.csv", "w+");

        for (i = 0; i <= 15; i++) {
                fprintf(Test, "Taille niveau;%d\n", trouverTailleNiveau(i));
        }

        fclose(Test);
        return 0;

}
