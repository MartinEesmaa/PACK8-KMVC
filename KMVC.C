/*
MIT License

Copyright(c) 2024 Martin Eesmaa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>

int main()
{
	printf("FullMotionVideo compression/decompression"
	"\n(c) Karl Morton 1994,1995,1996 All Rights Reserved\n"
	"(c) Martin Eesmaa 2024, MIT License, reimplementation in C programming language\n"
	"\nGitHub: https://github.com/MartinEesmaa/PACK8-KMVC\n"
    "\nEmail: martin.eesmaa@protonmail.com\n"
	"\nOptions:\n"
	"  /size <x> <y>               set output window size (maximum 320x200)\n"
    "  /crop <x1> <y1> <x2> <y2>   set input window size\n"
	"  /dither <n>                 set dither coefficient (0..1)\n"
	"  /frate <n>                  set replay frame rate (5..60 FPS)\n"
	"  /srate <n>                  set replay audio rate (5000..44000 Hz)\n"
	"  /output <path>              set output animation file\n"
	"  /palsize <n>                set palette size (1..255)\n"
	"  /output <path>              set output animation file\n"
	"  /drate <n>                  set data rate (k/sec)\n"
	"  /con <n>                    set contrast enhancement factor\n"
	"  /bri <n>                    set brightness enhancement factor\n"
	"  /fadeup <n>                 fade first <n> frames up from BLACK\n"
	"  /fadedn <n>                 fade  last <n> frames down to BLACK\n"
	"  /even                       remove odd lines from source image\n"
	"  /odd                        remove even lines from source image\n"
	"  /delsrc                     delete source files when processed\n"
	"  /monopal                    calculate one optimal movie palette\n"
	"  /loadpal <path>             load movie palette from file\n"
	"  /savepal <path>             save movie palette(s) to file\n"
	"  /palframes <path>           load a list of user-defined palette frame numbers\n"
	"  /keyforce <n>               force keyframe every <n> frames\n\n"
	"Input:\n\n"
	"tga <path1> .. <pathN>\n\n"
	"or...\n\n"
	"par { <path> <first> <last> }\n\n"
	"or...\n\n"
	"old <snd-dump> <avi-name>\n");
	return 0;
}