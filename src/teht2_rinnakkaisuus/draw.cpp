#include "vars.cpp"

#include <SFML/Graphics.hpp>

#include <cmath>

constexpr auto sqr_size = 4;

sf::RenderWindow window(sf::VideoMode(COLS*sqr_size, ROWS*sqr_size), "Heikin hieno strategiapeli");

inline double normalize(double strength) {
  return (strength) / (MAX_STRENGTH - MIN_STRENGTH);
}

inline int makeRGB(double strength)
{
  return (int)round(255 * normalize(strength));
}

sf::Color createColor(double strength) {
  int green {0};
  int red {0};

  if (strength < 0) {
    strength *= -1;
    green = makeRGB(strength);
  } else if(strength > 0) {
    red = makeRGB(strength);
  }
  return sf::Color(red, green, 0);
}

void drawMap() {


  for (int c0{0}; c0 < COLS; c0++) {
    for (int r0{0}; r0 < ROWS; r0++) {

      sf::RectangleShape s(sf::Vector2f(sqr_size, sqr_size));

      if (influence_map[c0][r0] == 0) {
        s.setFillColor(sf::Color(0, 0, 0));
      } else {
        s.setFillColor(createColor(influence_map[c0][r0]));
      }

      s.setPosition(c0 * sqr_size, r0 * sqr_size);
      window.draw(s);
    }
  }

}

void drawUnits()
{
  for (int c0{0}; c0 < COLS; c0++) {
    for (int r0{0}; r0 < ROWS; r0++) {


      if (unit_map[c0][r0] != 0) {
        sf::RectangleShape s(sf::Vector2f(sqr_size, sqr_size));
        s.setFillColor(sf::Color(255, 0, 0));
        s.setPosition(c0 * sqr_size, r0 * sqr_size);
        window.draw(s);
      }

    }
  }
}

void showWindow() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    drawMap();
    // drawUnits();

    window.display();
  }
}
