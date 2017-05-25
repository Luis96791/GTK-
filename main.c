#include <stdlib.h>
#include <gtk/gtk.h>
#include "Window.h"
#include "Button.h"


struct Paramatro{
    gchar* cadena;
    gint numero;
};

void hello(gpointer data[])
{
    gchar* dir;

    dir = gtk_entry_get_text(GTK_ENTRY(data[0]));

    g_print("Hello World!\n");
    g_print(dir);
}

void destroy()
{
    gtk_main_quit();
}

int
main (int argc, char *argv[])
{
//    GtkWidget *window;
//    GtkWidget *button;
//
//    gtk_init (&argc, &argv);
//
//    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//    gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC(destroy), NULL);
//    gtk_container_border_width (GTK_CONTAINER (window), 100);
//
//    button = gtk_button_new_with_label ("Hello World");
//
//    gtk_signal_connect (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (hello), data);
//    gtk_signal_connect_object (GTK_OBJECT (button), "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy), GTK_OBJECT (window));
//    gtk_container_add (GTK_CONTAINER (window), button);
//
//    gtk_widget_show (button);
//    gtk_widget_show (window);


    _Window* window;
    _Window* window1;
//    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    new_window(&window, "Principal", 150);
    new_window(&window1, "Secundaria", 150);
//    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//    gtk_signal_connect (GTK_OBJECT (window), "destroy", GTK_SIGNAL_FUNC(destroy), NULL);
//    gtk_container_border_width (GTK_CONTAINER (window), 100);

    window_show(&window);
    window_show(&window1);

    gtk_main ();

    return 0;
}


//https://developer.gnome.org/gtk-tutorial/stable/x344.html
