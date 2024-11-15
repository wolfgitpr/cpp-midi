# wolf-midi

## Intro

Refer to [QMidi](https://github.com/waddlesplash/QMidi).

Only provides the most basic MIDI file read and write functions.

## Install

```bash
vcpkg install wolf-midi
```

```cmake
find_package(wolf-midi)
target_link_libraries(${PROJECT_NAME} PRIVATE wolf-midi::wolf-midi)
```

## Usage

## MIDI File I/O

Quick example:
```c++
MidiFile f;
f.load(" .. some filename .. ");
f.save(" .. some filename .. ");
```
You can get the events using `f.events()` which returns a `std::list<MidiEvent*>*`.