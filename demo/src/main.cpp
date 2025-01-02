#include <iostream>
#include "Table.h"

using namespace mahjong;

int main()
{
	Table t;
	t.game_init();
	fmt::print("{}\n", t.to_string());
	return 0;
}
