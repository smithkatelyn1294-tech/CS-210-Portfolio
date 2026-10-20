/*
 * Chada Tech Clocks
 *
 * Author: Katelyn Mathews
 *
 * This file defines the Clock class used by the program.
 */

#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor
    Clock(int h, int m, int s);

    // Functions used to change the time.
    void addHour();
    void addMinute();
    void addSecond();

    // Functions used to get the clock values.
    int getHour();
    int getMinute();
    int getSecond();
};

#endif
