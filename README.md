# PACK8-KMVC
A closed source MS-DOS executable of Karl Morton's Video Codec encoder.

Command line help usage:

```
              FullMotionVideo compression/decompression
          (c) Karl Morton 1994,1995,1996 All Rights Reserved

                   email: info@beamaim.demon.co.uk

usage: pack8 <options> <input>

Options:

  size <x> <y>               set output window size
  crop <x1> <y1> <x2> <y2>   set input window size
  dither <n>                 set dither coefficient (0..1)
  frate <n>                  set replay frame rate
  srate <n>                  set replay audio rate
  output <path>              set output animation file
  palsize <n>                set palette size (1..255)
  drate <n>                  set data rate (k/sec)
  con <n>                    set contrast enhancement factor
  bri <n>                    set brightness enhancement factor
  fadeup <n>                 fade first <n> frames up from BLACK
  fadedn <n>                 fade  last <n> frames down to BLACK
  even                       remove odd lines from source image
  odd                        remove even lines from source image
  delsrc                     delete source files when processed
  monopal                    calculate one optimal movie palette
  loadpal <path>             load movie palette from file
  savepal <path>             save movie palette(s) to file
  palframes <path>           load a list of user-defined palette frame numbers
  keyforce <n>               force keyframe every <n> frames

Input:

  tga <path1> .. <pathN>

or...

  par { <path> <first> <last> }

or...

  old <snd-dump> <avi-name>
```

The executable binary was compiled by Karl Morton and AVI files were used at Worms game for cutscenes from Team17.

- Martin Eesmaa