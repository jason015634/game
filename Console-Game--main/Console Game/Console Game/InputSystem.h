#pragma once
namespace global
{
	// �Լ��� ����� ���� ���信 ���� ������ ���ô�.
	// �ʿ��� �������̽��� �����Ѵٴ� ���信 ���� ������ ���ô�.
	namespace input
	{
		// ����� ���� �ϴ� ����� ���� �˾� ���ô�. 
		// const Ű�� #define �� ���̸� �˾ƾ� �մϴ�. ��Ʈ! const �� ������ ���� Ű�����̰� #�� ������ ���������Ͽ� ���� �˴ϴ�.
	
		const int UP_KEY_INDEX = 0;
		const int DOWN_KEY_INDEX = 1;
		const int LEFT_KEY_INDEX = 2;
		const int RIGHT_KEY_INDEX = 3;
		const int SUBMIT = 4;
		const int ESC = 6;
		const int MAX_KEY = 7;

		void Set(const int keyIdx, bool bOn);

		bool IsLeftKeyOn();
		bool IsRightKeyOn();
		bool IsUpKeyOn();
		bool IsDownKeyOn();

		void UpdateInput();
		int keyControl();
		char answerKey();
	};
};
