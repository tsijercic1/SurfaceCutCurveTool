# shellcheck disable=SC2046
g++ main.cpp -o ./result/CurveCreator $(pkg-config gtkmm-3.0 --cflags --libs)
cp ./resources/glade/* ./result/
