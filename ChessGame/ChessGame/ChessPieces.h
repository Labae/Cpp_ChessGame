#pragma once

// Includes
#include "Vector2.h"

class ChessPieces
{
public:
	enum
	{
		King	 = 0,
		Queen	 = 1,
		Bishop	 = 2,
		Rook	 = 3,
		Knight	 = 4,
		Pawn	 = 5,
	};

	enum
	{
		// À§
		White = 0,
		// ¾Æ·¡
		Black = 1,
	};

public:
	ChessPieces();
	ChessPieces(unsigned int team, unsigned int type, bool selected);
	~ChessPieces();
	ChessPieces(const ChessPieces& other);
	ChessPieces& operator= (const ChessPieces& other);

	void Shutdown();

	void Select();
	void UnSelect();

	void SetPosition(int x, int y);

	virtual void Move(const int& moveX, const int& moveY);

	unsigned int GetType() const;
	unsigned int GetTeam() const;
	bool IsSelected() const;
	Vector2<int>* GetPaths(ChessPieces* (*board)[8], unsigned int pathCount) const;
	unsigned int GetPathCount(ChessPieces* (*board)[8]) const;
	Vector2<int> GetPosition();

protected:
	virtual Vector2<int>* CalcuratePaths(ChessPieces *(*board)[8], unsigned int pathCount) const;
	virtual unsigned int CalcuratePathCount(ChessPieces *(*board)[8]) const;

protected:
	unsigned int m_iTeam;
	unsigned int m_iType;
	bool m_bSelected;
	Vector2<int> m_Position;
};

