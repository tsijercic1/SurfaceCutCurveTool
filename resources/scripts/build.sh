printf "Compiling\n"
# shellcheck disable=SC2046
g++ src/main.cpp -o result/CurveCreator $(pkg-config gtkmm-3.0 --cflags --libs)
