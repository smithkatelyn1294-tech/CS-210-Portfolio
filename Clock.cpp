/*
 * Chada Tech Clocks
 *
 * Author: Katelyn Mathews
 *
 * This file contains the functions used by the Clock class.
 */

#include "Clock.h"

 // Sets the starting time for the clock.
Clock::Clock(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

// Adds one hour to the clock.
void Clock::addHour()
{
    hour++;

    // Reset the hour after 23.
    if (hour >= 24)
    {
        hour = 0;
    }
}

// Adds one minute to the clock.
void Clock::addMinute()
{
    minute++;

    // Reset minutes and add one hour when needed.
    if (minute >= 60)
    {
        minute = 0;
        addHour();
    }
}

// Adds one second to the clock.
void Clock::addSecond()
{
    second++;

    // Reset seconds and add one minute when needed.
    if (second >= 60)
    {
        second = 0;
        addMinute();
    }
}

// Returns the current hour.
int Clock::getHour()
{
    return hour;
}

// Returns the current minute.
int Clock::getMinute()
{
    return minute;
}

// Returns the current second.
int Clock::getSecond()
{
    return second;
}