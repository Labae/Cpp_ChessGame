#pragma once

// Includes
#include <Windows.h>
#include <iostream>

#include "ChessBoard.h"
#include "Queue.h"

class ChessGraphics
{
public:
	ChessGraphics();
	~ChessGraphics();

	bool Initialize();
	bool Render(ChessBoard* board, Queue<Vector2<int>>* inputLog, ChessPieces* selectedPiece, const int& team, const bool& gameover);
	void Shutdown();

	char* ToChar(const ChessPieces* piece);
	void ShowPath(ChessBoard* board, const ChessPieces* piece);
	void RenderInformation(const int& team, const bool& gameover);

private:
  char* m_RenderTarget[9][9];
};

