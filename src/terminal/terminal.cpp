#include "terminal.h"

size_t strlen(const char* str)
{
	size_t ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}

Terminal::Terminal( size_t width, size_t height ) :
  _width( width ),
  _height( height ),
  _rowCounter( 0 ),
  _columnCounter( 0 ),
  _textColour( ColourWhite ),
  _backgroundColour( ColourBlack ),
  _buffer( ( uint16_t* ) 0xB8000 )
{
  for( size_t x = 0; x < _width; ++x )
    {
      for( size_t y = 0; y < _height; ++y )
	{
	  const size_t index = y * _width + x;
	  _buffer[index] = MarkUp( ' ' ); 
	}
    }
}

uint16_t Terminal::MarkUp( char c )
{
  uint16_t c16 = c;
  uint16_t color16 = _textColour | _backgroundColour << 4;

  return c16 | color16 << 8;
}


void Terminal::SetTextColour( Colour colour )
{
  _textColour = colour;
}

void Terminal::SetBackgroundColour( Colour colour )
{
  _backgroundColour = colour;
}
 
void Terminal::WriteEntryAt( char c, size_t x, size_t y )
{
  const size_t index = y * _width + x;
  _buffer[index] = MarkUp( c );
}
			    
void Terminal::Write( char c )
{
    if( c == '\n' )
    {
      // Increment the row counter and reset the column counter
      _rowCounter++;
      _columnCounter = 0;
      return;
    }

    WriteEntryAt( c, _columnCounter, _rowCounter );
    
    if ( ++_columnCounter == _width )
    {
        _columnCounter = 0;
        if ( ++_rowCounter == _height )
	{
	    _rowCounter = 0;
	}
    }
}

void Terminal::Write( const char * data )
{
  size_t datalen = strlen(data);
  for ( size_t i = 0; i < datalen; i++ )
    Write(data[i]);
}

void Terminal::WriteLine( const char* data )
{
  Write( data );
  Write( "\n" );
}
