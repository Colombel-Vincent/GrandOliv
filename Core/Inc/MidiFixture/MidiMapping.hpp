/*
 * MidiMapping.hpp
 *
 *  Created on: 9 févr. 2022
 *      Author: colom
 */

#ifndef INC_MIDIFIXTURE_MIDIMAPPING_HPP_
#define INC_MIDIFIXTURE_MIDIMAPPING_HPP_
#include "../Builder.hpp"

#define NB_GREEN_LED 75
#define NB_RED_LED 169
#define NB_BUTTON 196

const uint8_t ButtonMidiMapping[NB_BUTTON][2] =
{
	2,1,  2,2,  2,3,  2,4,  2,5,// PCB1 top
	2,6,  2,7,  2,8,  2,9,  2,10, // PCB2 top
	2,61, 2,62, 2,63, 2,64, // PCB1 potard

	2,11, 2,12, 2,13, 2,14, 2,15, // PCB1 bottom
	2,16, 2,17, 2,18, 2,19, 2,20, // PCB2 bottom
	2,65, 2,66, 2,67, 2,68, // PCB2 potard

	2,21, 2,22, 2,23, 2,24, 2,25, // PCB3 Top
	2,31, 2,32, 2,33, 2,34, 2,35, // PCB4 Top
	2,69, 2,70, 2,71, 2,72, 0,0, // PCB3 potard

	2,26, 2,27, 2,28, 2,29, 2,30, // PCB3 Bottom
	2,36, 2,37, 2,38, 2,39, 2,40, // PCB4 Bottom
	1,1, 1,2, 1,3, 1,4, 1,5, // PCB12 1

	2,41, 2,42, 2,43, 2,44, 2,45, // PCB5 Top
	2,46, 2,47, 2,48, 2,49, 2,50, // PCB6 Top
	1,6, 1,7, 1,8, 1,9, 1,10, // PCB12 2

	2,51, 2,52, 2,53, 2,54, 2,55, // PCB5 Bottom
	2,56, 2,57, 2,58, 2,59, 2,60, // PCB6 Bottom
	1,11, 1,12, 1,13, 1,14, 1,15, // PCB12 3

	3,1, 3,2, 3,3, 3,4, // PCB16 1
	3,21, 3,22, // PCB 15 1
	4,1,  4,2, 4,3, // PCB 21
	1,16, 1,17, 1,18, 1,19, 1,20, // PCB12 4

	3,5, 3,6, 3,7, 3,8, // PCB16 2
	3,23, 3,24,  // PCB 15 2
	4,4,  4,5, 4,6, // PCB 22
	1,21, 1,22, 1,23, 1,24, 1,25, // PCB12 5

	3,9, 3,10, 3,11, 3,12, // PCB16 3
	3,25, 3,26,  // PCB 15 3
	4,7,  4,8, 4,9, // PCB 22
	2,73, 2,74, // PCB9

	3,13, 3,14, 3,15, 3,16, // PCB16 4
	3,27,  // PCB 15 4
	3,53,  3,54, 3,55, 3,56, 3,57, // PCB 17

	3,41,  3,42,  3,43, // PCB 14 1
	3,29,  3,30,  3,31, // PCB 13 1

	3,58,  3,59,  3,60,  3,61, 3,62,  3,63, // PCB 16 5

	3,44,  3,45, 3,46, // PCB 14 2
	3,32,  3,33, 3,34, // PCB 13 2
	2,75,  2,76, //PCB 9
	2,83,  2,84,  2,85, // PCB 10 line 2

	3,47,  3,48, 3,49, // PCB 14 3
	3,35,  3,36, 3,37, // PCB 13 3
	2,77,  2,78,  2,79,  2,80,  2,81,  2,82,  //PCB 10

	3,50,  3,51, 3,52, // PCB 14 4
	3,38,  3,39, 3,40, // PCB 13 4

	3,17, 3,20, // PCB16 5

};

const user::Midi_fixture_types ButtonTypeMapping[210] =
{
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 1 Top
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 2 Top
		user::Button_W,user::Button_W,user::Button_W,user::Button_W,user::Nothing, // PCB 1 Potard

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 1 Bottom
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 2 Bottom
		user::Button_W,user::Button_W,user::Button_W,user::Button_W,user::Nothing, // PCB 2 Potard

		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 3 Top
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 4 Top
		user::Button_W,user::Button_W,user::Button_W,user::Button_W,user::Nothing, // PCB 3 Potard

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 3 Bottom
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 4 Bottom
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 12 1

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 5 Top
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 6 Top
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 12 2

		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 5 Bottom
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 6 Bottom
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 12 3

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Nothing, // PCB 16 1
		user::Button_W_1Led,user::Button_W_1Led, //PCB 15 1
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 21
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 12 4

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Nothing, // PCB 16 2
		user::Button_W_1Led,user::Button_W_1Led, //PCB 15 2
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 22
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB 12 5

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Nothing, // PCB 16 3
		user::Button_W_1Led,user::Button_W_1Led, //PCB 15 3
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 22
		user::Button_W,user::Button_W,user::Nothing,user::Nothing,user::Nothing, // PCB 9

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Nothing, // PCB 16 4
		user::Button_W_1Led,user::Nothing, //PCB 15 4
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, //PCB 17
		user::Nothing,user::Nothing,

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 13 1
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 14 1
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB18
		user::Nothing,user::Nothing,user::Nothing,

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 13 2
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 14 2
		user::Button_W,user::Button_W, // PCB 8
		user::Button_W_2Led,user::Button_W_2Led,user::Button_W_2Led, // PCB10 line 2
		user::Nothing,user::Nothing,user::Nothing,user::Nothing,

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 13 3
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 14 3
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB10 line 1
		user::Nothing,

		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 13 4
		user::Button_W_1Led,user::Button_W_1Led,user::Button_W_1Led, // PCB 14 4
		user::Button_W_1Led,user::Nothing,user::Nothing,user::Button_W_1Led, // PCB 16 5
		user::Nothing,user::Nothing,user::Nothing,user::Nothing,

};

