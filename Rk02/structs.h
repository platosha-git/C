#ifndef STRUCTS_H
#define STRUCTS_H

struct BMP
{
	struct info_header *head;
};

struct info_header
{
	int width;
	int height;

	int bitcount;
	int offsetbits;

	unsigned char *matr;
};

#endif