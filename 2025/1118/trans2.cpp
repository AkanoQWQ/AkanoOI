#include<bits/stdc++.h>
using namespace std;

#define NOTE_B0   "NotePitch::B0"
#define NOTE_C1   "NotePitch::C1"
#define NOTE_CS1  "NotePitch::Cs1"
#define NOTE_D1   "NotePitch::D1"
#define NOTE_DS1  "NotePitch::Ds1"
#define NOTE_E1   "NotePitch::E1"
#define NOTE_F1   "NotePitch::F1"
#define NOTE_FS1  "NotePitch::Fs1"
#define NOTE_G1   "NotePitch::G1"
#define NOTE_GS1  "NotePitch::Gs1"
#define NOTE_A1   "NotePitch::A1"
#define NOTE_AS1  "NotePitch::As1"
#define NOTE_B1   "NotePitch::B1"

#define NOTE_C2   "NotePitch::C2"
#define NOTE_CS2  "NotePitch::Cs2"
#define NOTE_D2   "NotePitch::D2"
#define NOTE_DS2  "NotePitch::Ds2"
#define NOTE_E2   "NotePitch::E2"
#define NOTE_F2   "NotePitch::F2"
#define NOTE_FS2  "NotePitch::Fs2"
#define NOTE_G2   "NotePitch::G2"
#define NOTE_GS2  "NotePitch::Gs2"
#define NOTE_A2   "NotePitch::A2"
#define NOTE_AS2  "NotePitch::As2"
#define NOTE_B2   "NotePitch::B2"

#define NOTE_C3   "NotePitch::C3"
#define NOTE_CS3  "NotePitch::Cs3"
#define NOTE_D3   "NotePitch::D3"
#define NOTE_DS3  "NotePitch::Ds3"
#define NOTE_E3   "NotePitch::E3"
#define NOTE_F3   "NotePitch::F3"
#define NOTE_FS3  "NotePitch::Fs3"
#define NOTE_G3   "NotePitch::G3"
#define NOTE_GS3  "NotePitch::Gs3"
#define NOTE_A3   "NotePitch::A3"
#define NOTE_AS3  "NotePitch::As3"
#define NOTE_B3   "NotePitch::B3"

#define NOTE_C4   "NotePitch::C4"
#define NOTE_CS4  "NotePitch::Cs4"
#define NOTE_D4   "NotePitch::D4"
#define NOTE_DS4  "NotePitch::Ds4"
#define NOTE_E4   "NotePitch::E4"
#define NOTE_F4   "NotePitch::F4"
#define NOTE_FS4  "NotePitch::Fs4"
#define NOTE_G4   "NotePitch::G4"
#define NOTE_GS4  "NotePitch::Gs4"
#define NOTE_A4   "NotePitch::A4"
#define NOTE_AS4  "NotePitch::As4"
#define NOTE_B4   "NotePitch::B4"

#define NOTE_C5   "NotePitch::C5"
#define NOTE_CS5  "NotePitch::Cs5"
#define NOTE_D5   "NotePitch::D5"
#define NOTE_DS5  "NotePitch::Ds5"
#define NOTE_E5   "NotePitch::E5"
#define NOTE_F5   "NotePitch::F5"
#define NOTE_FS5  "NotePitch::Fs5"
#define NOTE_G5   "NotePitch::G5"
#define NOTE_GS5  "NotePitch::Gs5"
#define NOTE_A5   "NotePitch::A5"
#define NOTE_AS5  "NotePitch::As5"
#define NOTE_B5   "NotePitch::B5"

#define NOTE_C6   "NotePitch::C6"
#define NOTE_CS6  "NotePitch::Cs6"
#define NOTE_D6   "NotePitch::D6"
#define NOTE_DS6  "NotePitch::Ds6"
#define NOTE_E6   "NotePitch::E6"
#define NOTE_F6   "NotePitch::F6"
#define NOTE_FS6  "NotePitch::Fs6"
#define NOTE_G6   "NotePitch::G6"
#define NOTE_GS6  "NotePitch::Gs6"
#define NOTE_A6   "NotePitch::A6"
#define NOTE_AS6  "NotePitch::As6"
#define NOTE_B6   "NotePitch::B6"

