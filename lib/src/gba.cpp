#include "Gba.hpp"
#include <cstdlib>

#include "IController.h"
#include "IDisplay.h"
#include "IRepeatingTimer.h"

Gba::Gba(IDisplay& display, IController& controller, IRepeatingTimer& timer)
    : m_controller(controller)
      , m_display(display)
      , m_frameTimer(timer)
{
    m_display.initialise(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    m_controller.initialise();
    m_frameTimer.setIntervalHz(60);

    // make connections
    m_controller.connect(IController::Button::Start, [this]() { m_display.togglePower(); });
    m_controller.connect(IController::Button::Exit, stop);
    m_frameTimer.m_timerDone.connect([this]() { frame(); });
}

void Gba::run() const
{
    m_frameTimer.start();

    npdib::SignalMain::get().run(); // run main event loop
}

void Gba::stop()
{
    npdib::SignalMain::get().quit();
}

void Gba::frame() const
{
    m_controller.update();

    const int16_t x = std::rand() % m_display.getWidth();
    const int16_t y = std::rand() % m_display.getHeight();
    const Colour c = ((std::rand() << 15) + std::rand()) << 2;

    m_display.setPixel(x, y, c);
    m_display.render();
}
