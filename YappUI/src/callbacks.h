#include <gtk/gtk.h>


void
on_InputBox_activate                   (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_OkButton_button_press_event         (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
InputBox_grab_focus                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
InputBox_grab_focus                    (GtkWidget       *widget,
                                        gpointer         user_data);
