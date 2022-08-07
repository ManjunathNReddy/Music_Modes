#include <iostream>
#include <map>
using namespace std;

constexpr unsigned int num_notes = 12;
// Intervals
enum class Step{H=1, W};
// Music modes
enum class Mode{Ionian, Dorian, Phrygian, Lydian, Mixolydian, Aeolian, Locrian}; 

namespace Chord
{
    // The 12 notes of the chromatic scale
    enum class ChordAlphabet{C,Cs,D,Ds,E,F,Fs,G,Gs,A,As,B}; 

    // String representation of the chords
    static const map <ChordAlphabet, string> string_by_chord = 
        {{ChordAlphabet::C, "C"},{ChordAlphabet::Cs, "C#"},{ChordAlphabet::D, "D"},{ChordAlphabet::Ds, "D#"},{ChordAlphabet::E, "E"},
        {ChordAlphabet::F, "F"},{ChordAlphabet::Fs, "F#"},{ChordAlphabet::G, "G"},{ChordAlphabet::Gs, "G#"},{ChordAlphabet::A, "A"},
        {ChordAlphabet::As, "A#"},{ChordAlphabet::B, "B"}};

    // Chord + intervals (in half steps)
    ChordAlphabet operator+(const ChordAlphabet chord, const unsigned short num)
    {
        return ChordAlphabet((int(chord) + num) % num_notes);
    }
    // Chord + interval (in type)
    ChordAlphabet operator+(const ChordAlphabet chord, const Step step_type)
    {
        return (chord + static_cast<unsigned short>(step_type));
    }
    // Next chord
    ChordAlphabet& operator++(ChordAlphabet& chord)
    {
        chord = chord + 1;
        return chord;
    }
    // Show chord name
    ostream& operator<<(ostream& out, const ChordAlphabet& chord)
    {
        return out << string_by_chord.at(chord);
    }
}