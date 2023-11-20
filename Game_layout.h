#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>

using namespace sf;

namespace Game_layout
{
	class Playing_field
	{ 
	public:

		// ‘он гри
		Texture f; // створенн€ текстури 
		Sprite fon; // створенн€ спрайту  

		//  арти
	    Texture Cards; // текстура, буде використовуватис€ в подальшому дл€ обох гравц≥в≥


		//------- Ѕлок табло ворога
		
		// Ћ≥чильник карт
		Texture sc_enemy;   
		Sprite score_enemy[2];  

		// напис "к-сть карт"
		Texture ns_enemy; 
		Sprite nadscore_enemy; 

		// ≤м'€ гравц€
		Texture pl_enemy; 
		Sprite Player_Enemy;  

		//-------- Ѕлок табло основого гравц€

		// Ћ≥чильник карт
		Texture sc_playerYou;  
		Sprite score_playerYou[2];

		// напис "к-сть карт"
		Texture Img_score_playerYou; 
		Sprite  Image_score_playerYou; 

		// ≤м'€ гравц€
		Texture nm_playerYou; 
		Sprite name_playerYou; 


		Playing_field(); // стовренн€ картинки ≥гровго пол€

		void Create_First_Player_Me(); // заповненн€ текстури картинкою дл€ карт
		 
		void Table_Score_Enemy(); // статистична таблиц€ ворога

		void Table_Score_Player(); //статистична таблиц€ основного гравц€

		 
	};
}
