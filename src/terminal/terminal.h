#include <stddef.h>
#include <stdint.h>
#include "colour.h"


enum Colour;

class Terminal
{
  size_t _width;
  size_t _height;
  size_t _rowCounter;
  size_t _columnCounter;
  Colour _textColour;
  Colour _backgroundColour; 
  uint16_t* _buffer;
  
 public:

    Terminal( size_t width, size_t height );
    void Write( char c );
    void Write( const char * data );
    void WriteLine( const char * data );
    void SetTextColour( Colour c );
    void SetBackgroundColour( Colour c );

private:

uint16_t MarkUp( char c );
 void WriteEntryAt( char c, size_t x, size_t y );    
};
