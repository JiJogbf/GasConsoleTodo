## GasConsoleTodo
Simple native CLI Todo managment tool.

## Known issues
For now this tool compiling only on Windows. If you kind people and wana help, feel free to make contribution for make this build crossplatform!

## How to build
In current master branch i used mingw and cmake. 

### Using MinGW 
calling cmake . -G "MinGW Makefile", then call mingw32-make to
build this app. After build will be created todo binnary. 

# Steps 
1. Install mingw
2. install cmake
3. make shure that mingw32-make and cmake apps accessible from command line
4. clone this repo
5. perform command `cmake . -G "MinGW Makefiles"`
6. If all green, then type `mingw32-make` (or `make`, but it's not tested)
7. Done. you compiled todo app in root folder and ready to use this application.

## How use 
For todo app we have some actions and that actions requires parameter.
action list. Appkication working with todo.txt text file. This file represen you 
current Todo tasks. Each task can be in one of supported states (New, Done, Delayed)

```
example_list
[ ] #1 This task is new
[-] #2 This task is delayed
[x] #3 this task is done
```

## Actions
1. Adding new taslk
```
todo new "long text"
todo new one_word
```
2. Make task with id=2 done
`todo done 2`
3. Make task with id=3 redone (Change state from Done to New for Task)
`todo renew 3`
4. Make task with id=1 delayed
`todo delay 1`



