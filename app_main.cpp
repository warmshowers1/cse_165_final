#include "App.h"


int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 600, 600, "Galaga Remake - Alex Woersching");

    app->run();
}
