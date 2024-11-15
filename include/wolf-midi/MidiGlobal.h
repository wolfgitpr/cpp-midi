#ifndef MIDIGLOBAL_H
#define MIDIGLOBAL_H

#ifdef _MSC_VER
#  define WOLF_MIDI_DECL_EXPORT __declspec(dllexport)
#  define WOLF_MIDI_DECL_IMPORT __declspec(dllimport)
#else
#  define WOLF_MIDI_DECL_EXPORT __attribute__((visibility("default")))
#  define WOLF_MIDI_DECL_IMPORT __attribute__((visibility("default")))
#endif

#ifndef WOLF_MIDI_EXPORT
#  ifdef WOLF_MIDI_STATIC
#    define WOLF_MIDI_EXPORT
#  else
#    ifdef WOLF_MIDI_LIBRARY
#      define WOLF_MIDI_EXPORT WOLF_MIDI_DECL_EXPORT
#    else
#      define WOLF_MIDI_EXPORT WOLF_MIDI_DECL_IMPORT
#    endif
#  endif
#endif

#endif //MIDIGLOBAL_H
