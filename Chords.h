#include <iostream>
#include <map>

constexpr unsigned int num_notes = 12;
// Intervals
enum class Step
{
    H = 1,
    W
};
// Music modes
enum class Mode
{
    Ionian,
    Dorian,
    Phrygian,
    Lydian,
    Mixolydian,
    Aeolian,
    Locrian
};

namespace Chord
{
    // The 12 notes of the chromatic scale
    enum class ChordAlphabet
    {
        C,
        Cs,
        D,
        Ds,
        E,
        F,
        Fs,
        G,
        Gs,
        A,
        As,
        B
    };

    // String representation of the chords
    inline const std::map<ChordAlphabet, std::string> chord_string =
        {{ChordAlphabet::C, "C"}, {ChordAlphabet::Cs, "C#"}, {ChordAlphabet::D, "D"}, {ChordAlphabet::Ds, "D#"}, {ChordAlphabet::E, "E"}, {ChordAlphabet::F, "F"}, {ChordAlphabet::Fs, "F#"}, {ChordAlphabet::G, "G"}, {ChordAlphabet::Gs, "G#"}, {ChordAlphabet::A, "A"}, {ChordAlphabet::As, "A#"}, {ChordAlphabet::B, "B"}};
    // Chord + intervals (in half steps)
    inline ChordAlphabet operator+(const ChordAlphabet chord, const unsigned short num)
    {
        return ChordAlphabet((static_cast<unsigned short>(chord) + num) % num_notes);
    }
    // Chord + interval (in type)
    inline ChordAlphabet operator+(const ChordAlphabet chord, const Step step_type)
    {
        return (chord + static_cast<unsigned short>(step_type));
    }
    // Next chord
    inline ChordAlphabet &operator++(ChordAlphabet &chord)
    {
        chord = chord + 1;
        return chord;
    }
}
inline std::ostream &operator<<(std::ostream &out, const Chord::ChordAlphabet chord)
{
    return out << Chord::chord_string.at(chord);
}