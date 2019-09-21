#pragma once

// Includes
#include "ChessPieces.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();

	bool Initialize(bool standard = true);
	void Shutdown();

	ChessPieces* GetChessPiece(int x, int y);
public:
	ChessPieces* m_Board[8][8];
};

