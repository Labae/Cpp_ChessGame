#include "King.h"

King::King(unsigned int team) : ChessPieces(ChessPieces::King, team, false)
{
}

void King::Move(const int& moveX, const int& moveY)
{
	m_Position.SetXY(moveX, moveY);
}

Vector2<int>* King::CalcuratePaths(ChessPieces* (*board)[8], unsigned int pathCount) const
{
	Vector2<int>* result = new Vector2<int>[pathCount];
	unsigned int count = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;

	for (int x = currentPosX - 1; x < currentPosX + 2; x++)
	{
		for (int y = currentPosY - 1; y < currentPosY + 2; y++)
		{
			// 맵 밖 제외.
			if (x >= 8 || y >= 8)
			{
				continue;
			}
			if (x < 0 || y < 0)
			{
				continue;
			}

			// 자기자신 제외.
			if (currentPosX == x && currentPosY == y)
			{
				continue;
			}

			piece = board[x][y];
			if (piece == nullptr)
			{
				result[count++] = Vector2<int>(x, y);
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result[count++] = Vector2<int>(x, y);
				}
			}
		}
	}

	return result;
}

unsigned int King::CalcuratePathCount(ChessPieces* (*board)[8]) const
{
	unsigned int result = 0;
	int currentPosX = m_Position.GetX();
	int currentPosY = m_Position.GetY();
	ChessPieces* piece = 0;

	for (int x = currentPosX - 1; x < currentPosX + 2; x++)
	{
		for (int y = currentPosY - 1; y < currentPosY + 2; y++)
		{
			// 맵 밖 제외.
			if (x >= 8 || y >= 8)
			{
				continue;
			}
			if (x < 0 || y < 0)
			{
				continue;
			}

			// 자기자신 제외.
			if (currentPosX == x && currentPosY == y)
			{
				continue;
			}

			piece = board[x][y];
			if (piece == nullptr)
			{
				result++;
			}
			else
			{
				if (piece->GetTeam() != GetTeam())
				{
					result++;
				}
			}
		}
	}

	return result;
}
