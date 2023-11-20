#pragma once

#include "Additional_Actions.h"

using namespace Additional_Actions; 
 

void Add_func::Random_Cards_Players() // ������� ���������� ����, ��������� ������
{

	srand(time(NULL)); // ���� ��� ��������� ���������������� �����

	for (int a = 0; a < initial_number_of_cards; a++) // ����, �� ���������� ����� ������ 7 �����,  
	{								// �� ������ ���������� ��� ���� �� �������� ���
		int card = rand() % 40 + 1; // ������� ����, �� 1 �� 40

		if (card == 10 || card == 20 || card == 30 || card == 40) // ������ ���������, 
		{										// � ��� ���� ������ ���������� ������ ���� �� �� ����������������,
			a -= 1;								// ��������� ���� �� ���� ��������, �� �������� �������� �����
			continue;
		}

		CreateDrawCounter.Cards_player_you.push_back(card); // ���� ����� ��������, ������ � ����� ����� �����
	}

}

void Add_func::Random_Cards_Players_enemy_1() // ������� ���������� ����, ����������
{

	for (int a = 0; a < initial_number_of_cards; a++) // ����, �� ���������� ����� ������ 7 �����, ������ ����
	{
		int card = rand() % 40 + 1;

		if (card == 10 || card == 20 || card == 30 || card == 40)
		{
			a -= 1;
			continue;
		}

		CreateDrawCounter.Cards_player_enemy.push_back(card); // ������ � ����� ������ ����
	}

}

void Add_func::Delete_MeCards(int i) // �-���, �� ������� � ������ ��������� ������ �����, �� ������� �� � ����� ���� �� ���������� ����  
{										 
	CreateDrawCounter.Look_for_button_cards--; // �������� ����� ��������, ��� ������ ������� ����� (������ ������)

	CreateDrawCounter.X_Pos_card_playerYou -= 99; // ��������� ����� � ��� ���������� ��������� ���� �� �������� ��� �� ��������� (�)
	CreateDrawCounter.array_of_cards_You -= 1; // ��������� ��������� �-�� ���� 

	int size_vector = CreateDrawCounter.player_you.size(); // ������ ������ �������, �� ����������� �����
	size_vector -= (i + 1); // �������� �� �-�� ���� � ����� ����� ��������� ����� ��� ���� ��������, ��� �������� �-��� ����,
							//��� ��������� ����������� � �� �������� ����� 


	CreateDrawCounter.NumberOfCards_YouPlayer -= 1; // �������� ����� ������ ���� �� ������� ��������� ������
	Time_player_card_size += 1; // �������� �������� ���� ��������� ������, �� ��������� � ����

	 
	TIME_Cards_player_me = CreateDrawCounter.Cards_player_you[i]; // �������� ����� � ��������� ����� 
	CreateDrawCounter.Cards_player_you.erase(CreateDrawCounter.Cards_player_you.begin() + i); // ��������� ����� � ��������� ������
	 


	CreateDrawCounter.Time_player_cards.push_back(CreateDrawCounter.player_you[i]); // �������� ����� �� ����������� ������ �������
	CreateDrawCounter.player_you.erase(CreateDrawCounter.player_you.begin() + i); // ��������� ����� � ������ �������


	for (int iter = 0; iter < size_vector; iter++) // ������� ��� ���� ���� ��������, � �� �� ������� ������
	{
		CreateDrawCounter.player_you[i].setPosition(600 + (98 * (i)), 850); // 600 �-���������� �� � - 850 , � ��� ���������� ��������� ����
		i++;
	}

}

void Add_func::Delete_CardsEnemy(int i) // �-���, �� ������ �������� ����� ��� ���� �������� � ������ ����������  
{
	CreateDrawCounter.X_Pos_card_playerEnemy -= 98; // ��������� ����� � ��� ���������� ��������� ���� �� �������� ��� �� ��������� (�)

     
	CreateDrawCounter.array_of_cards_Enemy -= 1; // ��������� ��������� �-�� ���� ���������� 

	int size_vector = CreateDrawCounter.player_enemy.size();
	size_vector -= (i + 1); // ����� �-�� ���� ���� ��������, �� ��������� ���� ���������� � �� ������� ������

	CreateDrawCounter.NumberOfCards_EnemyPlayer -= 1; // �������� ����� ������ ���� �� ������� ����������
	Time_EnemyPlayer_card_size += 1; // �������� �������� �-�� ���� ������, �� ��������� � ����

 
	TIME_Cards_player_enemy_1 = CreateDrawCounter.Cards_player_enemy[i];  // �������� ����� � ��������� ����� 
	CreateDrawCounter.Cards_player_enemy.erase(CreateDrawCounter.Cards_player_enemy.begin() + i); // ��������� ����� � ��������� ������


	CreateDrawCounter.Time_EnemyPlayer_cards.push_back(CreateDrawCounter.player_enemy[i]); // �������� ����� �� ����������� ������ �������
	CreateDrawCounter.player_enemy.erase(CreateDrawCounter.player_enemy.begin() + i); // ��������� ����� � ������ �������


	for (int iter = 0; iter < size_vector; iter++) // ������� ��� ���� ���� ��������, � �� �� ������� ������
	{
		CreateDrawCounter.player_enemy[i].setPosition(600 + (98 * (i)), 100);
		i++;
	}
}

int Add_func::Logic(int time) // ����� �����������
{
	// �������� ����, �� ������ ���������� ��� �������� ����
	int card_me = time; // ����� �����, �� ���� ������ � ����� ��������� �-��� 
	int cards_enemy;

	for (int a = 1; a < 5; a++) // ����� ���� ��������� �� ��������
	{
		for (int i = 0; i < CreateDrawCounter.NumberOfCards_EnemyPlayer; i++)
		{	 
			cards_enemy = CreateDrawCounter.Cards_player_enemy[i]; // ����� ���� ������
	 
			if (card_me >= CreateDrawCounter.Iterator_start[a - 1] && // �������� ����, �� ����� ������ � ��������� ����  
				card_me <= CreateDrawCounter.Iterator_end[a - 1] && // � ����� ���� �� ������� �� ����� ���� �� ��������
				cards_enemy >= CreateDrawCounter.Iterator_start[a - 1] &&  // �� ����, �� � ���������� � �����,���� ���� ����� � ��������� �� �����
				cards_enemy <= CreateDrawCounter.Iterator_end[a - 1])
			{
				return i;
			}
		}
	}


	for (int i = 0; i < CreateDrawCounter.NumberOfCards_EnemyPlayer; i++) // �������� ���� ��������� �� �������
	{
		if (card_me <= 40 && CreateDrawCounter.Cards_player_enemy[i] <= 40) 
		{
			int proverka_1 = card_me % 10; 
			int proverka_2 = CreateDrawCounter.Cards_player_enemy[i] % 10;

			if (proverka_1 == proverka_2) { return i; } // ��������� ������� �� ������ ������ �����, 
														// �� ���� ���������� ������ ����� ����-����� �������
		}
	}

	return -1; // ���� �� ���� �������� ����� ���� ����� ������ ��������� -1
}

 