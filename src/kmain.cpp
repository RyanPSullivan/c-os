#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
 
/* Check if the compiler thinks if we are targeting the wrong operating system. */
//#if defined(__linux__)
//#error "You are not using a cross-compiler, you will most certainly run into trouble"
//#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
#include "terminal/terminal.h"

  
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main()
{
  Terminal term = Terminal( VGA_WIDTH, VGA_HEIGHT );
  term.WriteLine("Test Writeline");
  term.Write("Test write without a line but really really really really looooooooooong");
}
