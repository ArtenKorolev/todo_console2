#ifndef _CONSOLE_UI_HPP_
#define _CONSOLE_UI_HPP_

#include <string>

class ConsoleUI
{
   public:
    static void run();

   private:
    static void _userInput(std::string &buffer);
    static void _printOptions();
    static void _handleInput(const std::string &input);
};

#endif  // _CONSOLE_UI_HPP_
