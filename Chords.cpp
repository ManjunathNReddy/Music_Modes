#include <algorithm>
#include <utility>
#include <vector>

#include "Chords.h"

void print_error_and_exit(const std::string &message)
{
    std::cout << message << "\n";
    exit(-1);
}

unsigned short get_user_mode()
{
    unsigned short mode;
    std::cout << "What do you want to play? \n";
    std::cout << " 1. Ionian (Pop) (M)\n";
    std::cout << " 2. Dorian (Blues) (m)\n";
    std::cout << " 3. Phrygian (Exotic) (m)\n";
    std::cout << " 4. Lydian (Inspiring) (M)\n";
    std::cout << " 5. Mixolydian (Rock) (M)\n";
    std::cout << " 6. Aeolian (Metal) (m)\n";
    std::cout << " 7. Locrian (Jazz) (dim)\n";
    std::cin >> mode;
    return mode;
}
// Get user desired key
std::string get_user_key()
{
    std::string key;
    std::cout << "Which key do you want to play in? \n";
    std::cin >> key;
    for (auto &c : key)
        c = toupper(static_cast<unsigned char>(c));
    return key;
}

int main()
{
    std::vector<Step> intervals = {Step::W, Step::W, Step::H, Step::W, Step::W, Step::W, Step::H};
    unsigned short choice = get_user_mode();
    bool valid_choice = (0 < choice && choice < 8);

    if (!valid_choice)
    {
        print_error_and_exit("Invalid input!");
    }
    // Make choice zero indexed
    choice--;
    std::string key = get_user_key();

    // Find the corresponding chord enum
    Chord::ChordAlphabet chord;
    bool chord_found = false;
    for (const auto &[chord_enum, chord_str] : Chord::chord_string)
    {
        if (chord_str == key)
        {
            chord = chord_enum;
            chord_found = true;
            break;
        }
    }

    std::cout << std::string(50, '\n');

    if (!chord_found)
    {
        print_error_and_exit("Invalid key!");
    }

    auto shift = static_cast<unsigned short>(choice);
    // Transform to mode
    std::rotate(intervals.begin(), intervals.begin() + shift, intervals.end());
    for (auto interval : intervals)
    {
        std::cout << std::exchange(chord, chord + interval) << " ";
    }
    return 0;
}