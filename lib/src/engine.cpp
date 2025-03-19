#include "engine.hpp"
#include <cstdlib>

void Engine::frame(IDisplay& display)
{
    const int16_t x = std::rand() % display.getWidth();
    const int16_t y = std::rand() % display.getHeight();
    const Colour c = ((std::rand() << 15) + std::rand()) << 2;

    display.setPixel(x, y, c);
    display.render();
}