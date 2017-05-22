#include <stdlib.h>
#include <gtk/gtk.h>

static void callback(GtkWidget* widget, gpointer data)
{
    g_print("- Hello El boton - %s ha sido presionado\n", (gchar *)data);
}

static gboolean delete_event(GtkWidget* widget, GdkEvent* event, gpointer data)
{
    gtk_main_quit();

    return FALSE;
}

static void nuevo_boton(GtkWidget* window, gchar* data)
{
    GtkWidget* button;
    GtkWidget* box;

    box = gtk_hbox_new(FALSE, 30);
    gtk_container_add(GTK_CONTAINER(window), box);

    button = gtk_button_new_with_label(data);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    gtk_widget_show(box);
    gtk_widget_show(button);
}

static void nueva_ventana(GtkWidget* window, gchar* data, gint tamanio_ventana)
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), data);
    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
    gtk_container_border_width(GTK_CONTAINER(window), tamanio_ventana);

    nuevo_boton(window, "LUIS");

    gtk_widget_show(window);
}


int main(int argc, char *argv[])
{
    GtkWidget* window;

    gtk_init(&argc, &argv);
    nueva_ventana(window, "Mi Ventana", 240);

//    gtk_widget_show(window);

    gtk_main();
}

//https://developer.gnome.org/gtk-tutorial/stable/x344.html
