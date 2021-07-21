#include <stdlib.h>
#include <gtk/gtk.h>
 
int main(int argc, char *argv[])
{
  GtkWidget *mainWindow;
  GtkWidget *label;
 
  gtk_init(&argc, &argv);
 
  // Cria a janela, ajusta o tamanho, o título e
  // conecta o evento "destroy" à função gtk_main_quit.
  mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(mainWindow),
                              320, 200);
  gtk_window_set_title(GTK_WINDOW(mainWindow), 
                       "Hello App");
  gtk_signal_connect(GTK_OBJECT(mainWindow),
                     "destroy",
                     GTK_SIGNAL_FUNC(gtk_main_quit),
                     NULL);
 
  // Cria o label e ajusta o texto.
  label = gtk_label_new(NULL);
  gtk_label_set_text(GTK_LABEL(label), "Hello, world!");
 
  // Adiciona o label à janela.
  // Mostra a janela e seus filhos.
  gtk_container_add(GTK_CONTAINER(mainWindow), label);
  gtk_widget_show_all(mainWindow);
 
  // Loop principal.
  gtk_main();
 
  return EXIT_SUCCESS;
}