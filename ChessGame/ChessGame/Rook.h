#pragma once
#include "ChessPieces.h"
class Rook :
	public ChessPieces
{
public:
	Rook(unsigned int team);

	void Move(const int& moveX, const int& moveY) override;

protected:
	Vector2<int>* CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const override;
	unsigned int CalcuratePathCount(ChessPieces* (*board)[8]) const override;
};

