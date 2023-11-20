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

		int array_of_cards_Enemy = 7;    // ���� ��� ������ �� ������ �� ����� �-�� ���� ����������
		int array_of_cards_You = 7; // ���� ��� ������ �� ������ �� ����� �-�� ���� ��������� ������
		 
		int Look_for_button_cards = 7; // ����� ��� ������ �����, �� ��� ���� ���������� ����

		void Show_Table_Score(); // �-���, �� ������� �� ���� �-�� ���� ����������

		void Show_Table_Score_Player(); // �-���, �� ������� �� ���� �-�� ���� ��������� ������

		void Play_First_Player_Me(); // ������� ���, ��������� ������ �� 7 ����, ���������� ������� ������ ����(������ ��������� ������)

		void Play_Enemy_Player_1(); // ������� ���, ��������� ������ �� 7 ����, ���������� ������� ������ ����(������ ����������)

		void Card_Draw_Player_me(); // �-��� ������ ���� ��������� ������

		void Card_Draw(); //  �-��� ������ ���� ����������  
	};
}