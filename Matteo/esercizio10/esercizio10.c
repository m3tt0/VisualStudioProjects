//Programma per la rappresentazione di immagini BitMap RGB.

#include <stdio.h>
#include <stdlib.h>

void freadImage(const char *nomeFile, int ****ImIn, int *NrowsIn, int *NcolsIn);
void modifyImage(int ***ImIn, int NrowsIn, int NcolsIn, int ****ImOut, int *NrowsOut, int *NcolsOut);
void fwriteImage(const char *nomeFile, int ***ImOut, int NrowsOut, int NcolsOut);
void freeImage(int ***Im);

int main()
{
	int ***ImIn, ***ImOut;
	int NrowsIn, NcolsIn, NcolsOut, NrowsOut;
	
	freadImage("ImIn.txt", &ImIn, &NrowsIn, &NcolsIn);
	modifyImage(ImIn, NrowsIn, NcolsIn, &ImOut, &NrowsOut, &NcolsOut);
	fwriteImage("ImOut.txt", ImOut, NrowsOut, NcolsOut);
	
	freeImage(ImIn);
	freeImage(ImOut);
}



#define FILE_READ_ERROR		10
#define FILE_WRITE_ERROR	15
#define MEMORY_ALLOC_ERROR	20
void gestisciErrore(int code)
{
	if (code == FILE_READ_ERROR) {
		fprintf(stderr, "Errore lettura file\n");
	}
	if (code == FILE_WRITE_ERROR) {
		fprintf(stderr, "Errore scrittura file\n");
	}
	if (code == MEMORY_ALLOC_ERROR) {
		fprintf(stderr, "Errore allocazione memoria\n");
	}
	
	exit(-1);
}

int **allocMatrix(int nrows, int ncols)
{
	int **M;
	int i;
	
	M = malloc(nrows*sizeof(int *));
	if (M == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	M[0] = malloc(nrows*ncols*sizeof(int));
	if (M[0] == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	for (i=1; i<nrows; i++) {
		M[i] = M[i-1] + ncols;
	}
	
	return M;
}

void freeMatrix(int **M)
{
	free(M[0]);
	free(M);
}

int ***allocImage(int nrows, int ncols)
{
	int ***Image;
	
	Image = (int ***) malloc(3*sizeof(int **));
	if (Image==NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	Image[0] = allocMatrix(nrows, ncols);
	Image[1] = allocMatrix(nrows, ncols);
	Image[2] = allocMatrix(nrows, ncols);
	
	return Image;
}

void freeImage(int ***Image)
{
	freeMatrix(Image[0]);
	freeMatrix(Image[1]);
	freeMatrix(Image[2]);
	free(Image);
}

void freadImage(const char *nomeFile, int ****ImIn, int *NrowsIn, int *NcolsIn)
{
	FILE *fp;
	int nrows, ncols;
	int ***Image;
	int i, j;
	int r, g, b;
	
	fp = fopen(nomeFile,"r");
	if (fp==NULL) {
		gestisciErrore(FILE_READ_ERROR);
	}
	
	fscanf(fp,"%d%d", &nrows, &ncols);
	Image = allocImage(nrows, ncols);
	
	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			fscanf(fp, "%d%d%d", &r, &g, &b);
			Image[0][i][j] = r;
			Image[1][i][j] = g;
			Image[2][i][j] = b;
		}
	}
	
	fclose(fp);
	
	*NrowsIn = nrows;
	*NcolsIn = ncols;
	*ImIn = Image;
}


void fwriteImage(const char *nomeFile, int ***Im, int Nrows, int Ncols)
{
	FILE *fp;
	int  r, g, b, i, j;
	
	fp = fopen(nomeFile,"w");
	if (fp == NULL) {
		gestisciErrore(FILE_WRITE_ERROR);
	}
	
	fprintf(fp,"%d %d", Nrows, Ncols);
	for (i=0; i<Nrows; i++) {
		for (j=0; j<Ncols; j++) {
			r = Im[0][i][j];
			g = Im[1][i][j];
			b = Im[2][i][j];
			fprintf(fp,"\n%d %d %d", r, g, b);
		}
	}
	
	fclose(fp);
}

void modifyImage(int ***ImIn, int NrowsIn, int NcolsIn, int ****ImOut, int *NrowsOut, int *NcolsOut)
{
	int ***Image;
	int nrows, ncols;
	int i, j, r, g, b, p;
	
	nrows = NrowsIn + 2;
	ncols = NcolsIn + 2;
	Image = allocImage(nrows, ncols);
	
	
	r = g = b = 255;
	//bordo superiore e inferiore
	for (j=0; j<ncols; j++) {
		Image[0][0][j] = r;
		Image[1][0][j] = g;
		Image[2][0][j] = b;
		
		Image[0][nrows-1][j] = r;
		Image[1][nrows-1][j] = g;
		Image[2][nrows-1][j] = b;
	}
	
	//bordo destro e sinistro
	for (i=1; i<nrows-1; i++) {
		Image[0][i][0] = r;
		Image[1][i][0] = g;
		Image[2][i][0] = b;
		
		Image[0][i][ncols-1] = r;
		Image[1][i][ncols-1] = g;
		Image[2][i][ncols-1] = b;
	}
	
	for (i=0; i<NrowsIn; i++) {
		for (j=0; j<NcolsIn; j++) {
			r = ImIn[0][i][j];
			g = ImIn[1][i][j];
			b = ImIn[2][i][j];
			
			p = (r + g + b)/3;
			
			Image[0][i+1][j+1] = p;
			Image[1][i+1][j+1] = p;
			Image[2][i+1][j+1] = p;
		}
	}
	
	*NrowsOut = nrows;
	*NcolsOut = ncols;
	*ImOut = Image;
}