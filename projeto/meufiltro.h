#ifndef MEUFILTRO_H
#define MEUFILTRO_H

#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <time.h>
#include "imagem.h"


//declare aqui os seus widgets
GtkWidget *widgetControleNivel;
GtkWidget *widgetMisturarCanais;
GtkWidget *botaocor;
GtkWidget *label3, *label4;

Imagem meuFiltro(Imagem origem, Imagem origem2);
void inicializarWidgetsMeuFiltro();
void adicionarWidgetsMeuFiltro(GtkWidget *container);
int comparar_cor(GdkRGBA pixel, GdkRGBA botao, float alcance);


//esta funcao esta implementada em filtroGtk.c, nao precisa alterar
void funcaoAplicar(GtkWidget *widget, gpointer data);

#endif


