#pragma once

#include "Additional_Actions.h"

using namespace Additional_Actions;

namespace Basis_of_the_game // основа гри
{
	class Life_cycle // життєвий цикл
	{
	public:
	 
		Add_func create_delete_cards; // створення об`єкту класу, що створює колоду з 7 карт двом гравцям, та видаляэ карти з колоди гравців
		 
		int axis_offset = 0; // зміщення карт, щоб між відбитими картами був простір

		int x_start_pos = 600, y_start_pos = 850; // змінні координат пошуку нажатої карти (основного гравця) (X_Pos_card_playerYou,Y_Pos_card_playerYou)

		bool me_go = true; // прапор, що ходить основний гравець
		bool me_fair = false; // прапор, що оновний гравець відбивається
		bool enemy_go = false; // прапор, що противник ходить
		bool enemy_fair = false; // прапор, що противник відбивається

		bool prov_enemy_fair = false; // перевірка на можливо, що противник буде відбивати свою карту
		bool nothing_beat = false; //  перевірка на можливо, що основний гравець буде відбивати свою карту (когда try я отбиваю свою карту)

		int axis_y = 0;// змінна для зміщення карти, в ситуації відбиття своєї карти основного гравця

		int offset = 0;  // змінна для зміщення карти, в ситуації відбиття своєї карти противника

		void Play_Logic(); // основна ф-ція гри, що відповідає за життєвий цикл гри''
	};
}
 
 