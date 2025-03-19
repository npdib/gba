#pragma once
#include <cstdint>
#include <memory>

class IRepeatingTimer;
class IDisplay;
class IController;

class Gba
{
public:
    Gba(IDisplay& display, IController& controller, IRepeatingTimer& timer);

    void run() const;
    static void stop();
    void frame() const;

private:
    static constexpr uint16_t DISPLAY_WIDTH = 1280;
    static constexpr uint16_t DISPLAY_HEIGHT = 720;

    IController& m_controller;
    IDisplay& m_display;
    IRepeatingTimer& m_frameTimer;
};
