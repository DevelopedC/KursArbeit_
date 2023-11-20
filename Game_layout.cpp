#pragma once

#include "Game_layout.h"

using namespace Game_layout;


Playing_field::Playing_field()// ����������� ������� ����
{
	// ������� ��� (���)
	f.loadFromFile("photo/playing_field.jpg"); // ������� � ����� ����������   
	fon.setTexture(f); // ������� � ������ �������� �� ������ ����������
};


void Playing_field::Create_First_Player_Me()  // ������������ ���� � ������� � ��������
{
	Cards.loadFromFile("photo/set_of_cards.jpg"); 
}

void Playing_field::Table_Score_Enemy()  // ����������� ������� ������
{
    // ���������� � ������ �������
	pl_enemy.loadFromFile("photo/enemy_name.png"); // ������������ ����������
	Player_Enemy.setTexture(pl_enemy); // ������� � ������       
	Player_Enemy.setPosition(10, 80); // ������������ �������     


	// - ����� ������� ������ � ����������
	sc_enemy.loadFromFile("photo/numbers.png");

	for (int i = 0; i < 2; i++) // ����� ������� ������
	{
		score_enemy[i].setTexture(sc_enemy);
		score_enemy[i].setPosition(300 + 25 * i, 136);
		score_enemy[i].setTextureRect(IntRect(0, 0, 25, 79));
	}


	// ����� ������� ����.
	ns_enemy.loadFromFile("photo/inscription.png");
	nadscore_enemy.setTexture(ns_enemy);
	nadscore_enemy.setPosition(10, 140);
}

void Playing_field::Table_Score_Player()// ����������� ������� ��������� ������
{
	// ���������� � ������ �������
	nm_playerYou.loadFromFile("photo/player_name.png");
	name_playerYou.setTexture(nm_playerYou);
	name_playerYou.setPosition(10, 750);


	// ����� ������� ������ � ������
	sc_playerYou.loadFromFile("photo/numbers.png");

	for (int i = 0; i < 2; i++) // ����� ������� ������
	{ 
        score_playerYou[i].setTexture(sc_playerYou);  
        score_playerYou[i].setPosition(300 + 25 * i, 808);  
        score_playerYou[i].setTextureRect(IntRect(0, 0, 25, 79));  
	}


	// ����� ������� ����.
	Img_score_playerYou.loadFromFile("photo/inscription.png");
	Image_score_playerYou.setTexture(Img_score_playerYou);
	Image_score_playerYou.setPosition(10, 810);
}

 