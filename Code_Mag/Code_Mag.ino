/********************************************************
  Sipper v3
  Written by Lex Kravitz and Mason Barrett

  Based on earlier version form the Creed lab
  https://hackaday.io/project/160388-automated-mouse-homecage-two-bottle-choice-test-v2

  Includes the "Tubetrode" hardware and library from Matt Gaidica

  This project code includes code from:
  *** Adafruit, who made the hardware breakout boards and associated code ***

  This project is released under The MIT license:

  Copyright (c) 2023 Lex Kravitz

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
********************************************************/


/********************************************************
  Setup code
********************************************************/
#include "a_Header.h"  //See "a_Header.h" for #defines and other constants

void setup() {
  StartUpCommands();
}

/********************************************************
  Main loop
********************************************************/
void loop() {
  CheckSippers();
  GoToSleep();
}
