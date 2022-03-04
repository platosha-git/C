#include <stdio.h>
#include <stdlib.h>

#include "size_pixels.h"
#include "structs.h"

void read_size_pixels(FILE *filename)
{
	struct BMP *bmp = (struct BMP *) malloc(sizeof(struct BMP));
	struct info_header *ihead = (struct info_header *) malloc(sizeof(struct info_header));
		
	fseek(filename, 18, SEEK_SET);
	fread(&(ihead->width), sizeof(int), 1, filename);

	fseek(filename, 22, SEEK_SET);
	fread(&(ihead->height), sizeof(int), 1, filename);

	fseek(filename, 28, SEEK_SET);
	fread(&(ihead->bitcount), sizeof(int), 1, filename);

	fseek(filename, 10, SEEK_SET);
	fread(&(ihead->offsetbits), sizeof(int), 1, filename);   	

	//create matr
	unsigned char *mas = (unsigned char *) malloc(3 * ihead->height * ihead->width);

	//read matr
	fseek(filename, ihead->offsetbits, SEEK_SET);
	for (int i = 0; i < ihead->height; i++)
	{
		for (int j = 0; j < ihead->width * (ihead->bitcount / 8); j++)
			fread(&(mas[i * j + j]), sizeof(char), 1, filename);
		fseek(filename, 1, SEEK_CUR);
	}

	ihead->matr = mas;
	bmp->head = ihead;

	printf("w = %d\nh = %d\n\n", ihead->width, ihead->height);
	printf("bitcount = %d\noffsetbits = %d\n\n", ihead->bitcount, ihead->offsetbits);

	//output matr
	for (int i = 0; i < ihead->height; i++)
	{
		for (int j = 0; j < ihead->width * (ihead->bitcount / 8); j++)
			printf("%d ", ihead->matr[i * j + j]);
		printf("\n");
	}

	//delete matr
	free(mas);
	free(ihead);
	free(bmp);
}