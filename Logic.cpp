#pragma once 

#include <ctime>
#include <time.h>

#include "PlayForm.h"
#include "Logic.h"
 

void Logics::Logic_Spawn_card_MyPlayer(int i)  // �������, �� �� �������� � ��������� ������ ���� ����� �� ��������� �� � �����, �� ���� �� ������� ��������� ������
{
		int X_card_pos, Y_card_pos; // �������� ����, ��� ������ ��������� �����

		X_Pos_card_playerYou += 98; // ������� ������� ������� �� ���� �����, ��� ������ ����

		if (Cards_player_you[i] < 10) // ����� ��������� ��� �����, ���� ���� ����� 10 � ������ ���� 
		{
			X_card_pos = Cards_player_you[i] - 1; // ����������� ������� �
			Y_card_pos = 0; // �� � ������ ���� 0
		}
		else // ������, ���� �� ����� � ������� ������ �����
		{
			X_card_pos = (Cards_player_you[i] % 10) - 1; // ������ ���������� �� �,  ������� �� ������
			Y_card_pos = (Cards_player_you[i] / 10); // ������ ���������� �� �
		}


		player_you[i].setTextureRect(IntRect((X_card_pos * 99), (Y_card_pos * 155), 99, 155)); // ������ � �������, �� ���������� ���� ����, 
																		// ��� ������� �� ���� ���������� ���� �����
		player_you[i].setPosition(X_Pos_card_playerYou, Y_Pos_card_playerYou); // ������� � ��� � ��� ��������� �������, ����
}


void Logics::Logic_Spawn_card_enemy_1(int i) // �������, �� �� ��������� � ��������� ������ ���� ����� �� ���������� �� �� �����, �� ���� �� ������� ������
{
	int X_card_pos; // ������� ����, ��� ������ ��������� �����
	int Y_card_pos;

	X_Pos_card_playerEnemy += 98; // ������� ������� ������� �� ���� �����, ��� ������ ����

	if (Cards_player_enemy[i] < 10)
	{
		X_card_pos = Cards_player_enemy[i] - 1;
		Y_card_pos = 0;
	}
	else
	{
		X_card_pos = (Cards_player_enemy[i] % 10) - 1; // ������ ���������� �� �,  ������� �� ������
		Y_card_pos = (Cards_player_enemy[i] / 10);     // ������ ���������� �� �
	}

	player_enemy[i].setTextureRect(IntRect((X_card_pos * 99), (Y_card_pos * 155), 99, 155)); // ������ � �������, ��������� �� �����. ���� ������
	player_enemy[i].setPosition(X_Pos_card_playerEnemy, Y_Pos_card_playerEnemy); // ������� � ��� � ��� ��������� �������, ����

}


int Logics::proverka_card_me_player(int time_card) // ����� ��������� ������, �� �������� �� ������� ����� ���� ����� ���� ������� ������ ����� ����� �� ���
{													 

		for (int it = 0; it < NumberOfCards_YouPlayer; it++) // �������� �� �-�� ���� � �����
		{
			int cards_enemy = Cards_player_you[it];  // ������ ����� � ������ ��������� ������

			for (int a = 1; a < 5; a++)
			{
				// �������� ���� ��������� �� ��������
				if (time_card >= Iterator_start[a - 1] &&
					time_card <= Iterator_end[a - 1] &&
					cards_enemy >= Iterator_start[a - 1] &&  // �������� �����, ����� ������� ��������
					cards_enemy <= Iterator_end[a - 1])
				{
					return it; // ���� ���� ����� �, ���������� �� �����
				}
			}
		}


		for (int i = 0; i < NumberOfCards_YouPlayer; i++)
		{
				int proverka_1 = time_card % 10; 
				int proverka_2 = Cards_player_you[i] % 10;

				// ���� �� �������� �� ������, ����� ������� �� ����� ����� ������� ����� (��� �� ��������)
				if (proverka_1 == proverka_2) {	return i; }
		}


	return -2; // ���� ���� ���� ������, ��������� -2
}


int Logics::Enemy_Player_turn()  // �-���, �� ������� ��������� �����, ���� ���� �������� �����
{
	int number_card = Cards_player_enemy.size(); // ������ ������ ���� ������ ����������

	if (Cards_player_enemy.size() != 1) { number_card--; } // ���� ����� ���� �� ������ 1, �� �������� ��������

	number_card = rand() % number_card + 0; // ���� ����� � ������, ���� ������� ��������

	return number_card; // ��������� ����� ���� �����
}
