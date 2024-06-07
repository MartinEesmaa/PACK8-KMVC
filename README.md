# PACK8-KMVC
A closed source MS-DOS executable of Karl Morton's Video Codec encoder.

Command line help usage of PACK8:

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

Command line help usage of AUDIO (after PACK8):

```
Usage: audio <options> <audiofile> <moviefile>

options:
  -offset <n>        : specifies offset into sample data
  -volume <n>        : specifies volume adjustment (0..1)
  -fadeup <n>        : specifies fade up frame count
  -fadedn <n>        : specifies fade down frame count
```

Command line help usage of PLAY (to verify is it playing correctly, FFmpeg native decoder of KMVC is available):

```
              FullMotionVideo compression/decompression
    Copyright VidiCom Technology 1994,1995,1996 All Rights Reserved

                   email: info@beamaim.demon.co.uk

usage: play <options> <filename>.avi

generic:
   /quiet            - operate quietly (no messages)
   /noskip           - disable frame skipping on slow machines
   /position <x> <y> - set replay window position

audio:
   /nosound          - no sound
   /blaster          - select sound-blaster
   /gravis           - select ultrasound

vga:
   /modex            - use modex screen double buffering
   /square           - enable square pixels (60hz refresh)
   /novideo          - dont setup video mode
   /gamma <n>        - set gamma correction (default=1.00)
   /palette <path>   - load fixed palette from file

svga:
   /fastcopy         - use fast copyup method
```

The executable binary was compiled by Karl Morton and AVI files were used at Worms game for cutscenes from Team17.

# Instructions to encode KMVC and embed WAV to AVI file

If you want to encode your source video into KMVC (known as Karl Morton's Video Codec) and embed WAV file to AVI file, here's how you gonna do:

You need:

* DOSBOX(-X) (recommended), FreeDOS or MS-DOS to run DOS executable file.
* FFmpeg (by encoding from source video to Truevision Targa image frames and only PCM Unsigned 8-bit with mono channel) (maximum 320x200 for output size on DOS video encoder) and to play AVI file using ffplay.
* PACK8 (for video encoding) or/and AUDIO (for embedding)
* 7-Zip or any compression tools to decompress KMVC.7z
* PLAY (for video with audio playback, optional)

If you have installed DOSBox or any DOS and FFmpeg, skip to Step 3.

Step 1: 

I recommend using DOSBOX-X for beginner users friendly, so you can follow instructions:

https://dosbox-x.com/

Before you run DOSBOX-X, you need to create a directory in root or anywhere of C:/ for Windows or / for macOS/Linux to avoid the directory is not found.

After that, run DOSBOX-X and type:

```
mount C: C:/DOSBOX
```

This mounts only folder of C: on DOSBox emulation, not the whole disk.

Step 2:

For Windows, you can download FFmpeg binaries from Gyan or BtBn.

After downloading FFmpeg binaries, make sure the FFmpeg binaries are in path environment.

For MacOS:

```
brew install ffmpeg
```

For Linux:

```
sudo apt install ffmpeg
```

If you have different based OS than example Debian based command, you may able to install FFmpeg by your package manager on your Linux OS.

Step 3:

Once you've installed FFmpeg, it is good idea to create directory in like Downloads folder or anything.

Copy your source video file to that you created a new directory.

Make a directory:

Windows: `mkdir C:\DOSBOX\IMGF1`

Linux/macOS: `mkdir -p ~/DOSBox/IMGF1`

Run to encode Truevision Targa image frames before KMVC:

Video frames:
```
ffmpeg -i sample.mp4 -s:v 320x200 -c:v targa -rle 0 C:\DOSBOX\IMGF1\00%4d.tga
```

You need to remember the FPS (frame per second) for example 25 fps reported on FFmpeg, because encoder requires to insert manually frame per second.

Also if you want to audio as well, you can embed after video encoding is done:

```
ffmpeg -i sample.mp4 -c:a pcm_u8 -ar 22050 -ac 1 -fflags +bitexact -flags:a +bitexact -map_metadata -1 C:\DOSBOX\sample.wav
```

Step 4:

You can download two seperate binaries by clicking executable file and go to Raw button to download on GitHub and save directory to DOSBox directory

Or...

You can decompress KMVC.7z compressed file and decompress into DOSBox directory.

For PLAY.EXE, it's necessary optional, but you can download as well to make sure it is compatible to play it with video or/and audio on DOS binary.

FFmpeg native decoder of KMVC is still available since 2007.

Step 5:

Once, you've finished encoding video and audio, head to DOSBOX-X.

Go to mount directory on DOSBox:

```
C:
```

Just in case, please double check the audio file, directory of Targa video frames and two executable files.

```
dir
ls
```

Once you've checked that exists, you're all checked.

Step 6:

After checking the file, run the example command:

```
pack8 /size 320 200 /drate 2500 /frate 30 /srate 22050 /output ENCODED.AVI tga IMGF1
```

```
Size is video output.
DRATE is video bitrate.
FRATE is frame per second.
SRATE is audio sample rate.
Output is to encode AVI (Audio Video Interleave) file.
tga IMGF1 is input to find directory with tga files.
```

After you've done that, you can embed the audio file to AVI file to finish off.

```
audio sample.wav ENCODED.AVI
```

When it's 100%, the AVI file is completed to play on PLAY.EXE or FFplay from FFmpeg.

- Martin Eesmaa