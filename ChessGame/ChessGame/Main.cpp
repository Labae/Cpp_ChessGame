#include "ChessManager.h"

#include <Windows.h>

int main()
{
	ChessManager* chessManager;
	chessManager = new ChessManager();
	if (!chessManager)
	{
		return 0;
	}

	bool result = chessManager->Initialize();
	if (result)
	{
		while (chessManager->Run())
		{

		}
	}

	chessManager->Shutdown();
	delete chessManager;
	chessManager = 0;

	return 0;
}