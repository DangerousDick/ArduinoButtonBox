#include <Joystick.h>

// button matrix
const int matrix_size = 5;
int button_matrix[matrix_size][matrix_size] = {{0, 1, 2, 3, 4},
                                               {5, 6, 7, 8, 9},
                                               {10,11,12,13,14},
                                               {15,16,17,18,19},
                                               {20,21,22,23,24}};
                                               
/*int button_matrix_state[matrix_size][matrix_size] = {{0,0,0,0,0},
                                                     {0,0,0,0,0},
                                                     {0,0,0,0,0},
                                                     {0,0,0,0,0},
                                                     {0,0,0,0,0}};*/

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  (matrix_size * matrix_size), // Button Count
  0,                           // Hat Switch Count
  false, false, false,         // X and Y, but no Z Axis
  false, false, false,         // No Rx, Ry, or Rz
  false, false,                // No rudder or throttle
  false, false, false);        // No accelerator, brake, or steering

// input pins (column)
//int col_in_pins[matrix_size] = {2,3,4,5,6};
int col_in_pins[matrix_size] = {6,5,4,3,2};
// output pins (row)
//int row_out_pins[matrix_size] = {8,9,10,11,12};
int row_out_pins[matrix_size] = {12,11,10,9,8};

void setup()
{
  // set these digital pins as output
  for (int index = 0; index < matrix_size; index++)
  {
    pinMode(row_out_pins[index], OUTPUT);
  }
  // set these digital pins as input
  for (int index = 0; index < matrix_size; index++)
  {
    pinMode(col_in_pins[index], INPUT);
  }

  // init joystick lib
  Joystick.begin();
}

void loop()
{
  // cycle through output pins
  for (int row = 0; row < matrix_size; row++)
  {
    digitalWrite(row_out_pins[row], HIGH);   // power to pin
    // cycle through input pins
    for (int col = 0; col < matrix_size; col++)
    {
      delay(5);
      //button_matrix_state[row][col] = digitalRead(col_in_pins[col]);
      //Joystick.setButton(button_matrix[row][col], button_matrix_state[row][col]);
      Joystick.setButton(button_matrix[row][col], digitalRead(col_in_pins[col]));
    }
    digitalWrite(row_out_pins[row], LOW);   // no power to pin
  }
}

