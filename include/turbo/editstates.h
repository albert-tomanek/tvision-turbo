#ifndef TURBO_EDITSTATES_H
#define TURBO_EDITSTATES_H

#include <tvision/tv.h>

namespace Scintilla {

struct TScintillaEditor;

} // namespace Scintilla

namespace turbo {

class LineNumbersWidth
{

public:

    int minWidth;
    bool enabled {false};

    LineNumbersWidth(int min) :
        minWidth(min)
    {
    }

    void toggle()
    {
        enabled ^= true;
    }

    int update(Scintilla::TScintillaEditor &editor);

private:

    int calcWidth(Scintilla::TScintillaEditor &editor);

};

class WrapState
{
    bool enabled {false};
    bool confirmedOnce {false};

public:

    bool toggle(Scintilla::TScintillaEditor &editor, bool dialog=true);
};

struct AutoIndent
{
    bool enabled {true};

    void toggle()
    {
        enabled ^= true;
    }

    void applyToCurrentLine(Scintilla::TScintillaEditor &editor);
};

void stripTrailingSpaces(Scintilla::TScintillaEditor &editor);
void ensureNewlineAtEnd(Scintilla::TScintillaEditor &editor);

} // namespace turbo

#endif