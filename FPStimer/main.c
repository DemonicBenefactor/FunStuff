/*
    Ambiguous
    Copyright (C) 2015-2016 Demonic Benefactor <demonic@tutanota.de>
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include <stdio.h>
#include <time.h>

#define FPS 60
#define MSEC (double)CLOCKS_PER_SEC/1000
#define CLOCK (double)clock()


int main (int argc, char *argv[])
{
  
  double delay, frameStart, frameTime;
  unsigned int i, j, running;

  //clock returns clock_t,
  
  delay = (MSEC) / FPS;
  running = 1;
  i = j = 0;

  while (running)
  {
    frameStart = frameTime = CLOCK;

    //MAIN LOOP
    ++i;
    if (i > 60)
    {
        printf("%u \n", j);
        i = 0;
        j++;
    }
    //MAIN LOOP END
    
    while ( frameTime/(MSEC) - frameStart/(MSEC) < delay )
    {
        frameTime = CLOCK;
    }
  }

  return 0;
}
