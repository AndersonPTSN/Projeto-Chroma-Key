#include "meufiltro.h"

void inicializarWidgetsMeuFiltro() {
	//widgets das opcoes de filtro
	botaocor = gtk_color_button_new();
	widgetControleNivel = 	gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 1, 0.05);
}

void adicionarWidgetsMeuFiltro(GtkWidget *container) {

	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);
	gtk_container_add(GTK_CONTAINER(container), vbox);
	gtk_container_add(GTK_CONTAINER(vbox), botaocor);
	gtk_container_add(GTK_CONTAINER(vbox), widgetControleNivel);
}

int comparar_cor(GdkRGBA pixel, GdkRGBA botao, float alcance){
	if(pixel.red <= botao.red+alcance && pixel.red >= botao.red-alcance && pixel.green <= botao.green+alcance && pixel.green >= botao.green-alcance && pixel.blue <= botao.blue+alcance && pixel.blue >= botao.blue-alcance){
		return 1;
	}
	else{
		return 0;
	}
}

Imagem meuFiltro(Imagem original, Imagem original2) {
	int i, j;
	int altura, largura;

	int variacaoh = 0;
	int variacaow = 0;

	GdkRGBA pixel, botao;
	Imagem destino = alocarImagem(original);
	Imagem fundo = alocarImagem(original);//original2


	altura = original.h;
	largura = original.w;

	for(j = 0; j < largura; j++){
		for(i = 0; i < altura; i++){
			if(j == original2.w + variacaow){
				variacaow = variacaow + original2.w;
			}
			if(i == original2.h + variacaoh){
				variacaoh = variacaoh + original2.h;
			}
			if(i == 0){
				variacaoh = 0;			
			}
			if(j == 0){
				variacaow = 0;
			}
			destino.m[i][j][0] = original.m[i][j][0];
			destino.m[i][j][1] = original.m[i][j][1];
			destino.m[i][j][2] = original.m[i][j][2];
			printf("i%i j%i i%i j%i\n",i,j,i - variacaoh,j - variacaow);
			fundo.m[i][j][0] = original2.m[i - variacaoh][j - variacaow][0];
			fundo.m[i][j][1] = original2.m[i - variacaoh][j - variacaow][1];
			fundo.m[i][j][2] = original2.m[i - variacaoh][j - variacaow][2];
		}
	}
	gtk_color_button_get_rgba(GTK_COLOR_BUTTON(botaocor), &botao);
	float alcance =  gtk_range_get_value(GTK_RANGE(widgetControleNivel));

		for(j = 0; j < largura; j++) {
			for(i = 0; i < altura; i++) {
				pixel.red = ((float)destino.m[i][j][0])/255;
				pixel.green = ((float)destino.m[i][j][1])/255;
				pixel.blue = ((float)destino.m[i][j][2])/255;
				printf("%d %d %d\n", destino.m[i][j][0], destino.m[i][j][1], destino.m[i][j][2]);
				if(comparar_cor(pixel, botao, alcance) == 1){
					destino.m[i][j][0] = fundo.m[i][j][0];
					destino.m[i][j][1] = fundo.m[i][j][1];
					destino.m[i][j][2] = fundo.m[i][j][2];
				}
			}
		}
	return destino;
}
