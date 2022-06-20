/*
MATTEO ROCCO 
N86004039
*/
#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE   256
#define DIM         3

struct Tris;

int load_matches_from_file(char *In_fileName, struct Tris **head);
char the_winner_is (char **campo);
int match_score (char **campo);
int free_positions (char **campo);
void print_list (struct Tris *head);
void print_match (struct Tris *head);
void remove_tied (struct Tris **head);
char **alloc_matrix(int righe, int colonne);

void free_list(struct Tris **head);