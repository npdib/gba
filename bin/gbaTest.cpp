// gba.cpp : Defines the entry point for the application.
//

#include "Sdl3RepeatingTimer.h"
#include "Sdl3Display.h"
#include "Sdl3Controller.h"
#include "Gba.hpp"


int main()
{
    Sdl3RepeatingTimer timer;
    Sdl3Display display;
    Sdl3Controller controller;
    Gba gba(display, controller, timer);

    gba.run();

    return 0;
}