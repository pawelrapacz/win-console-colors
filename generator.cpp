#include <fstream>
#include <iomanip>
#include <string>

int main()
{
    const char* colors[] = {
        "BLACK",
        "BLUE",
        "GREEN",
        "AQUA",
        "RED",
        "PURPLE",
        "YELLOW",
        "WHITE",
        "GREY",
        "LIGHTBLUE",
        "LIGHTGREEN",
        "LIGHTAQUA",
        "LIGHTRED",
        "LIGHTPURPLE",
        "LIGHTYELLOW",
        "BRIGHTWHITE"
    };
    std::ofstream output("win-console-colors.h", std::ios::trunc);
    output <<
R"(/* created by Paweł Rapacz https://github.com/pawelrapacz */

#ifndef WIN_CONSOLE_COLORS_H
#define WIN_CONSOLE_COLORS_H

// Naming: FOREGROUND_BACKGROUND
)";

    for (int i = 0; i < 16; i++) {          // background
        std::string fColor = "_";
        fColor.append(colors[i]);
        for (int j = 0; j < 16; j++) {      // foreground
            output << "#define " << std::left << std::setw(30) << colors[j] + fColor << "0x" << std::hex << i << j << '\n';
        }
    }

    output <<
R"(
#endif //WIN_CONSOLE_COLORS_H)";
    output.close();
    return 0;
}