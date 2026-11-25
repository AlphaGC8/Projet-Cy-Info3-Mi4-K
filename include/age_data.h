#include <stdio.h>
#include <stdlib.h>

typedef struct Chainon{
        int age;
        int nb[2][3];
        struct Chainon* suivant;
} Chainon;

typedef Chainon* PChainon;   
