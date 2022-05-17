#!/bin/bash
HOST=192.168.78.140
SYSROOT=sysroot
umount $SYSROOT
mkdir -p $SYSROOT
sshfs -o idmap=user,follow_symlinks $HOST:/ $SYSROOT
