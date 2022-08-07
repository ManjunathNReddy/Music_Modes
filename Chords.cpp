#include <algorithm>
#include <vector>

#include "Chords.h"

// Get user desired music mode
unsigned short get_user_mode()
{
    unsigned short mode;
    cout << " What do you want to play? \n";
    cout << " 1. Ionian (Pop) (M)\n";
    cout << " 2. Dorian (Blues) (m)\n";
    cout << " 3. Phrygian (Exotic) (m)\n";
    cout << " 4. Lydian (Inspiring) (M)\n";
    cout << " 5. Mixolydian (Rock) (M)\n";
    cout << " 6. Aeolian (Metal) (m)\n";
    cout << " 7. Locrian (Jazz) (m)\n";
    cin >> mode;
    return mode;
}
// Get user desired key
string get_user_key()
{
    string key;
    cout << " Which key do you want to play in? \n";
    cin >> key;
    for (auto & c: key) c = toupper(c);
    return key;
}

int main()
{
    vector<Step> intervals = {Step::W,Step::W,Step::H,Step::W,Step::W,Step::W,Step::H};
    unsigned short choice = get_user_mode();    
    bool valid_choice = (0 < choice && choice < 8);
    // Make choice zero indexed
    choice--;
    string key = get_user_key();   
    auto found_key = (find_if(Chord::string_by_chord.begin(), Chord::string_by_chord.end(), 
                    [key](const auto& mo) {return mo.second == key;}));
    
    auto chord_found = (found_key != Chord::string_by_chord.end());

    // Clear screen
    cout << string( 50, '\n' );

    if (!valid_choice || !chord_found)
    {
        cout << "Invalid input!\n";
        return -1;
    }

    Chord::ChordAlphabet chord = found_key->first;
    if(!choice)
    {
        auto shift =  static_cast<unsigned short>(Mode(choice));
        // Transform to mode       
        std::rotate(intervals.begin(),intervals.begin()+shift,intervals.end());
    }
    for (auto interval : intervals)
    {
        cout << chord << " ";
        chord = chord+interval;
    }

    return 0;
}