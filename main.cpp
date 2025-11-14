#include <gtk/gtk.h>
#include <iostream>
#include <vector>

using namespace std;

struct olliWidget{
    GtkWidget* widget;
    int x, y;
};

vector<olliWidget> widgets;

// Callback für die Checkbox
static void on_toggled(GtkToggleButton* toggle, gpointer user_data) {
    bool active = gtk_toggle_button_get_active(toggle);
    cout << "Checkbox ist jetzt: " 
              << (active ? "AN" : "AUS") << std::endl;
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Eine Checkbox (GTK2)");
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 120);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Layout (für absolute Positionierung)
    GtkWidget* layout = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), layout);

    GtkWidget* checkbox = gtk_check_button_new_with_label("Checkbox");

    olliWidget tmp;
    tmp.widget = checkbox;
    tmp.x = tmp.y = 20;

    widgets.emplace_back(tmp);

    for(olliWidget widget : widgets){
        gtk_fixed_put(GTK_FIXED(layout), widget.widget, widget.x, widget.y);
        g_signal_connect(widget.widget, "toggled", G_CALLBACK(on_toggled), NULL);
    }

    // Eine Checkbox
    
/*
    // Positionieren an x=20, y=20
    gtk_fixed_put(GTK_FIXED(layout), checkbox, 20, 20);

    // Event verbinden
    g_signal_connect(checkbox, "toggled", G_CALLBACK(on_toggled), NULL);
*/
    gtk_widget_show_all(window);
    gtk_main();

}
