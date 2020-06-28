#include <gtkmm-3.0/gtkmm.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void on_button_clicked(){
    std::cout << fs::current_path().string() << std::endl;
}

int main(int argc, char *argv[]) {
    auto app =
            Gtk::Application::create(argc, argv,
                                     "com.tsijercic1.scct");

    Glib::RefPtr<Gtk::Builder> builder;
    try {
        builder = Gtk::Builder::create_from_file("resources/glade/SurfaceCutCurveGUI.glade");
    } catch (const Glib::FileError &ex) {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 1;
    }
    catch (const Glib::MarkupError &ex) {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }
    catch (const Gtk::BuilderError &ex) {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }

    Gtk::Window *windowPtr;
    builder->get_widget("Root", windowPtr);
    Gtk::Button *buttonPtr;
    builder->get_widget("button", buttonPtr);
    buttonPtr->signal_clicked().connect(sigc::ptr_fun(&on_button_clicked));
    int result = app->run(*windowPtr);
    delete windowPtr;
    delete buttonPtr;

    return result;
}


