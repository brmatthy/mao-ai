//
// Created by brent on 11/12/22.
//

#ifndef MAO_AI_COLOR_H
#define MAO_AI_COLOR_H

#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }

    };
    const static Color::Modifier red(Color::FG_RED);
    const static Color::Modifier def(Color::FG_DEFAULT);
}

#endif //MAO_AI_COLOR_H
