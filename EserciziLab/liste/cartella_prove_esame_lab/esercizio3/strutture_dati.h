#define MAX_CHAR    5

struct Classe 
{
    char Classe[MAX_CHAR];
    int Studenti;
    int Promossi;
    int Bocciati;
    int Rimandati;

    int flag;

    struct Classe *next;
};