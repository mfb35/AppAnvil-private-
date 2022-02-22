#include "about.h"
#include "../threads/command_caller.h"

#include <iostream>
#include <string>
#include <vector>

template<typename T_Widget> std::unique_ptr<T_Widget> About::get_widget(Glib::ustring name, const Glib::RefPtr<Gtk::Builder> &builder)
{
  T_Widget *raw_addr = nullptr;
  builder->get_widget<T_Widget>(name, raw_addr);
  return std::unique_ptr<T_Widget>(raw_addr);
}

About::About()
    : builder{Gtk::Builder::create_from_resource("./resources/about.glade")}, 
    a_box{About::get_widget<Gtk::Box>("a_box", builder)}
    {
        this->add(*a_box);
    }
    

