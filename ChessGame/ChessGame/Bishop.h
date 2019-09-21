#pragma once
#include "ChessPieces.h"
class Bishop :
	public ChessPieces
{
public:
	Bishop(unsigned int team);

	void Move(const int& moveX, const int& moveY) override;

protected:
	Vector2<int>* CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const override;
	unsigned int CalcuratePathCount(ChessPieces* (*board)[8]) const override;
};

