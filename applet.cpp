#include <gtk/gtk.h>
#include <gnome-panel/libpanel-applet/panel-applet.h>

static gboolean
hello_world_applet_start (PanelApplet *applet)
{
    GtkWidget *label;

    label = gtk_label_new ("Hello World");
    gtk_container_add (GTK_CONTAINER (applet), label);
    gtk_widget_show_all (GTK_WIDGET (applet));

    return TRUE;
}

static gboolean
hello_world_factory_callback (PanelApplet  *applet,
                              const gchar  *iid,
                              gpointer      data)
{
    gboolean retval = FALSE;

    if (g_strcmp0 (iid, "HelloWorldApplet") == 0)
        retval = hello_world_applet_start (applet);

    return retval;
}

PANEL_APPLET_OUT_PROCESS_FACTORY("HelloWorldFactory", PANEL_TYPE_APPLET, hello_world_factory_callback, NULL);
