#include <cmath>
#include <iostream>
#include <chrono>

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

  // Small test
  // unit_map[10 - 1][20 - 1] = -2;
  // unit_map[20 - 1][30 - 1] = 2;

  // // player units
  unit_map[36 - 1][90 - 1] = -2;
  unit_map[36 - 1][80 - 1] = -3;
  unit_map[53 - 1][36 - 1] = -4;
  unit_map[54 - 1][62 - 1] = -2;
  unit_map[97 - 1][72 - 1] = -2;
  unit_map[96 - 1][8 - 1] = -1;
  unit_map[8 - 1][26 - 1] = -1;
  unit_map[37 - 1][190 - 1] = -2;
  unit_map[32 - 1][180 - 1] = -3;
  unit_map[58 - 1][136 - 1] = -4;
  unit_map[58 - 1][162 - 1] = -2;
  unit_map[90 - 1][172 - 1] = -2;
  unit_map[90 - 1][118 - 1] = -1;
  unit_map[8 - 1][126 - 1] = -1;

  // AI units
  unit_map[172 - 1][88 - 1] = 2;
  unit_map[126 - 1][34 - 1] = 2;
  unit_map[262 - 1][70 - 1] = 2;
  unit_map[216 - 1][98 - 1] = 2;
  unit_map[152 - 1][54 - 1] = 2;
  unit_map[172 - 1][188 - 1] = 2;
  unit_map[126 - 1][134 - 1] = 2;
  unit_map[262 - 1][170 - 1] = 2;
  unit_map[216 - 1][198 - 1] = 2;
  unit_map[152 - 1][154 - 1] = 2;
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

void printInfluenceMapRow(int column) {
  for (int r0{0}; r0 < ROWS; r0++) {
    cout << influence_map[column][r0];
  }
  cout << '\n';
}

void printInfluenceMap() {
  for (int c0{0}; c0 < COLS; c0++) {
    printInfluenceMapRow(c0);
  }
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

int main() {
{
  initMap();

  auto start = std::chrono::system_clock::now();
  calculateStregths();
  auto stop = std::chrono::system_clock::now();
  std::chrono::duration<double> duration = stop - start;
  cout << "Aikaa kului " << duration.count() << " sekuntia";
  if (duration.count() > 60)
    cout << " eli "
         << std::chrono::duration_cast<std::chrono::minutes>(duration)
      .count()
         << " minuuttia";

  cout << ".\n";

  // printInfluenceMap();

  showWindow();
  return 0;
}
