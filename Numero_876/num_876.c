#include <stdio.h>
#include <stdlib.h>

struct Branche {
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

int calculerParametre(int temp, int nb1, int nb2) {
        
        return 2 * (nb1 + nb2) - temp;

}

int fonctionABC(int a, int b, int c) {
        struct Branche branche[512];
        branche[0].a = a;
        branche[0].b = b;
        branche[0].c = c;
        int p;
        int n;
        int dp;
        int solutionTrouvee = 0;

        for (n = 1; solutionTrouvee == 0 && n < 5; n++) {

                dp = puissance(3, n);

                for (p = 1; puissance(3, n) + 1 > p; p += 3) {
                        branche[p + dp].a = calculerParametre(branche[p].a, branche[p].b, branche[p].c);
                        branche[p + dp].b = branche[p].b;
                        branche[p + dp].c = branche[p].c;
                        dp++;

                        branche[p + dp].b = calculerParametre(branche[p].b, branche[p].a, branche[p].c);
                        branche[p + dp].a = branche[p].a;
                        branche[p + dp].c = branche[p].c;
                        dp++;

                        branche[p + dp].c = calculerParametre(branche[p].c, branche[p].b, branche[p].a);
                        branche[p + dp].a = branche[p].a;
                        branche[p + dp].b = branche[p].b;

                        if (branche[p + dp - 2].a == 0 || branche[p + dp - 1].b == 0|| branche[p + dp].c == 0) {
                                solutionTrouvee = 1;
                        }
                } 
        } 

        return n + 1;

}

int main() {
        printf("\n%d\n\n", fonctionABC(6, 10, 35));

        return 0;

}
