/*
 * Chada Tech Clocks
 *
 * Author: Katelyn Mathews
 *
 * This program displays a 12-hour and 24-hour clock at the same time.
 * The user can add one hour, one minute, or one second to the clocks.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"

using namespace std;

// Gets the starting time from the user.
void getStartingTime(int& hour, int& minute, int& second)
{
    cout << "Enter starting hour (0-23): ";
    cin >> hour;

    while (hour < 0 || hour > 23)
    {
        cout << "Please enter an hour between 0 and 23: ";
        cin >> hour;
    }

    cout << "Enter starting minute (0-59): ";
    cin >> minute;

    while (minute < 0 || minute > 59)
    {
        cout << "Please enter a minute between 0 and 59: ";
        cin >> minute;
    }

    cout << "Enter starting second (0-59): ";
    cin >> second;

    while (second < 0 || second > 59)
    {
        cout << "Please enter a second between 0 and 59: ";
        cin >> second;
    }
}

// Displays the 12-hour and 24-hour clocks side-by-side.
void displayClocks(Clock& clock)
{
    int hour12 = clock.getHour();
    string amPm = "A M";

    // Converts the 24-hour time to 12-hour time.
    if (hour12 >= 12)
    {
        amPm = "P M";
    }

    if (hour12 == 0)
    {
        hour12 = 12;
    }
    else if (hour12 > 12)
    {
        hour12 -= 12;
    }

    cout << endl;
    cout << "**************************    **************************" << endl;
    cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
    cout << "*      "
        << setfill('0') << setw(2) << hour12 << ":"
        << setw(2) << clock.getMinute() << ":"
        << setw(2) << clock.getSecond() << " " << amPm
        << "       *    *        "
        << setfill('0') << setw(2) << clock.getHour() << ":"
        << setw(2) << clock.getMinute() << ":"
        << setw(2) << clock.getSecond()
        << "        *" << endl;
    cout << "**************************    **************************" << endl;
}

// Displays the menu options.
void displayMenu()
{
    cout << endl;
    cout << "**************************" << endl;
    cout << "*  1 - Add One Hour      *" << endl;
    cout << "*  2 - Add One Minute    *" << endl;
    cout << "*  3 - Add One Second    *" << endl;
    cout << "*  4 - Exit Program      *" << endl;
    cout << "**************************" << endl;
}

// Performs the action selected by the user.
void processMenuChoice(Clock& clock, int choice)
{
    if (choice == 1)
    {
        clock.addHour();
    }
    else if (choice == 2)
    {
        clock.addMinute();
    }
    else if (choice == 3)
    {
        clock.addSecond();
    }
}

// Runs the menu until the user chooses to exit.
void runClock(Clock& clock)
{
    int choice = 0;

    do
    {
        displayClocks(clock);
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            processMenuChoice(clock, choice);
        }
        else if (choice == 4)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);
}

int main()
{
    int hour;
    int minute;
    int second;

    // Gets the initial time from the user.
    getStartingTime(hour, minute, second);

    // Creates the clock using the starting time.
    Clock clock(hour, minute, second);

    // Runs the clock program.
    runClock(clock);

    return 0;
}