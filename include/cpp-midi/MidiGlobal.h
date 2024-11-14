#ifndef MIDIGLOBAL_H
#define MIDIGLOBAL_H

#ifdef _MSC_VER
#  define CPP_MIDI_DECL_EXPORT __declspec(dllexport)
#  define CPP_MIDI_DECL_IMPORT __declspec(dllimport)
#else
#  define CPP_MIDI_DECL_EXPORT __attribute__((visibility("default")))
#  define CPP_MIDI_DECL_IMPORT __attribute__((visibility("default")))
#endif

#ifndef CPP_MIDI_EXPORT
#  ifdef CPP_MIDI_STATIC
#    define CPP_MIDI_EXPORT
#  else
#    ifdef CPP_MIDI_LIBRARY
#      define CPP_MIDI_EXPORT CPP_MIDI_DECL_EXPORT
#    else
#      define CPP_MIDI_EXPORT CPP_MIDI_DECL_IMPORT
#    endif
#  endif
#endif

#endif //MIDIGLOBAL_H
