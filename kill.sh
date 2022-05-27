#!/bin/sh

TARGET=192.168.78.140
BINARY=foo.bin
scp foo.bin $TARGET:/bin
ssh $TARGET LD_LIBRARY_PATH=/opt/vc/lib ./$BINARY
ssh $TARGET pkill $BINARY
