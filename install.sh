#!/bin/sh
gcc chatpop.c -o chatpop.so \
  -fPIC -shared `pkg-config pidgin --cflags --libs glib-2.0` \
  -Wall -Werror-implicit-function-declaration \
  && sudo mkdir -p /usr/lib/purple-2/ \
  && sudo cp chatpop.so /usr/lib/purple-2/
