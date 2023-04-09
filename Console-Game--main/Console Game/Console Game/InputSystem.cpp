#include <windows.h>
#include <cassert>
#include "InputSystem.h"
#include <iostream>
#include <conio.h>

namespace global
{
	namespace input
	{
		bool inputKeyTable[MAX_KEY]; // 정의된 5개의 키 값을 처리 합니다.

		// Helper Functions ..
		void Set(const int keyIdx, bool bOn)
		{
			assert(keyIdx >= 0 && keyIdx < MAX_KEY); // 방어 코드를 작성하는 것에 익숙해져야 합니다.  배열을 다룰 때는 인덱스를 조심해야 합니다!!

			inputKeyTable[keyIdx] = bOn;			// bool 타입을 활용 합시다.
		}

		bool IsLeftKeyOn()
		{
			return inputKeyTable[LEFT_KEY_INDEX];
		}

		bool IsRightKeyOn()
		{
			return inputKeyTable[RIGHT_KEY_INDEX];
		}

		bool IsUpKeyOn()
		{
			return inputKeyTable[UP_KEY_INDEX];
		}

		bool IsDownKeyOn()
		{
			return inputKeyTable[DOWN_KEY_INDEX];
		}

		// 입력 키값에 대해 알아 봅시다. 블러킹과 넌블러킹에 대해서만 이해하고 가기로 합니다!!
		// * 비트 연산에 대해 학습합니다. & 와 && 은 달라요. 
		// &, * 연산자가 맥락에 따라 다르게 해석되는 것에 주의 해야 합니다. 
		void UpdateInput()
		{
			/*if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				global::input::Set(ESCAPE_KEY_INDEX, true);
			}*/

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) //왼쪽
			{
				global::input::Set(LEFT_KEY_INDEX, true);
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) //오른쪽
			{
				global::input::Set(RIGHT_KEY_INDEX, true);
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000) //위
			{
				global::input::Set(UP_KEY_INDEX, true);
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000) //아래
			{
				global::input::Set(DOWN_KEY_INDEX, true);
			}
		}

		int keyControl()
		{
			
			char temp = _getch();

			if (temp == 'w' || temp == 'W' || temp == 72)
			{
				return UP_KEY_INDEX;
			}
			else if (temp == 's' || temp == 'S' || temp == 80)
			{
				return DOWN_KEY_INDEX;
			}
			else if (temp == 'a' || temp == 'A' || temp == 75)
			{
				return LEFT_KEY_INDEX;
			}
			else if (temp == 'w' || temp == 'W' || temp == 77)
			{
				return RIGHT_KEY_INDEX;
			}
			else if (temp == ' ')
			{
				return SUBMIT;
			}

			else if (temp == 27)
			{
				return ESC;
			}

		}

		char answerKey()
		{
			int n = 0;
			if (_kbhit)
			{
				bool b_answerSelect = false;
				while (b_answerSelect==false)
				{
					n = _getch();
					switch (n)
					{
					case '1':
					{
						b_answerSelect = true;

						return '1';
						break;
					}
					case '2':
					{
						b_answerSelect = true;
						return '2';
						break;
					}
					case '3':
					{
						b_answerSelect = true;
						return '3';
						break;
					}
					case '4':
					{
						b_answerSelect = true;
						return '4';
						break;
					}
					case '5':
					{
						b_answerSelect = true;
						return '5';
						break;
					}
					default:
						break;
					}
				}
				
			}
		}
	};
};