#pragma once

#include "Game_layout.h"
#include "Logic.h"

using namespace Game_layout;
using namespace Logic_game;
 

namespace Field_data
{
	class Fill_field : public Playing_field, public Logics
	{
		public:

		int array_of_cards_Enemy = 7;    // зм≥на дл€ запису та виводу на екран к-ст≥ карт противника
		int array_of_cards_You = 7; // зм≥на дл€ запису та виводу на екран к-ст≥ карт основного гравц€
		 
		int Look_for_button_cards = 7; // зм≥нна дл€ пошуку карти, на €ку було натисканн€ миш≥

		void Show_Table_Score(); // ф-ц≥€, що в≥дпов≥даЇ за зм≥ну к-ст≥ карт противника

		void Show_Table_Score_Player(); // ф-ц≥€, що в≥дпов≥даЇ за зм≥ну к-ст≥ карт основного гравц€

		void Play_First_Player_Me(); // початок гри, створюЇмо спрайт на 7 карт, заповнюЇмо картами ≥грове поле(колоду основного гравц€)

		void Play_Enemy_Player_1(); // початок гри, створюЇмо спрайт на 7 карт, заповнюЇмо картами ≥грове поле(колоду противника)

		void Card_Draw_Player_me(); // ф-ц≥€ добору карт основному гравцю

		void Card_Draw(); //  ф-ц≥€ добору карт противнику  
	};
}