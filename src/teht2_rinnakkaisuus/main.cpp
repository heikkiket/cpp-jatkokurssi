#include <SFML/Graphics.hpp>

#include <cmath>
#include <iostream>
using namespace std;

constexpr auto COLS = 300;
constexpr auto ROWS = 300;
bool done = false;
constexpr auto MIN_STRENGTH = -4;
constexpr auto MAX_STRENGTH = 4;


//
// Military unit strengths (positive = AI unit,
// negative = player unit, 0 = empty).
//
double unit_map[COLS][ROWS];

//
// Influence unit_map.
//
double influence_map[COLS][ROWS];

sf::RenderWindow window(sf::VideoMode(300, 300), "Heikin hieno strategiapeli");

//
// Calculates distance between (c0, r0) and (c1, r1).
//
inline double distance(int c0, int r0, int c1, int r1)
{
	return sqrt((r0 - r1) * (r0 - r1) + (c0 - c1) * (c0 - c1));
}

void setPlayers() {
  // player units
  unit_map[36 - 1][90 - 1] = -2;
  unit_map[36 - 1][180 - 1] = -3;
  unit_map[54 - 1][36 - 1] = -4;
  unit_map[54 - 1][162 - 1] = -2;
  unit_map[90 - 1][72 - 1] = -2;
  unit_map[90 - 1][108 - 1] = -1;
  unit_map[108 - 1][126 - 1] = -1;

  // AI units
  unit_map[72 - 1][288 - 1] = 2;
  unit_map[126 - 1][234 - 1] = 2;
  unit_map[162 - 1][270 - 1] = 2;
  unit_map[216 - 1][198 - 1] = 2;
  unit_map[252 - 1][54 - 1] = 2;
}


void initMap()
{
  for(int c0{0}; c0 < COLS; c0++) {
    for (int r0{0}; r0 < ROWS; r0++) {
        unit_map[c0][r0] = {1};
      }
  }

  setPlayers();
}

inline double strengthInSq(int unitStrength, double distance)
{
  return unitStrength / (1 + distance);
}

int createColor(double strength) {
  double res = (strength - (MIN_STRENGTH)) / (MAX_STRENGTH - MIN_STRENGTH);
  return (int) round(255 * res);
}

void printMap() {

  window.clear();

  for (int c0{0}; c0 < COLS; c0++) {
    for (int r0{0}; r0 < ROWS; r0++) {
      sf::RectangleShape s(sf::Vector2f(10, 10));


      if (influence_map[c0][r0] == 0) {
        s.setFillColor(sf::Color(0, 0, 0));
      }
      else {
        int green = createColor(influence_map[c0][r0]);
        s.setFillColor(sf::Color(green, 127, 0));
      }

      s.setPosition(c0*10, r0*10);
      window.draw(s);
    }
  }

  window.display();
}

void calculateStregths()
{

    for (int c0{0}; c0 < COLS; c0++) {
      for (int r0{0}; r0 < ROWS; r0++) {

        influence_map[c0][r0] = {0};
        int unitStrength = unit_map[c0][r0];

        for (int c1{0}; c1 < COLS; c1++) {
          for (int r1{0}; r1 < ROWS; r1++) {

            double dist = distance(c0, r0, c1, r1);
            influence_map[c0][r0] = strengthInSq(unitStrength, dist);

          }
      }

      }
  }
}





int main()
{
    sf::RectangleShape shape(sf::Vector2f(10.f, 10.f));
    sf::RectangleShape shape2(sf::Vector2f(5.f, 5.f));
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);

    initMap();
    calculateStregths();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        printMap();

    }

    return 0;
}

int test() {

      //
      // TODO
      //
      // Calculate influence_map values from unit_map values.
      //

      printMap();
      return 0;
    }
