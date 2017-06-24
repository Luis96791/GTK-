#ifndef WINDOW_H
#define WINDOW_H
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct Window _Window;

struct Window
{
    GtkWidget* window_widget;
    GdkEvent* event;
};

static void new_window(_Window* window, gchar* data, gint _size);
static void new_window_secondary(_Window* window, gpointer data[]);
static gboolean delete_event(_Window* window);
static void window_show(_Window* window);

static void new_window(_Window* window, gchar* data, gint _size)
{
    window->window_widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window->window_widget), data);
    g_signal_connect(GTK_OBJECT(window->window_widget), "delete-event", GTK_SIGNAL_FUNC(delete_event), NULL);
    gtk_container_border_width(GTK_CONTAINER(window->window_widget), _size);
    gtk_window_set_default_size(GTK_WINDOW(window->window_widget), 300, 200);

    g_print("DEUCE");
}

static gboolean delete_event(_Window* window)
{
    gtk_main_quit();
    return FALSE;
}

static void window_show(_Window* window)
{
    gtk_widget_show(window->window_widget);
}

static void new_window_secondary(_Window* window, gpointer data[])
{
    window->window_widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window->window_widget), gtk_entry_get_text(GTK_ENTRY(data[0])));
    gtk_container_border_width(GTK_CONTAINER(window->window_widget), gtk_entry_buffer_get_text(GTK_ENTRY(data[1])));
}

#endif // WINDOW_H
