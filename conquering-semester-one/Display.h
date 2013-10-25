/**
 * Display class
 *
 * This class is designed to manipulate the text output in the 
 * console in the following ways:
 *  - Change the text color.
 *  - Clear the contents of the console.
 *  - Evenly distribute several "columns" of text into a "row" in a "table".
 *
 * @author    Oliver Spryn
 * @namespace global
 * @package   display
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include "DistributeParametersInvalid.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Display {
public : 
        static void clear();
        static void coloredText(string text, int color);
        static string distribute(vector<string> text, vector<char> align) throw(DistributeParametersInvalid);
        static void resetTextColor();
        static void setTextColor(int color);

        static const int CONSOLE_HEIGHT = 25;
        static const int CONSOLE_WIDTH = 80;
        static const int DEFAULT_CONSOLE_COLOR = 7;
};

enum colors {pink = 13, green = 10, yellow = 14, blue = 9, white = 15, red = 12};

#endif