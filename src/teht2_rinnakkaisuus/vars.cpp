#ifndef VARS_H
#define VARS_H

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

#endif /* VARS_H */
