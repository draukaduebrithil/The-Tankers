#!/bin/python3
# Sconstruct file, czolgi

# zrodlami projektu sa wszystkie pliki co sie koncza na '.cpp'

sources = [ Glob('*.cpp') ];

env = Environment(); #  srodowisko, czesc skladni SConstruct

#  -Wall - wyswietlaj wszystkie rodzaje errorow,
#  std=c++11 - interpretuj pliki zgodnie ze standartem c++11
#  -g - wlacza mozliwosc debugowania kodu
env.Append(CCFLAGS = ' -Wall --std=c++11 -g  ');

#  SDL - chcemy kompilowac z SDL-em
env.Append(LINKFLAGS = ' -lSDL2 ');

# jak wpiszemy 'scons thetankers' to ma sie zrobic program thetankers
thetankers = env.Program(target = 'thetankers', source = sources);
#  jak wpiszemy 'scons' bez argumentu, to defaultowo sie zrobi thetankers
Default(thetankers)
