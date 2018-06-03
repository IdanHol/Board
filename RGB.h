#pragma once

class RGB {
  public:
  uint8_t red = 255, green = 255, blue = 255;

  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};