#!/bin/bash 
./configure --extra-cflags="-D_XBOX -I/opt/local/include" --extra-ldflags="-L/opt/local/lib" --enable-postproc --enable-gpl --enable-static --enable-swscale --enable-protocol=http --enable-memalign-hack --disable-altivec --enable-pthreads --disable-debug --disable-shared --disable-decoder=mpeg_xvmc --enable-libfaad --disable-ffplay --disable-ffserver --disable-ffprobe --disable-muxers --disable-encoders --disable-decoder=aac