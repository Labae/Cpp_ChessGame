#pragma once

// Includes
#include <conio.h>
#include <Windows.h>
#include "ChessBoard.h"
#include "Queue.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	bool Initialize();
	void Shutdown();

	void Input(ChessBoard* board, int& team);

	static int GetPosX();
	static int GetPosY();
	bool IsSelected();
	Queue<Vector2<int>>* GetQueue();
	ChessPieces* GetSelectedPiece();

public:
	static int m_kPosX;
	static int m_kPosY;

private:
	Queue<Vector2<int>>* m_InputPositionLog;
	bool m_Selected;
	ChessPieces* m_SelectedPiece;
};