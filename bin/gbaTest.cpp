// gba.cpp : Defines the entry point for the application.
//

#include "Sdl3RepeatingTimer.h"
#include "Sdl3Display.h"
#include "Sdl3Controller.h"
#include "engine.hpp"


int main()
{
	Sdl3RepeatingTimer timer;
    Sdl3Display display;
    Sdl3Controller controller;
    Engine engine;

    display.initialise(1280, 720);
    controller.initialise();

    controller.connect([&display]() { display.togglePower(); });

    timer.m_timerDone.connect([&controller]() { controller.update(); });
    timer.m_timerDone.connect([&display, &engine]()
    {
        engine.frame(display);
    });

    timer.setIntervalHz(60);
    timer.start();

    npdib::SignalMain::get().run();

    return 0;
}