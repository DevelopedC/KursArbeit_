#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>

using namespace sf;

namespace Game_layout
{
	class Playing_field
	{ 
	public:

		// ��� ���
		Texture f; // ��������� �������� 
		Sprite fon; // ��������� �������  

		// �����
	    Texture Cards; // ��������, ���� ����������������� � ���������� ��� ���� �������


		//------- ���� ����� ������
		
		// ˳������� ����
		Texture sc_enemy;   
		Sprite score_enemy[2];  

		// ����� "�-��� ����"
		Texture ns_enemy; 
		Sprite nadscore_enemy; 

		// ��'� ������
		Texture pl_enemy; 
		Sprite Player_Enemy;  

		//-------- ���� ����� �������� ������

		// ˳������� ����
		Texture sc_playerYou;  
		Sprite score_playerYou[2];

		// ����� "�-��� ����"
		Texture Img_score_playerYou; 
		Sprite  Image_score_playerYou; 

		// ��'� ������
		Texture nm_playerYou; 
		Sprite name_playerYou; 


		Playing_field(); // ��������� �������� ������� ����

		void Create_First_Player_Me(); // ���������� �������� ��������� ��� ����
		 
		void Table_Score_Enemy(); // ����������� ������� ������

		void Table_Score_Player(); //����������� ������� ��������� ������

		 
	};
}
