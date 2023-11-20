#pragma once

#include "Field_data_.h"

using namespace Field_data;

 
void Fill_field::Show_Table_Score() // �������� ���� ����������
{
 
    if (array_of_cards_Enemy < 9)
    {
        score_enemy[1].setTextureRect(IntRect(array_of_cards_Enemy * 25, 0, 25, 79));

        score_enemy[0].setTextureRect(IntRect(0 * 25, 0, 25, 79));
    }
    else
    {
        score_enemy[1].setTextureRect(IntRect((array_of_cards_Enemy % 10) * 25, 0, 25, 79));    

        score_enemy[0].setTextureRect(IntRect((array_of_cards_Enemy / 10) * 25, 0, 25, 79));
    }
    
}

void Fill_field::Show_Table_Score_Player() // �������� ���� ��������� ������
{

    if (array_of_cards_You < 9)
    {
        score_playerYou[1].setTextureRect(IntRect(array_of_cards_You * 25, 0, 25, 79));

        score_playerYou[0].setTextureRect(IntRect(0 * 25, 0, 25, 79));
    }
    else
    {
        score_playerYou[1].setTextureRect(IntRect((array_of_cards_You % 10) * 25, 0, 25, 79));

        score_playerYou[0].setTextureRect(IntRect((array_of_cards_You / 10) * 25, 0, 25, 79));
    }

}

void Fill_field::Play_First_Player_Me() // ������� ���, ��������� ������ �� 7 ����, ���������� ���������
{
	 // �������� �������
 	player_you.resize(7); // ��������� ������ ������� �� 7 ��������

	for (int i = 0; i < 7; i++)
	{
		player_you[i].setTexture(Cards); // ������� ���������� ������ ���� � �����
		Logic_Spawn_card_MyPlayer(i); // ������ �-���, �� ������ ����� � ����������� ������� � �����
	}

}

void Fill_field::Play_Enemy_Player_1() // ��������� ���������� ������ �� 7 ��.
{
	player_enemy.resize(NumberOfCards_EnemyPlayer); // ��������� ������ ������� �� 7 ��������

	for (int i = 0; i < 7; i++)
	{
		player_enemy[i].setTexture(Cards); // ������� ���������� ������ ���� � �����
		Logic_Spawn_card_enemy_1(i);  // ������ �-���, �� ������ ����� � ����������� ������� � �����
	}
}

void Fill_field::Card_Draw() // ������� ��������� ����� ���������� � ��� ������� ������
{
	NumberOfCards_EnemyPlayer += 1; // ��������� ��������� ���� � ����� 

	 array_of_cards_Enemy += 1; // ��������� ��������� ���� � ������������� ����

	int card; // ��������� �����, ��� ������ ���� ������

	for (int i = 0; i < 1; i++) // ���� ������ ��������� ������
	{
        card = rand() % 40 + 1; // ������� ������ �� 1 �� 40

		if (card == 10 || card == 20 || card == 30 || card == 40) // �������� �� �������� ������
		{
			i -= 1;
			continue;
		}
	}

	Cards_player_enemy.push_back(card); // ����� ������ ������ ������ � �������� �����

	player_enemy.resize(NumberOfCards_EnemyPlayer); // ���� ������ ������ �������

	player_enemy[NumberOfCards_EnemyPlayer - 1].setTexture(Cards); // ����� � ����� ������� ������, ��������

	Logic_Spawn_card_enemy_1(NumberOfCards_EnemyPlayer - 1); // ������ �-���, �� ������ ����� � ����������� ������� � �����

}


void Fill_field::Card_Draw_Player_me() // ���� ���� ��������� ������
{
	Look_for_button_cards++; // ��������� ����� ��� ������ ��������� ������

	 array_of_cards_You += 1;  // ��������� ��������� ���� � ������������� ����

	NumberOfCards_YouPlayer++; // ��������� ��������� ���� � ����� 

	int card; // ��������� �����, ��� ������ ���� ������

	for (int i = 0; i < 1; i++)  // ���� ������ ��������� ������
	{
		card = rand() % 40 + 1;  // ������� ������ �� 1 �� 40

		if (card == 10 || card == 20 || card == 30 || card == 40)  // �������� �� �������� ������
		{
			i -= 1;
			continue;
		}

	}

	Cards_player_you.push_back(card);  // ����� ������ ������ ������ � �������� �����

	player_you.resize(NumberOfCards_YouPlayer); // ���� ������ ������ �������

	player_you[NumberOfCards_YouPlayer - 1].setTexture(Cards);  // ����� � ����� ������� ������, ��������

	Logic_Spawn_card_MyPlayer(NumberOfCards_YouPlayer - 1); // ������ �-���, �� ������ ����� � ����������� ������� � �����
}