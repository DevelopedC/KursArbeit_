#pragma once

#include "Additional_Actions.h"

using namespace Additional_Actions;

namespace Basis_of_the_game // ������ ���
{
	class Life_cycle // ������� ����
	{
	public:
	 
		Add_func create_delete_cards; // ��������� ��`���� �����, �� ������� ������ � 7 ���� ���� �������, �� ������� ����� � ������ �������
		 
		int axis_offset = 0; // ������� ����, ��� �� �������� ������� ��� ������

		int x_start_pos = 600, y_start_pos = 850; // ���� ��������� ������ ������ ����� (��������� ������) (X_Pos_card_playerYou,Y_Pos_card_playerYou)

		bool me_go = true; // ������, �� ������ �������� �������
		bool me_fair = false; // ������, �� ������� ������� ����������
		bool enemy_go = false; // ������, �� ��������� ������
		bool enemy_fair = false; // ������, �� ��������� ����������

		bool prov_enemy_fair = false; // �������� �� �������, �� ��������� ���� �������� ���� �����
		bool nothing_beat = false; //  �������� �� �������, �� �������� ������� ���� �������� ���� ����� (����� try � ������� ���� �����)

		int axis_y = 0;// ����� ��� ������� �����, � �������� ������� �� ����� ��������� ������

		int offset = 0;  // ����� ��� ������� �����, � �������� ������� �� ����� ����������

		void Play_Logic(); // ������� �-��� ���, �� ������� �� ������� ���� ���''
	};
}
 
 