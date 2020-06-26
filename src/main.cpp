#include <gtkmm-3.0/gtkmm.h>
#include <iostream>

int main(int argc, char *argv[]) {
    auto app =
            Gtk::Application::create(argc, argv,
                                     "com.tsijercic1.surfacecutcurvetool");

    Glib::RefPtr<Gtk::Builder> builder;
    try {
        builder = Gtk::Builder::create_from_file("result/SurfaceCutCurveGUI.glade");
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

    int result = app->run(*windowPtr);
    delete windowPtr;

    return result;
}
