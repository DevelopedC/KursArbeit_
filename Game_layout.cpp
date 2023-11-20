#pragma once

#include "Game_layout.h"

using namespace Game_layout;


Playing_field::Playing_field()// Конструктор головне меню
{
	// ігровий фон (стіл)
	f.loadFromFile("photo/playing_field.jpg"); // додання в нього зображення   
	fon.setTexture(f); // додання в спрайт текстуру як фонове зображення
};


void Playing_field::Create_First_Player_Me()  // Завантаження сету з картами в текстуру
{
	Cards.loadFromFile("photo/set_of_cards.jpg"); 
}

void Playing_field::Table_Score_Enemy()  // Статистична таблиця ворога
{
    // зображення з іменем гравцем
	pl_enemy.loadFromFile("photo/enemy_name.png"); // завантаження зображення
	Player_Enemy.setTexture(pl_enemy); // додання в спрайт       
	Player_Enemy.setPosition(10, 80); // налаштування позиції     


	// - цифри кількості карток у противника
	sc_enemy.loadFromFile("photo/numbers.png");

	for (int i = 0; i < 2; i++) // табло кількості карток
	{
		score_enemy[i].setTexture(sc_enemy);
		score_enemy[i].setPosition(300 + 25 * i, 136);
		score_enemy[i].setTextureRect(IntRect(0, 0, 25, 79));
	}


	// напис кількість карт.
	ns_enemy.loadFromFile("photo/inscription.png");
	nadscore_enemy.setTexture(ns_enemy);
	nadscore_enemy.setPosition(10, 140);
}

void Playing_field::Table_Score_Player()// Статистична таблиця основного гравця
{
	// зображення з іменем гравцем
	nm_playerYou.loadFromFile("photo/player_name.png");
	name_playerYou.setTexture(nm_playerYou);
	name_playerYou.setPosition(10, 750);


	// цифри кількості карток у гравця
	sc_playerYou.loadFromFile("photo/numbers.png");

	for (int i = 0; i < 2; i++) // табло кількості карток
	{ 
        score_playerYou[i].setTexture(sc_playerYou);  
        score_playerYou[i].setPosition(300 + 25 * i, 808);  
        score_playerYou[i].setTextureRect(IntRect(0, 0, 25, 79));  
	}


	// напис кількість карт.
	Img_score_playerYou.loadFromFile("photo/inscription.png");
	Image_score_playerYou.setTexture(Img_score_playerYou);
	Image_score_playerYou.setPosition(10, 810);
}

 