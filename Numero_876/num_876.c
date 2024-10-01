#include <stdio.h>
#include <stdlib.h>

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
        struct Arbre branche[100000];
        branche[0].a = a;
        branche[0].b = b;
        branche[0].c = c;
        int p = 0;
        int n = 0;
        int tailleN = 0;
        int dp;
        int solutionTrouvee = 0;

        for (n = 0; solutionTrouvee == 0 && n < 4; n++) {

                dp = puissance(3, n);
                tailleN += dp;

                for (p = p; p < tailleN; p++) {
                        branche[p + dp].a = (2 * (branche[p].b + branche[p].c)) - branche[p].a;
                        branche[p + dp].b = branche[p].b;
                        branche[p + dp].c = branche[p].c;
                        dp++;

                        branche[p + dp].b = (2 * (branche[p].a + branche[p].c)) - branche[p].b;
                        branche[p + dp].a = branche[p].a;
                        branche[p + dp].c = branche[p].c;
                        dp++;

                        branche[p + dp].c = (2 * (branche[p].a + branche[p].b)) - branche[p].c;
                        branche[p + dp].a = branche[p].a;
                        branche[p + dp].b = branche[p].b;


                        if (branche[p + dp - 2].a == 0 || branche[p + dp - 1].b == 0 || branche[p + dp].c == 0) {
                                solutionTrouvee = 1;
                        }
                }
        } 

        if (solutionTrouvee == 0) {
                n = 0;
        }

        return n;

}

int main() {
        printf("\n%d\n", fonctionABC(8, 2, 2));

        return 0;

}
