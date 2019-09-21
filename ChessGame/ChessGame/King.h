#pragma once
#include "ChessPieces.h"

class King :
	public ChessPieces
{
public:
	King(unsigned int team);

	void Move(const int& moveX, const int& moveY) override;

protected:
	Vector2<int>* CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const override;
	unsigned int CalcuratePathCount(ChessPieces* (*board)[8]) const override;
};

