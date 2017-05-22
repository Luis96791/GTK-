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

int main(int argc, char *argv[])
{
    GtkWidget* window;
    GtkWidget* button;
    GtkWidget* box1;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello Buttons!");
    gtk_window_set_position(window, 700);
    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    box1 = gtk_hbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);

    button = gtk_button_new_with_label("Acceder");
    g_signal_connect(button, "clicked", G_CALLBACK(callback), (gpointer) "Acceder");
    gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

    gtk_widget_show(button);
    gtk_widget_show(box1);
    gtk_widget_show(window);

    gtk_main();
}
