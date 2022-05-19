#!/bin/bash
HOST=192.168.78.140
SYSROOT=sysroot
umount $SYSROOT
mkdir -p $SYSROOT
sshfs \
  -o "Compression=no" \
  -o "Ciphers=aes128-cbc" \
  -o cache_timeout=115200 \
  -o attr_timeout=115200 \
  -o idmap=user,follow_symlinks \
  $HOST:/ $SYSROOT


# cachefilesd

# https://superuser.com/questions/344255/faster-way-to-mount-a-remote-file-system-than-sshfs
# sshfs_opts="-o auto_cache -o cache_timeout=115200 -o attr_timeout=115200   \
# -o entry_timeout=1200 -o max_readahead=90000 -o large_read -o big_writes   \
# -o no_remote_lock"

# https://github.com/ibizaman/pcachefs

