linux_build: 
    clang main.c -std=c99 -Wextra -Wall -L /lib/ -lraylib -o main

macos_build:
    clang main.c -std=c99 -Wextra -Wall -L /opt/homebrew/lib -lraylib -o main    