const uint8_t ButtonGreenLedMapping[NB_GREEN_LED][2] =
{
		2,0,  2,1,  2,2,  2,3,  2,4, // PCB1 Top

		5,0,  5,1,  5,2,  5,3,  2,4, // PCB2 Top

		8,0,  8,1,  8,2,  8,3,  8,4, // PCB3 Top

		11,0,  11,1,  11,2,  11,3,  11,4, // PCB4 Bottom

		23,0,  23,1,  23,2,  23,3,  23,4, // PCB12 1

		24,0,  24,1,  24,2,  24,3,  24,4, //PCB12 2

		14,0,  14,1,  14,2,  14,3,  14,4, // PCB5 Bottom

		15,0,  15,1,  15,2,  15,3,  15,4, // PCB6 Bottom

		25,0,  25,1,  25,2,  25,3,  25,4, // PCB12 3

		26,0,  26,1,  26,2,  26,3,  26,4, // PCB12 4

		27,0,  27,1,  27,2,  27,3,  27,4, // PCB12 5

		27,0,  27,1,  27,2,  27,3,  27,4, // PCB12 5

		35,3,  35,4,  35,5 // PCB 10

};

const uint8_t ButtonRedLedMapping[NB_RED_LED][2] =
{
		0,0,  0,1,  0,2,  0,3,  0,4,// PCB1 top
		3,0,  3,1,  3,2,  3,3,  3,4, // PCB2 top

		1,0,  1,1,  1,2,  1,3,  1,4,// PCB1 Bottom
		4,0,  4,1,  4,2,  4,3,  4,4, // PCB2 Bottom

		6,0,  6,1,  6,2,  6,3,  6,4,// PCB3 Top
		9,0,  9,1,  9,2,  9,3,  9,4, // PCB4 Top

		7,0,  7,1,  7,2,  7,3,  7,4,// PCB3 Bottom
		10,0,  10,1,  10,2,  10,3,  10,4, // PCB4 Bottom

		18,0,  18,1,  18,2,  18,3,  18,4, // PCB12 1

		12,0,  12,1,  12,2,  12,3,  12,4,// PCB5 Top
		16,0,  16,1,  16,2,  16,3,  16,4, // PCB6 Top

		19,0,  19,1,  19,2,  19,3,  19,4, // PCB12 2

		13,0,  13,1,  13,2,  13,3,  13,4,// PCB5 Bottom
		17,0,  17,1,  17,2,  17,3,  17,4, // PCB6 Bottom

		20,0,  20,1,  20,2,  20,3,  20,4, // PCB12 3

		41,0,  41,1,  41,2,  41,3,  41,4, // PCB16 1

		32,0,  33,0,  // PCB15 1

		36,0,  37,0, 38,0, // PCB 21

		21,0,  21,1,  21,2,  21,3,  21,4, // PCB12 4

		42,0,  42,1,  42,2,  42,3,  42,4, // PCB16 2

		32,1,  33,1,  // PCB15 2

		36,2,  37,2, 38,2, // PCB 22

		21,0,  21,1,  21,2,  21,3,  21,4, // PCB12 5

		43,0,  43,1,  43,2,  43,3,  43,4, // PCB16 3

		32,2,  33,2,  // PCB15 3

		36,3,  37,3, 38,3, // PCB 22

		44,0,  44,1,  44,2,  44,3,  44,4, // PCB16 4

		32,3,  // PCB15 3

		31,0,  31,1, 31,2,  31,3,  31,4,   // PCB17

		28,0,  29,0, 30,0,    // PCB14 1

		28,4,  29,4, 30,4,    // PCB13 1

		39,0, 39,1, 39,2, 40,3, 40,4, 40,5, // PCB 18

		28,1,  29,1, 30,1,    // PCB14 2

		28,5,  29,5, 30,5,    // PCB13 2

		35,0, 35,1, 35,2, //PCB 10 line 2

		28,2,  29,2, 30,2,    // PCB14 3

		28,6,  29,6, 30,6,    // PCB13 3

		34,0, 34,1, 34,2, 34,3, 34,4, 34,5, //PCB 10 line 2

		28,3,  29,3, 30,3,    // PCB14 4

		28,7,  29,7, 30,7,    // PCB13 5

		44,0,  44,4,    // PCB16 5
};

void createAllButton(std::vector<MidiFixture*> *  MdiList);
void createGreenLedButton(ButtonGreenLed * Bt);
void createRedLedButton(ButtonRedLed * Bt);
void createNoLedButton(MidiFixtureImpl * Bt);



#endif /* INC_MIDIFIXTURE_MIDIMAPPING_HPP_ */
