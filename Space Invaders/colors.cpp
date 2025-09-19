#include "colors.h"

const Color darkGrey = { 26, 31, 40, 255 };
const Color green = { 47, 230, 23, 255 };
const Color red = { 255, 0 , 0, 255 };
const Color orange = { 226, 116, 17, 255 };
const Color yellow = { 237, 234, 4, 255 };
const Color purple = { 170, 4, 237, 255 };
const Color cyan = { 21, 204, 209, 255 };
const Color blue = { 4, 66, 237, 255 };

std::vector<Color> GetCellColors()
{
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}