# Possible Julia Bug when overwriting `_exit` via `LD_PRELOAD`

Issue: <https://github.com/JuliaLang/julia/issues/60971>

tested with Julia 1.12.4 installed on Debian 13 via juliaup.

Issue was closed as not planned, thus this repo is only archived for reference (and maybe other poor souls who do `LD_PRELOAD`ing

## How to use
run `./reproduce.sh`

Note: It fails with both g++ and clang++

## Output
```
~/code/julia_ldpreload_exit$ ./reproduce.sh 
+ g++ -ldl -fPIC -shared -o injector.so injector.cc
injector.cc: In function ‘void _exit(int)’:
injector.cc:14:1: warning: ‘noreturn’ function does return
   14 | }
      | ^
+ julia --version
julia version 1.12.4
+ LD_PRELOAD=./injector.so
+ julia main.jl
duck _exit
Error during libstdcxxprobe in parent process:
The child process did not exit normally.
```
