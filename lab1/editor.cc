#include "editor.h"

#include <string>
//commect check for make
using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
	if (pos >= text.size() || (text[pos] != ')' && text[pos] != ']' && text[pos] != '}')){
	
    return string::npos;


	}




    return string::npos;

}
