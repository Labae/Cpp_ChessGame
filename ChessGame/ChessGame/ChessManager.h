#pragma once

// Includes
#include "ChessGraphics.h"
#include "InputManager.h"
#include "ChessBoard.h"

class ChessManager
{
public:
	ChessManager();
	~ChessManager() = default;
	ChessManager(const ChessManager& other);

	bool Initialize();
	bool Run();
	void Shutdown();

private:
	ChessGraphics* m_ChessGraphics;
	ChessBoard* m_Board;
	InputManager* m_Input;
	int m_Team;
};

