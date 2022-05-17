#!/bin/sh

## USE SSHFS INSTEAD

HOST=192.168.78.140

mkdir sysroot
cd sysroot
rsync -avz $HOST:/lib .
rsync -avz $HOST:/usr/include usr
rsync -avz $HOST:/usr/lib usr
