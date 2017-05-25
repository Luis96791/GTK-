#ifndef BUTTON_H
#define BUTTON_H
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "Window.h"

typedef struct Button _Button;


struct Button
{
    GtkWidget* button_widget;
    GtkWidget* box_widget;
};

static void new_button(_Window* window, _Button* button, gchar* data);
static void send_data(_Window* window, gpointer data[]);

static void new_button(_Window* window, _Button* button, gchar* data)
{
    button->box_widget = gtk_hbox_new(FALSE, 30);
    gtk_container_add(GTK_CONTAINER(window->window_widget), button->box_widget);

    button->button_widget = gtk_button_new_with_label(data);
    gtk_box_pack_start(GTK_BOX(button->box_widget), button->button_widget, TRUE, TRUE, 0);

    gtk_widget_show(button->box_widget);
    gtk_widget_show(button->button_widget);
}

//static void send_data(_Window* window, gpointer data[])
//{
//    new_window_secondary(window, gtk_entry_get_text(GTK_ENTRY(data[0])),
//                gtk_entry_get_text(GTK_ENTRY(data[1])));
//}

#endif //BUTTON_H
