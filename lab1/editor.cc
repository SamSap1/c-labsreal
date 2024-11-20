#include "editor.h"

#include <string>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const 
{
    if (pos >= text.size()) 
    {
        return string::npos;
    }

    char close = text[pos];
    char open;

    switch (close)
    {
        case ')':
            open = '('; 
            break;
        case ']': 
            open = '[';
            break;
        case '}': 
            open = '{';
            break;
        default: 
            return string::npos;
    }

    int balance = 0;

    for (size_type i = pos - 1; i >= 0; i--)
    {
        if (text[i] == close) 
        {
            balance++;
        }
        else if (text[i] == open)
        {
            balance--;
            if (balance == 0) 
            {
                return i;
            }
        }
    }
    return string::npos;
}