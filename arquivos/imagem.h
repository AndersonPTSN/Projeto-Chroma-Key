#ifndef IMAGEM_H
#define IMAGEM_H

#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>

typedef struct Imagem {
	unsigned char ***m;
	int w;
	int h;
	int numCanais;
} Imagem;

Imagem img;

Imagem original, original2, resultado;
Imagem alocarImagem(Imagem referencia);
Imagem alocarImagem2(Imagem referencia);
void desalocarImagem(Imagem referencia);

#endif


