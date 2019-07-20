#include "engine/application.h"

int main(int argc, char** argv)
{
    melkor::application app(640, 480, "Last Square Standing", false);
    app.run();
    return 0;
}