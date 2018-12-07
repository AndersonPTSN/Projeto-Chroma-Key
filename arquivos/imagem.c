#include "imagem.h"

Imagem alocarImagem(Imagem referencia) {
	int i, j;
	Imagem img;
	img.h = referencia.h;
	img.w = referencia.w;
	img.numCanais = referencia.numCanais;
	img.m = malloc(sizeof(guchar **)*img.h);
	for(i = 0; i < img.h; i++) {
		img.m[i] = malloc(sizeof(guchar *)*img.w);
		for(j = 0; j < img.w; j++)
			img.m[i][j] = malloc(sizeof(guchar)*img.numCanais);
	}
	return img;
}

Imagem alocarImagem2(Imagem referencia) {
	int i, j;
	Imagem img2;
	img2.h = referencia.h;
	img2.w = referencia.w;
	img2.numCanais = referencia.numCanais;
	img2.m = malloc(sizeof(guchar **)*img2.h);
	for(i = 0; i < img2.h; i++) {
		img2.m[i] = malloc(sizeof(guchar *)*img2.w);
		for(j = 0; j < img2.w; j++)
			img2.m[i][j] = malloc(sizeof(guchar)*img2.numCanais);
	}
	return img2;
}


void desalocarImagem(Imagem referencia) {
	for(int i = 0; i < referencia.h; i++) {
		for(int j = 0; j < referencia.w; j++) {
			free(referencia.m[i][j]);
		}
		free(referencia.m[i]);
	}
	free(referencia.m);
}

