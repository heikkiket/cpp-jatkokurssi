
#include <cmath>
#include <iostream>

#include "draw.cpp"
#include "vars.cpp"

using namespace std;


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
  unit_map[36 - 1][80 - 1] = -3;
  unit_map[54 - 1][36 - 1] = -4;
  unit_map[54 - 1][62 - 1] = -2;
  unit_map[90 - 1][72 - 1] = -2;
  unit_map[90 - 1][8 - 1] = -1;
  unit_map[8 - 1][26 - 1] = -1;

  // AI units
  unit_map[72 - 1][88 - 1] = 2;
  unit_map[26 - 1][34 - 1] = 2;
  unit_map[62 - 1][70 - 1] = 2;
  unit_map[16 - 1][98 - 1] = 2;
  unit_map[52 - 1][54 - 1] = 2;
}


void initMap()
{
  for(int c0{0}; c0 < COLS; c0++) {
    for (int r0{0}; r0 < ROWS; r0++) {
        unit_map[c0][r0] = {0};
      }
  }

  setPlayers();
}

inline double strengthInSq(int unitStrength, double distance)
{
  return unitStrength / (1 + distance);
}

inline void calculate_strength_component(int c0, int r0, int c1, int r1)
{
  int unitStrength = unit_map[c1][r1];
  double dist = distance(c0, r0, c1, r1);
  influence_map[c0][r0] += strengthInSq(unitStrength, dist);
}

void calculateStregths()
{

    for (int c0{0}; c0 < COLS; c0++) {
      for (int r0{0}; r0 < ROWS; r0++) {

        influence_map[c0][r0] = {0};

        for (int c1{0}; c1 < COLS; c1++) {
          for (int r1{0}; r1 < ROWS; r1++) {
            calculate_strength_component(c0, r0, c1, r1);
          }
      }

      }
  }
}







int test()
{

  calculate_strength_component(53, 161, 53, 157);

  cout << "Strength here: " << influence_map[53][61] << '\n';
  return 0;
}

int main() {
  initMap();

  // test();
  calculateStregths();

  showWindow();
  return 0;
}
