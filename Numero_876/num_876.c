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

int calculerVariableTemp(int temp, int nb1, int nb2) {
        return 2 * (nb1 + nb2) - temp;

}

int fonctionABC(int a, int b, int c) {
        struct Branche branche[100];
        branche[0].tempA = a;
        branche[0].tempB = b;
        branche[0].tempC = c;
        int differenceA;
        int differenceB;
        int differenceC;
        int i;
        int estRetour = 0;

        for (i = 1; branche[i].tempA != 0 || branche[i].tempB != 0 || branche[i].tempC != 0; i++) {
                if (estRetour == 0) {
                        
                        branche[i].a = branche[(i - 1)].tempA;
                        branche[i].b = branche[(i - 1)].tempB;
                        branche[i].c = branche[(i - 1)].tempC;

                        branche[i].tempA = calculerVariableTemp(branche[i].a, branche[i].b, branche[i].c);
                        branche[i].tempB = calculerVariableTemp(branche[i].a, branche[i].c, branche[i].b);
                        branche[i].tempC = calculerVariableTemp(branche[i].b, branche[i].c, branche[i].a);
                        
                        differenceA = abs(0 - branche[i].tempA);
                        differenceB = abs(0 - branche[i].tempB);
                        differenceC = abs(0 - branche[i].tempC);

                        if ((differenceA <= differenceB) && (differenceA <= differenceC)) {
                                branche[i].tempB = branche[i].b;
                                branche[i].tempC = branche[i].c;

                        }
                        else if ((differenceB <= differenceA) && (differenceB <= differenceC)) {
                                branche[i].tempA = branche[i].a;
                                branche[i].tempC = branche[i].c;

                        }
                        else if ((differenceC <= differenceB) && (differenceC <= differenceA)) {
                                branche[i].tempB = branche[i].b;
                                branche[i].tempA = branche[i].a;

                        }
                }

                
        } 

        printf("(%d, %d, %d, %d)", branche[0].tempA, branche[0].tempB, branche[0].tempC, i);

        return 0;

}

int main() {
       fonctionABC(34, 2, 31);

       return 0;

}

