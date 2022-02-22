#ifndef TABS_ABOUT_H
#define TABS_ABOUT_H

#include "status.h"

#include <gtkmm/builder.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/enums.h>
#include <gtkmm/filechooser.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/grid.h>
#include <gtkmm/liststore.h>
#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/searchentry.h>
#include <gtkmm/textview.h>
#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/treeview.h>
#include <gtkmm/treeviewcolumn.h>
#include <memory>
#include <regex>
#include <string>
#include <vector>

class About : public Gtk::ScrolledWindow
{
public:
  About();

private:
  // GUI Builder to parse UI from xml file
  Glib::RefPtr<Gtk::Builder> builder;

  //container Widgets
  std::unique_ptr<Gtk::Box> a_box;
  std::unique_ptr<Gtk::Label> a_label;

  const std::vector<std::string> col_names{"Profile", "Status"};
  std::shared_ptr<StatusColumnRecord> col_record;

  template<typename T_Widget> static std::unique_ptr<T_Widget> get_widget(Glib::ustring name, const Glib::RefPtr<Gtk::Builder> &builder);
};

#endif // TABS_ABOUT_H
