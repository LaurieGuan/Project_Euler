#include <stdio.h>
#include <stdlib.h>

struct Branche {
        int a;
        int b;
        int c;
        int tempA;
        int tempB;
        int tempC;
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

int calculerVariableTemp(int temp, int nb1, int nb2) {
        
        return 2 * (nb1 + nb2) - temp;

}

int fonctionABC(int a, int b, int c) {
        struct Branche branche[364];
        branche[0].tempA = a;
        branche[0].tempB = b;
        branche[0].tempC = c;
        int i
        int n;
        int solutionTrouvee = 0;

        for (n = 0; solutionTrouvee == 1 || n < 5; n++) {

                for (i = puissance(3, n); i
                        branche[i].a = branche[(i - 1)].tempA;
                        branche[i].b = branche[(i - 1)].tempB;
                        branche[i].c = branche[(i - 1)].tempC;

                        branche[i].tempA = calculerVariableTemp(branche[i].a, branche[i].b, branche[i].c);
                        branche[i].tempB = calculerVariableTemp(branche[i].a, branche[i].c, branche[i].b);
                        branche[i].tempC = calculerVariableTemp(branche[i].b, branche[i].c, branche[i].a);
                
        } 

        printf("(%d, %d, %d, %d)", branche[0].tempA, branche[0].tempB, branche[0].tempC, i);

        return 0;

}

int main() {
        printf("%d\n", puissance(2, 8));
        return 0;

}

