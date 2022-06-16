#define MAX_CHAR    20
struct Persona
{
    char Nome[MAX_CHAR];
    char Cognome[MAX_CHAR];
    float Peso;
    float Altezza;

    struct Persona *next;
};