#define NOTE_C7   "NotePitch::C7"
#define NOTE_CS7  "NotePitch::Cs7"
#define NOTE_D7   "NotePitch::D7"
#define NOTE_DS7  "NotePitch::Ds7"
#define NOTE_E7   "NotePitch::E7"
#define NOTE_F7   "NotePitch::F7"
#define NOTE_FS7  "NotePitch::Fs7"
#define NOTE_G7   "NotePitch::G7"
#define NOTE_GS7  "NotePitch::Gs7"
#define NOTE_A7   "NotePitch::A7"
#define NOTE_AS7  "NotePitch::As7"
#define NOTE_B7   "NotePitch::B7"

#define NOTE_C8   "NotePitch::C8"
#define NOTE_CS8  "NotePitch::Cs8"
#define NOTE_D8   "NotePitch::D8"
#define NOTE_DS8  "NotePitch::Ds8"



int main(){
	freopen("output2.txt","w",stdout);
	uint32_t bpm = 137;
	uint32_t ndms = 12000;
	string melody[] = {
		// Intro
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2, NOTE_DS2,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, NOTE_DS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_DS3, NOTE_FS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, NOTE_DS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_DS3, NOTE_FS3,
		// Verse 1 - 16
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4,
		// Verse 17 - 32
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_F5,
		NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		// Verse 33 - 48
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_F5,
		NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, "NotePitch::Rest",
		// Interlude
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, NOTE_DS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_DS3, NOTE_FS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, NOTE_DS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_GS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3,
		NOTE_DS3, "NotePitch::Rest", NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_GS3, NOTE_FS3, NOTE_GS3, NOTE_FS3, NOTE_DS3, NOTE_FS3,
		// Verse(2) 1 - 16
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_CS5,
		NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_F4,
		NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4,
		// Verse(2) 17 - 32
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_DS4,
		NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_AS4, NOTE_CS5,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		NOTE_CS5, NOTE_DS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_DS5, NOTE_F5,
		NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4,
		//                                               to 1=G
		NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_B4, NOTE_D5,
		// Verse(2) 33 - 48 1=G
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4,
		NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_D5,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4,
		NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_D5,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4,
		NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_D5,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_FS5,
		NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4,
		NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_E4, "NotePitch::Rest",
		// Outro 1=G
		NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
		NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
		NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
		NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, "NotePitch::Rest",
		"NotePitch::Rest"
	};
	// note durations: unit: 1/16 note, time = number * (1/16), ex: 1/4 note, number: 4, 1/8 note, number: 2:
	uint32_t noteDurations[] = {
		// Intro
		4, 4, 4, 1, 1, 1, 1,
		4, 4, 4, 2, 2,
		4, 4, 4, 1, 1, 1, 1,
		4, 4, 4, 2, 2,
		4, 4, 4, 1, 1, 1, 1,
		4, 4, 4, 2, 2,
		4, 4, 4, 1, 1, 1, 1,
		4, 4, 4, 2, 2,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		// Verse 1 - 16
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 4, 4,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 4, 4,
		// Verse 17 - 32
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		// Verse 33 - 48
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 4,
		// Interlude
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		4, 1, 1, 1, 1, 4, 1, 1, 1, 1,
		4, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1,
		// Verse(2) 1 - 16
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 4, 4,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 2, 2, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		4, 4, 4, 4,
		// Verse(2) 17 - 32
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		// Verse(2) 33 - 48
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 2, 2,
		2, 2, 2, 2, 4, 4,
		// Outro
		3, 3, 2, 3, 3, 2,
		3, 3, 2, 3, 3, 2,
		3, 3, 2, 3, 3, 2,
		3, 3, 2, 3, 3, 2,
		16
	};
	for (uint32_t i = 0; i < 895; i++){
		cout<<"Note("<<melody[i]<<","<<noteDurations[i] * ndms / bpm<<"),"<<endl;
	}
	return 0;
}

